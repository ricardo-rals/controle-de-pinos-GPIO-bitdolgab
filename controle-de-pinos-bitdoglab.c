#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "includes/uart.h"
#include "includes/buzzer.h"
#include "includes/leds.h"
#include "includes/menu.h"

int main() {
    stdio_init_all();
    uart_init_custom();

    inicializador_perifericos();
    pwm_init_buzzer(21);

    while (true) {
        exibir_menu();
        char comando = getchar();

        switch (comando) {
            case 'r':
            case 'R':
                ligar_led(GPIO_RED_LED);
                printf("Led vermelho aceso.\n");
                break;
            case 'b':
            case 'B':
                ligar_led(GPIO_BLUE_LED);
                printf("Led azul aceso.\n");
                break;
            case 'g':
            case 'G':
                ligar_led(GPIO_GREEN_LED);
                printf("Led verde aceso.\n");
                break;
            case 'w':
            case 'W':
                gpio_put(GPIO_RED_LED, 1);
                gpio_put(GPIO_BLUE_LED, 1);
                gpio_put(GPIO_GREEN_LED, 1);
                printf("Todos os LEDs acesos.\n");
                break;
            case 'd':
            case 'D':
                gpio_put(GPIO_RED_LED, 0);
                gpio_put(GPIO_BLUE_LED, 0);
                gpio_put(GPIO_GREEN_LED, 0);
                printf("Todos os LEDs desligados.\n");
                break;
            case 'z':
            case 'Z':
                beep(2000, 2000);
                printf("Buzzer ativado por 2 segundos.\n");
                break;
            case 'x':
            case 'X':
                printf("Reiniciando o sistema...\n");
                sleep_ms(300);
                reset_usb_boot(0, 0);
                break;
            default:
                printf("Comando inválido: %c\n", comando);
                break;
        }
    }
    return 0;
}
