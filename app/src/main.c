#include <zephyr/kernel.h>

void main(void)
{
    volatile int alive = 0;

    while (1) {
        alive++;
        k_sleep(K_SECONDS(1));
    }
}
