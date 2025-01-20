#ifndef BUZZER_H
#define BUZZER_H

#include "pico/stdlib.h"

void pwm_init_buzzer(uint pin);
void beep(uint note, uint duration);

#endif // BUZZER_H
