#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

void main(void)
{
    printk("Zephyr is alive\n");

    while (1) {
        printk("tick\n");
        k_sleep(K_SECONDS(1));
    }
}
