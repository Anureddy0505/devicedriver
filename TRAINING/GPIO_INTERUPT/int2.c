#include <linux/gpio.h>
#include <linux/gpio/consumer.h>

struct gpio_desc *my_gpio;

static int __init my_gpio_init(void)
{
    int ret;

    // Request the GPIO (assuming GPIO is already defined elsewhere)
    my_gpio = gpiod_get(NULL, "my-gpio-label", GPIOD_OUT_LOW);
    if (IS_ERR(my_gpio)) {
        pr_err("Failed to get GPIO\n");
        return PTR_ERR(my_gpio);
    }

    // Export the GPIO to user space
    ret = gpiod_export(my_gpio, true);
    if (ret) {
        pr_err("Failed to export GPIO\n");
        gpiod_put(my_gpio);
        return ret;
    }

    pr_info("GPIO exported successfully\n");
    return 0;
}

static void __exit my_gpio_exit(void)
{
    gpiod_unexport(my_gpio);
    gpiod_put(my_gpio);
}

module_init(my_gpio_init);
module_exit(my_gpio_exit);

MODULE_LICENSE("GPL");
