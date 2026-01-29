#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include "app_api.h"

void system_service_init(void)
{
    printk("[system] init\n");
}
