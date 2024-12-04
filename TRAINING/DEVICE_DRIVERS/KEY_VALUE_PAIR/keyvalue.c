#include <linux/module.h>//modules for module_init and module_exit are present in it
#include <linux/kernel.h>//for printk to print the data
#include <linux/fs.h>//file operations are present in it. and direct structures are defined in it and you invoke them in another structure using another structre like .open , .read etc
#include <linux/uaccess.h> // For copy_to_user and copy_from_user 

#define DEVICE_NAME "keyvalue"
#define BUFFER_SIZE 1024
#define MAX_LEN 50
#define MAX_SIZE 3
struct kv_pair
{
	int index;
	int key;
	char value[50];
};
static int major_number;//majornumber initialization
//static char device_buffer[BUFFER_SIZE];
static int open_count = 0;
static struct kv_pair kv[MAX_SIZE];
static int wcount=0;
static int rcount=0;
static int k=0;
static char buff[100];
static char buff1[100];
//static int index;
static int device_open(struct inode *inode, struct file *file);
static int device_close(struct inode *inode, struct file *file);
static ssize_t device_read(struct file *file, char __user *user_buffer, size_t size, loff_t *offset);
static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t size, loff_t *offset);

static struct file_operations fops = {
    .open = device_open,
    .release = device_close,
    .read = device_read,
    .write = device_write,
};

static int device_open(struct inode *inode, struct file *file) {
    open_count++;
    printk(KERN_INFO "simple_device: Device opened %d time(s)\n", open_count);
    return 0;
}

// Close device
static int device_close(struct inode *inode, struct file *file) {
    printk(KERN_INFO "simple_device: Device closed\n");
    return 0;
}

// Called when data is read from the device
static ssize_t device_read(struct file *file, char __user *user_buffer, size_t size, loff_t *offset) {
	char output[100];
	if(MAX_SIZE==rcount)
	{
		if (copy_to_user(user_buffer,buff, strlen(buff)+1)) {
			return -EFAULT;
		}
		rcount++;
	}
	else if(MAX_SIZE>rcount)
	{
		snprintf(output, sizeof(output), "ID:%d,KEY:%d,VALUE:%s", kv[rcount].index,kv[rcount].key, kv[rcount].value);
		printk(KERN_INFO,"%s",output);
		if (copy_to_user(user_buffer,output, strlen(output)+1)) {
			return -EFAULT;
		}
		printk(KERN_INFO "%s",user_buffer);
		rcount++;
	}
	else if(MAX_SIZE<rcount)
	{
	if (copy_to_user(user_buffer,buff1, strlen(buff1)+1)) {
			return -EFAULT;
	}
    printk(KERN_INFO "kv_Device: values are sent to the user\n");
//	printk(KERN_INFO "Sent data to user: index=%d, key=%d, value=%s\n", kv[rcount].index, kv[rcount].key, kv[rcount].value);
	
	return size;
}



static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t size, loff_t *offset) {
	//	char buff[100];int index;char buff1[100];
	int index;
	/*	if (size != sizeof(struct kv_pair)) {
			printk(KERN_ERR "Invalid data size: expected %lu, got %zu\n", sizeof(struct kv_pair), size);
			return -EINVAL; // Invalid argument
		}*/
		if(MAX_SIZE> wcount)
		{
			if (copy_from_user(&kv[wcount], user_buffer, sizeof(struct kv_pair))) {
			return -EFAULT; // Failed to copy data from user space
			}
			wcount++;
		
		}
		else if(wcount==MAX_SIZE)
		{
		printk(KERN_ERR "Write limit exceeded\n");
		wcount++;
		snprintf(buff,sizeof(buff),"write limit excedded");
		}
		else if(MAX_SIZE <wcount)
		{
		if (copy_from_user(&index, user_buffer, sizeof(int))) {
			printk(KERN_INFO "%d",index);
			for(k=0;k<MAX_SIZE;k++)
			{
				if((kv[k].id==index))
				{
					snprintf(buff1,sizeof(buff1),"Received index=%d, key=%d, value=%s\n", kv[wcount].index, kv[wcount].key, kv[wcount].value);
				return size;
				}
			}
			printk(KERN_ERR "index not found\n");
			snprintf(buff1,sizeof(buff1),"index not found\n");

		}}
return size;
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

// Device read function
//
/*
static ssize_t device_read(struct file *file, char __user *user_buffer, size_t size, loff_t *offset) {
    char output[100];

    if (MAX_SIZE == rcount) {
        if (copy_to_user(user_buffer, buff, strlen(buff) + 1)) {
            return -EFAULT;
        }
        rcount++;
    } else if (rcount < MAX_SIZE) {
        snprintf(output, sizeof(output), "ID:%d,KEY:%d,VALUE:%s", kv[rcount].index, kv[rcount].key, kv[rcount].value);
        if (copy_to_user(user_buffer, output, strlen(output) + 1)) {
            return -EFAULT;
        }
        printk(KERN_INFO "%s", user_buffer);
        rcount++;
    } else {
        if (copy_to_user(user_buffer, buff1, strlen(buff1) + 1)) {
            return -EFAULT;
        }
    }
    printk(KERN_INFO "kv_Device: values are sent to the user\n");
    printk(KERN_INFO "Sent data to user: index=%d, key=%d, value=%s\n", kv[rcount].index, kv[rcount].key, kv[rcount].value);

    return size;
}

// Device write function
static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t size, loff_t *offset) {
    int index;

    if (size != sizeof(struct kv_pair)) {
        printk(KERN_ERR "Invalid data size: expected %lu, got %zu\n", sizeof(struct kv_pair), size);
        return -EINVAL;
    }
    if (MAX_SIZE > wcount) {
        if (copy_from_user(&kv[wcount], user_buffer, sizeof(struct kv_pair))) {
            return -EFAULT;
        }
        wcount++;
    } else {
        printk(KERN_ERR "Write limit exceeded\n");
        snprintf(buff, sizeof(buff), "Write limit exceeded");
    }

    if (copy_from_user(&index, user_buffer, sizeof(int))) {
        for (int k = 0; k < MAX_SIZE; k++) {
            if (kv[k].index == index) {
                snprintf(buff1, sizeof(buff1), "Received index=%d, key=%d, value=%s\n",
                         kv[k].index, kv[k].key, kv[k].value);
                return size;
            }
        }
        printk(KERN_ERR "Index not found\n");
        snprintf(buff1, sizeof(buff1), "Index not found\n");
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
MODULE_DESCRIPTION("A Simple Linux Device Driver");*/
