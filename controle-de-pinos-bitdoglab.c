#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#define LED_VERDE 11
#define LED_AZUL 12
#define LED_VERMELHO 13
#define BUZZER 21
#define FREQUENCIA_BUZZER 2000

// Definição de uma função para inicializar o PWM no pino do buzzer
void pwm_init_buzzer(uint pin) {
    // Configurar o pino como saída de PWM
    gpio_set_function(pin, GPIO_FUNC_PWM);

    // Obter o slice do PWM associado ao pino
    uint slice_num = pwm_gpio_to_slice_num(pin);

    // Configurar o PWM com frequência desejada
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (FREQUENCIA_BUZZER * 4096)); // Divisor de clock
    pwm_init(slice_num, &config, true);

    // Iniciar o PWM no nível baixo
    pwm_set_gpio_level(pin, 0);
}

// Função para ligar o buzzer de forma similar aos LEDs
void ligar_buzzer() {
    printf("Ligando Buzzer\n");

    pwm_set_gpio_level(BUZZER, 1024);
    sleep_ms(2000);  // Aguardar 500ms (tempo do beep)
    pwm_set_gpio_level(BUZZER, 0);     // Desativar o buzzer
    sleep_ms(500);  // Pausa entre os beeps
}

int main()
{
    stdio_init_all();

    pwm_init_buzzer(BUZZER);

    while (true) {
        ligar_buzzer();
    }

    return 0;
}
