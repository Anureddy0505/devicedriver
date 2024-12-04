#include <linux/module.h> // Modules for module_init and module_exit
#include <linux/kernel.h> // For printk
#include <linux/fs.h>     // File operations
#include <linux/uaccess.h> // For copy_to_user and copy_from_user

#define DEVICE_NAME "keyvalue"
#define MAX_SIZE 3
#define MAX_LEN 50

struct kv_pair {
    int index;
    int key;
    char value[MAX_LEN];
};

static int major_number; // Major number for device
static int open_count = 0; // Track how many times the device is opened
static struct kv_pair kv[MAX_SIZE]; // Array of key-value pairs
static int wcount = 0;
static int rcount = 0;
static int k=0;
static char buff[100];
static char buff1[100];

// Function prototypes
static int device_open(struct inode *inode, struct file *file);
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

// Device open function
static int device_open(struct inode *inode, struct file *file) {
    open_count++;
    printk(KERN_INFO "simple_device: Device opened %d time(s)\n", open_count);
    return 0;
}

// Device close function
static int device_close(struct inode *inode, struct file *file) {
    printk(KERN_INFO "simple_device: Device closed\n");
    return 0;
}

// Device read function
static ssize_t device_read(struct file *file, char __user *user_buffer, size_t size, loff_t *offset) {
    char output[100];

    if (rcount == MAX_SIZE) {
        if (copy_to_user(user_buffer, buff, strlen(buff) + 1)) {
            return -EFAULT;

        }
		rcount++;
    } else if(rcount<=MAX_SIZE){
        snprintf(output, sizeof(output), "ID:%d,KEY:%d,VALUE:%s", kv[rcount].index, kv[rcount].key, kv[rcount].value);
        if (copy_to_user(user_buffer, output, strlen(output) + 1)) {
            return -EFAULT;
        }
        rcount++;
    }
	else if(rcount>MAX_SIZE){
	if (copy_to_user(user_buffer, buff1, strlen(buff1) + 1)) {
            return -EFAULT;
        }
	}
    return size;
}

// Device write function
static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t size, loff_t *offset) {
    int index;

  /*  if (size != sizeof(struct kv_pair)) {
       y printk(KERN_ERR "Invalid data size: expected %lu, got %zu\n", sizeof(struct kv_pair), size);
        return -EINVAL;
    }*/
    if (wcount < MAX_SIZE)
   	{
        if (copy_from_user(&kv[wcount], user_buffer, sizeof(struct kv_pair))) {
            return -EFAULT;
        }
        wcount++;
    } 
	else if(wcount==MAX_SIZE)
	{
        snprintf(buff, sizeof(buff), "Write limit exceeded");
		wcount++;
		printk(KERN_INFO "buff\n",buff);
    }
	else
	{
    	(copy_from_user(&index, user_buffer, sizeof(int))); 
		printk(KERN_INFO "%d",index);
        for(k=0; k<MAX_SIZE; k++) 
		{
    	   	 if (kv[k].index == index)
		   	{
                snprintf(buff1, sizeof(buff1), "Received index=%d, key=%d, value=%s\n", kv[k].index, kv[k].key, kv[k].value);
				pr_info("%s",buff1);
                return size;
        	}
    	}
        snprintf(buff1, sizeof(buff1), "Index not found\n");
		pr_info("%s",buff1);
    
	}

    return size;
}

// Module initialization function
static int __init simple_driver_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "simple_device: Failed to register device\n");
        return major_number;
    }
    printk(KERN_INFO "simple_device: Registered with major number %d\n", major_number);
    return 0;
}

// Module cleanup function
static void __exit simple_driver_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "simple_device: Unregistered device\n");
}

module_init(simple_driver_init);
module_exit(simple_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A Simple Linux Device Driver");

