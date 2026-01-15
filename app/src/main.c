#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

void main(void)
{
    while (1) {
        printk("STM32 Zephyr test app running\n");
        k_sleep(K_SECONDS(1));
    }
}
