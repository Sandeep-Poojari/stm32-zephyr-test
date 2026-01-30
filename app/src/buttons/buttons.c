#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include "app_api.h"

#define BUTTON_NODE DT_NODELABEL(user_button)

static const struct gpio_dt_spec button =
    GPIO_DT_SPEC_GET(BUTTON_NODE, gpios);

static struct gpio_callback button_cb;


static void button_pressed(const struct device *dev,
                           struct gpio_callback *cb,
                           uint32_t pins)
{
    printk("[button] pressed, uptime=%llu ms\n", k_uptime_get());
}

int button_init(void)
{
    if (!device_is_ready(button.port)) {
        printk("[button] GPIO device not ready\n");
        return -ENODEV;
    }

    gpio_pin_configure_dt(&button, GPIO_INPUT);

    gpio_init_callback(&button_cb,
                       button_pressed,
                       BIT(button.pin));

    gpio_add_callback(button.port, &button_cb);

    gpio_pin_interrupt_configure_dt(&button,
        GPIO_INT_EDGE_TO_ACTIVE);

    printk("[button] interrupt enabled on PC13\n");
    return 0;
}
