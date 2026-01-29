#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include "app_api.h"

#define SENSOR_THREAD_STACK_SIZE 1024
#define COMM_THREAD_STACK_SIZE   1024

#define SENSOR_THREAD_PRIORITY 5
#define COMM_THREAD_PRIORITY   7

K_THREAD_STACK_DEFINE(sensor_stack, SENSOR_THREAD_STACK_SIZE);
K_THREAD_STACK_DEFINE(comm_stack, COMM_THREAD_STACK_SIZE);

static struct k_thread sensor_thread_data;
static struct k_thread comm_thread_data;

static void sensor_thread(void *a, void *b, void *c)
{
    while (1) {
        printk("[sensor]:uptime: %llu ms\n", k_uptime_get());
        printk("[sensor] heartbeat\n");
        k_sleep(K_SECONDS(2));
    }
}

static void comm_thread(void *a, void *b, void *c)
{
    while (1) {
        printk("[comm]:uptime: %llu ms\n", k_uptime_get());
        printk("[comm] alive\n");
        k_sleep(K_SECONDS(5));
    }
}

void threads_start(void)
{
    k_thread_create(&sensor_thread_data,
                    sensor_stack,
                    SENSOR_THREAD_STACK_SIZE,
                    sensor_thread,
                    NULL, NULL, NULL,
                    SENSOR_THREAD_PRIORITY,
                    0,
                    K_NO_WAIT);

    k_thread_create(&comm_thread_data,
                    comm_stack,
                    COMM_THREAD_STACK_SIZE,
                    comm_thread,
                    NULL, NULL, NULL,
                    COMM_THREAD_PRIORITY,
                    0,
                    K_NO_WAIT);
}
