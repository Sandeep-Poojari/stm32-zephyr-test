#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include "app_api.h"

void main(void)
{
    printk("[app] startup\n");

    system_service_init();
    threads_start();

    while (1) {
        printk("[main]:uptime: %llu ms\n", k_uptime_get());
        k_sleep(K_MSEC(500));
    }
}
