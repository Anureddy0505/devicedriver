#include <linux/module.h>//modules for module_init and module_exit are present in it
#include <linux/kernel.h>//for printk to print the data
#include <linux/fs.h>//file operations are present in it. and direct structures are defined in it and you invoke them in another structure using another structre like .open , .read etc
#include <linux/uaccess.h> // For copy_to_user and copy_from_user 

#define DEVICE_NAME "calculator_device"
#define BUFFER_SIZE 1024

static int major_number;//majornumber initialization
static char device_buffer[BUFFER_SIZE];
static int open_count = 0;

// Function prototypes for device operations
static int device_open(struct inode *inode, struct file *file);//to open 
static int device_close(struct inode *inode, struct file *file);
static ssize_t device_read(struct file *file, char __user *user_buffer, size_t size, loff_t *offset);
static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t size, loff_t *offset);

// File operations structure
static struct file_operations fops = {
    .open = device_open,
    .release = device_close,
    .read = device_read,
    .write = device_write,
};

// Called when the device is opened
static int device_open(struct inode *inode, struct file *file) {
    open_count++;
    printk(KERN_INFO "simple_device: Device opened %d time(s)\n", open_count);
    return 0;
}

// Called when the device is closed
static int device_close(struct inode *inode, struct file *file) {
    printk(KERN_INFO "simple_device: Device closed\n");
    return 0;
}

// Called when data is read from the device
static ssize_t device_read(struct file *file, char __user *user_buffer, size_t size, loff_t *offset) {
    size_t len = strlen(device_buffer);

    if (*offset >= len) // Check if all data has been read
        return 0;

    if (size > len - *offset) // Adjust size to avoid reading beyond buffer
        size = len - *offset;

    if (copy_to_user(user_buffer, device_buffer + *offset, size)) {
        return -EFAULT;
    }

    *offset += size;
    printk(KERN_INFO "cal_Device: value is sent to the user\n");
    return size;
}

// Called when data is written to the device
static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t size, loff_t *offset) {
	int a, b,res = 0;
    char c;

    if (size > BUFFER_SIZE - 1)  // Limit size to buffer capacity
        size = BUFFER_SIZE - 1;

    if (copy_from_user(device_buffer, user_buffer, size)) {
        return -EFAULT;
    }

    if (sscanf(device_buffer, "%d %d %c", &a, &b, &c) != 3) {
        return -EINVAL;  // Invalid input format
    }
/*
	for(i=0;i<size;i++)
	{
		if(device_buffer[i]==' ')
		{
			count++;
			if(count==1)
			{
	           a = a * 10 + (device_buffer[i] - '0');
			   printk(KERN_INFO "a:%d\n",a);
			}
			if(count==2)
			{
				b=b*10+(device_buffer[i]-'0');
				   printk(KERN_INFO "b:%d\n",b);
			}
			if(count==3)
			{
				c=device_buffer[i];
			}
		}
	}
*/	

	if(c=='+')
	{
	 res=a+b;
	}
	else if(c=='-')
	{
		res=a-b;
	}
	else if(c=='*')
	{
		res=a*b;
	}
	else if(c=='/')
	{
		res=a/b;
	}
	else if(c=='%')
	{
		res=a%b;
	}
	snprintf(device_buffer, sizeof(device_buffer), "Result: %d\n", res);
    
    // Ensure the string is null-terminated
    device_buffer[BUFFER_SIZE - 1] = '\0';  // Null-terminate the string

    printk(KERN_INFO "cal_device: Result: %d\n", res);
    return size;  // Return the number of bytes written}
	}
// Module initialization
static int __init simple_driver_init(void) {//this function is called while
    major_number = register_chrdev(0, DEVICE_NAME, &fops);//creates a major number for this device.
	if (major_number < 0) {
        printk(KERN_ALERT "simple_device: Failed to register device\n");
        return major_number;
    }
    printk(KERN_INFO "simple_device: Registered with major number %d\n", major_number);
    return 0;
}

// Module cleanup
static void __exit simple_driver_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "simple_device: Unregistered device\n");
}

module_init(simple_driver_init);
module_exit(simple_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A Simple Linux Device Driver");
