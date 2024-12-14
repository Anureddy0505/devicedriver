#include <linux/module.h> // Modules for module_init and module_exit
#include <linux/kernel.h> // For printk
#include <linux/fs.h>     // File operations
#include <linux/uaccess.h> // For copy_to_user and copy_from_user

#define DEVICE_NAME "keyvalcir"
#define MAX_SIZE 3
#define MAX_LEN 50

struct kv_pair {
    int index;
    int key;
    char value[MAX_LEN];
};

static int major_number; 
static int open_count = 0; 
static struct kv_pair kv[MAX_SIZE]; // Array of key-value pairs
static int head = 0; // Head  circular buffer
static int tail = 0; // Tail  circular buffer
static int count = 0; 
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

    if (count == 0) {
        snprintf(buff1, sizeof(buff1), "Buffer empty\n");
        if (copy_to_user(user_buffer, buff1, strlen(buff1) + 1)) {
            return -EFAULT;
        }
        return 0;
    }

    snprintf(output, sizeof(output), "ID:%d,KEY:%d,VALUE:%s", kv[tail].index, kv[tail].key, kv[tail].value);
    if (copy_to_user(user_buffer, output, strlen(output) + 1)) {
        return -EFAULT;
    }

    tail = (tail + 1) % MAX_SIZE;
    count--;

    return strlen(output);
}

// Device write function
static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t size, loff_t *offset) {
    int index;
    int i;

    // Check if buffer is full
    if (count < MAX_SIZE) {
        // Copy the user data to the circular buffer
        if (copy_from_user(&kv[head], user_buffer, sizeof(struct kv_pair))) {
            return -EFAULT;
        }
        head = (head + 1) % MAX_SIZE;
        count++;
    } else {
        // Buffer is full, overwrite old data and return a message to indicate the limit is exceeded
        snprintf(buff, sizeof(buff), "Write limit exceeded\n");
        if (copy_to_user(user_buffer, buff, strlen(buff) + 1)) {
            return -EFAULT;
        }
        
        // Overwrite the oldest entry
        if (copy_from_user(&kv[head], user_buffer, sizeof(struct kv_pair))) {
            return -EFAULT;
        }
        head = (head + 1) % MAX_SIZE;
        tail = (tail + 1) % MAX_SIZE; // Move tail forward to overwrite the oldest data
        count = MAX_SIZE;  // Ensure count remains at MAX_SIZE
    }

    // Handle reading by index if size is sizeof(int)
    if (size == sizeof(int)) {
        if (copy_from_user(&index, user_buffer, sizeof(int))) {
            return -EFAULT;
        }

        for (i = 0; i < MAX_SIZE; i++) {
            int pos = (tail + i) % MAX_SIZE;
            if (kv[pos].index == index) {
                snprintf(buff1, sizeof(buff1), "Received index=%d, key=%d, value=%s\n", kv[pos].index, kv[pos].key, kv[pos].value);
                pr_info("%s", buff1);
                return size;
            }
        }

        snprintf(buff1, sizeof(buff1), "Index not found\n");
        pr_info("%s", buff1);
    }

    return size;
}

// Device write function


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
MODULE_DESCRIPTION("A Simple Linux Device Driver with Circular Buffer");
