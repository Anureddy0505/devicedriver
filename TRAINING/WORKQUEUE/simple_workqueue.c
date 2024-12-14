#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/workqueue.h>

struct work_struct my_work;

/* Workqueue handler function */
void my_work_function(struct work_struct *work)
{
    pr_info("Workqueue handler executed\n");
}

static int __init my_module_init(void)
{
    /* Initialize work_struct and associate it with the handler function */
    INIT_WORK(&my_work, my_work_function);

    /* Schedule the work */
    schedule_work(&my_work);

    pr_info("Module loaded and work scheduled\n");
    return 0;
}

static void __exit my_module_exit(void)
{
    /* Cancel any pending work before module exit */
    cancel_work_sync(&my_work);

    pr_info("Module unloaded and work canceled\n");
}

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author Name");
MODULE_DESCRIPTION("Workqueue Example");

