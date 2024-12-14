#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/interrupt.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("TechDhaba");
MODULE_DESCRIPTION("A simple Linux kernel module to demonstrate softirqs");

static struct tasklet_struct my_tasklet;

// Declare SoftIRQ
declare_softirq(MY_SOFTIRQ, softirq_handler);

// SoftIRQ handler function
static void softirq_handler(struct softirq_action *action)
{
    printk(KERN_INFO "Softirq: Executing softirq handler\n");
}

// Tasklet function to trigger SoftIRQ
static void tasklet_function(unsigned long data)
{
    printk(KERN_INFO "Tasklet: Scheduling softirq\n");
    raise_softirq(MY_SOFTIRQ);
}

// Module init function
static int __init softirq_example_init(void)
{
    printk(KERN_INFO "Softirq example module loaded\n");

    // Register SoftIRQ
    open_softirq(MY_SOFTIRQ, softirq_handler);

    // Initialize Tasklet
    tasklet_init(&my_tasklet, tasklet_function, 0);

    return 0;
}

// Module exit function
static void __exit softirq_example_exit(void)
{
    // Kill the Tasklet
    tasklet_kill(&my_tasklet);

    printk(KERN_INFO "Softirq example module unloaded\n");
}

module_init(softirq_example_init);
module_exit(softirq_example_exit);

