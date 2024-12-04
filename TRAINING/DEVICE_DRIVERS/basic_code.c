#include<linux/module.h>
#include<linux/kernel.h>
//MODULE INITIALIZATION FUCNTION
static int __init basic_driver_init(void)
{
	printk(KERN_INFO "Basic Driver Loaded\n");
	return 0; //Return 0 indicates successful loading
}
//MODULE CLEANUP FUNCTION
static void __exit basic_driver_exit(void)
{
	printk(KERN_INFO "Basic Driver Unloaded\n");
}
//REGISTER MODULE INITIALIZATION AND CLEANUP FUNCTIONS
module_init(basic_driver_init);
module_exit(basic_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MIRAFRA");
MODULE_DESCRIPTION("A basic linux Device Driver");



