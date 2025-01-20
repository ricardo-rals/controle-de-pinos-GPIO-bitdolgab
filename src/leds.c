#include "../includes/leds.h"
#include "pico/stdlib.h"

void inicializador_perifericos() {
    gpio_init(GPIO_RED_LED);
    gpio_set_dir(GPIO_RED_LED, GPIO_OUT);
    gpio_put(GPIO_RED_LED, 0);

    gpio_init(GPIO_BLUE_LED);
    gpio_set_dir(GPIO_BLUE_LED, GPIO_OUT);
    gpio_put(GPIO_BLUE_LED, 0);

    gpio_init(GPIO_GREEN_LED);
    gpio_set_dir(GPIO_GREEN_LED, GPIO_OUT);
    gpio_put(GPIO_GREEN_LED, 0);
}

void ligar_led(uint gpio) {
    gpio_put(GPIO_RED_LED, gpio == GPIO_RED_LED);
    gpio_put(GPIO_BLUE_LED, gpio == GPIO_BLUE_LED);
    gpio_put(GPIO_GREEN_LED, gpio == GPIO_GREEN_LED);
}
