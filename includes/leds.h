#ifndef LEDS_H
#define LEDS_H

#include "pico/stdlib.h"

#define GPIO_RED_LED 13
#define GPIO_BLUE_LED 12
#define GPIO_GREEN_LED 11

void inicializador_perifericos();
void ligar_led(uint gpio);

#endif // LEDS_H
