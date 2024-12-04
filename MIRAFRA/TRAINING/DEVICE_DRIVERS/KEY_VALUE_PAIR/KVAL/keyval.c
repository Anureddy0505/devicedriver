#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/string.h>
#include <linux/init.h>

#define DEVICE_NAME "keyvalue"
#define MAX_SIZE 3

struct kv_pair {
    int index;
    int key;
    char value[50];
};

static int major_number;      // Major number for the device
static int open_count = 0;    // Count of device opens
static struct kv_pair kv[MAX_SIZE]; // Array of key-value pairs
static int wcount = 0;        // Write count
static int rcount = 0;        // Read count
static char buff[100];        // Buffer for write limit exceeded message
static char buff1[100];       // Buffer for index not found message

// Function prototypes for device operations
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
    char output[100];

    if (rcount >= wcount) {
        snprintf(output, sizeof(output), "No data to read\n");
        if (copy_to_user(user_buffer, output, strlen(output) + 1)) {
            return -EFAULT;
        }
        return strlen(output);
    }

    snprintf(output, sizeof(output), "Index: %d, Key: %d, Value: %s\n",
             kv[rcount].index, kv[rcount].key, kv[rcount].value);

    if (copy_to_user(user_buffer, output, strlen(output) + 1)) {
        return -EFAULT;
    }

    printk(KERN_INFO "simple_device: Read data: %s", output);
    rcount++;
    return strlen(output);
}

// Called when data is written to the device
static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t size, loff_t *offset) {
    struct kv_pair user_kv;

    if (wcount >= MAX_SIZE) {
        snprintf(buff, sizeof(buff), "Write limit exceeded\n");
        printk(KERN_ERR "simple_device: %s", buff);
        if (copy_to_user(user_buffer, buff, strlen(buff) + 1)) {
            return -EFAULT;
        }
        return -ENOMEM; // No space left
    }

    if (copy_from_user(&user_kv, user_buffer, sizeof(struct kv_pair))) {
        return -EFAULT; // Error copying from user space
    }

    kv[wcount] = user_kv;
    wcount++;

    printk(KERN_INFO "simple_device: Written - Index: %d, Key: %d, Value: %s\n",
           user_kv.index, user_kv.key, user_kv.value);

    return size;
}

// Module initialization
static int __init simple_driver_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ERR "simple_device: Failed to register device\n");
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

