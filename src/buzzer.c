#include "../includes/buzzer.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "pico/stdlib.h"

#define GPIO_BUZZER_B 21

void pwm_init_buzzer(uint pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_config config = pwm_get_default_config();
    pwm_init(slice_num, &config, true);
    pwm_set_gpio_level(pin, 0);
}

void beep(uint note, uint duration) {
    uint slice_num = pwm_gpio_to_slice_num(GPIO_BUZZER_B);
    uint32_t clock = clock_get_hz(clk_sys);

    uint32_t divisor = clock / (note * 4096);
    pwm_set_clkdiv(slice_num, divisor);

    pwm_set_gpio_level(GPIO_BUZZER_B, 2048);
    sleep_ms(duration);
    pwm_set_gpio_level(GPIO_BUZZER_B, 0);
    sleep_ms(20);
}
