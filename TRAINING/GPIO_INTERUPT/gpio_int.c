#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>
#include <linux/init.h>
#include <linux/errno.h>
#include<linux/delay.h>
#include <linux/gpio/consumer.h>
#define GPIO_PIN 529  // Replace with the GPIO pin number you want to use

static unsigned int irq_number;
static bool led_state = false;
static struct gpio_desc *gpiod;  // GPIO descriptor
//static struct file_operations fops;
// Interrupt handler function
static irqreturn_t gpio_irq_handler(int irq, void *dev_id) {
    pr_info("GPIO Interrupt triggered!\n");
	
	
    // Toggle LED state or perform your desired operation
   led_state = !led_state;
    gpiod_set_value(gpiod, led_state);  // Use the GPIO descriptor to set value

    return IRQ_HANDLED;
}

static int __init gpio_interrupt_init(void) {
    int ret;

    pr_info("GPIO Interrupt Module Loading\n");

    // Get GPIO descriptor for the GPIO pin
    gpiod = gpio_to_desc(GPIO_PIN);
    if (!gpiod) {
        pr_err("Failed to get GPIO descriptor for GPIO: %d\n", GPIO_PIN);
        return -ENODEV;
    }

    // Request GPIO pin as output
    ret = gpiod_direction_output(gpiod, led_state);
    if (ret) {
        pr_err("Failed to set GPIO direction\n");
        return ret;
    }

   /* // Export GPIO for user-space access (use gpiod_export instead of gpio_export)
    ret = gpiod_export(gpiod, false);
    if (ret) {
        pr_err("Failed to export GPIO\n");
        return ret;
    }
*/
    // Request IRQ line
    irq_number = gpiod_to_irq(gpiod);
    if (irq_number < 0) {
        pr_err("Failed to get IRQ number for GPIO: %d\n", GPIO_PIN);
        //gpiod_free(gpiod);  // Release the GPIO descriptor
        return irq_number;
    }

    ret = request_irq(
        irq_number,                // IRQ number
        gpio_irq_handler,          // Interrupt handler function
        IRQF_TRIGGER_RISING,       // Trigger on rising edge
        "gpio_interrupt",         // Interrupt name
        NULL                       // Device ID (optional)
    );

    if (ret) {
        pr_err("Failed to request IRQ: %d\n", irq_number);
        //gpiod_free(gpiod);  // Release the GPIO descriptor
        return ret;
    }

    pr_info("GPIO Interrupt Module Loaded Successfully\n");
    return 0;
}

static void __exit gpio_interrupt_exit(void) {
    pr_info("GPIO Interrupt Module Unloading\n");

    free_irq(irq_number, NULL);    // Free the IRQ
    gpiod_unexport(gpiod);         // Unexport the GPIO
   // gpio_free(gpiod);             // Release the GPIO descriptor

    pr_info("GPIO Interrupt Module Unloaded Successfully\n");
}

module_init(gpio_interrupt_init);
module_exit(gpio_interrupt_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple GPIO interrupt driver for Raspberry Pi");
MODULE_VERSION("1.0");
