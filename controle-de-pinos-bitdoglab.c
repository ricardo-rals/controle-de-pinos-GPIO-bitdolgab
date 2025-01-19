#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "pico/bootrom.h" // Biblioteca para usar o comando reboot (bootloader via serial)

// UART defines
// By default the stdout UART is `uart0`, so we will use the second one
#define UART_ID uart1
#define BAUD_RATE 115200

// Use pins 4 and 5 for UART1
// Pins can be changed, see the GPIO function select table in the datasheet for information on GPIO assignments
#define UART_TX_PIN 4
#define UART_RX_PIN 5

#define GPIO_RED_LED 13
#define GPIO_BLUE_LED 12
#define GPIO_GREEN_LED 11
#define GPIO_BUZZER_B 10

void inicializador_perifericos(){
    gpio_init(GPIO_RED_LED);
    gpio_set_dir(GPIO_RED_LED, GPIO_OUT);
    gpio_put(GPIO_RED_LED,0);
    
    gpio_init(GPIO_BLUE_LED);
    gpio_set_dir(GPIO_BLUE_LED, GPIO_OUT);
    gpio_put(GPIO_BLUE_LED,0);

    gpio_init(GPIO_GREEN_LED);
    gpio_set_dir(GPIO_GREEN_LED, GPIO_OUT);
    gpio_put(GPIO_GREEN_LED,0);
}

void ligar_led(uint gpio) {
    gpio_put(GPIO_RED_LED, gpio == GPIO_RED_LED);
    gpio_put(GPIO_BLUE_LED, gpio == GPIO_BLUE_LED);
    gpio_put(GPIO_GREEN_LED, gpio == GPIO_GREEN_LED);
}

void exibir_menu(){
   printf("\n--------------------------------------------\n");
   printf("MENU DE CONTROLE:\n\n");
   printf("R - Acender o LED vermelho\n");
   printf("B - Acender o LED azul\n");
   printf("G - Acender o LED verde\n");
   printf("W - Acender todos os LEDs (luz branca)\n");
   printf("D - Desligar todos os LEDs\n");
   printf("Z - Ativar o buzzer por 2 segundos\n");
   printf("X - Entrar em modo bootloader\n");
   printf("--------------------------------------------\n\n");
   printf("Digite um novo comando via UART:\n");

}

int main()
{
    // Set up our UART
    uart_init(UART_ID, BAUD_RATE);
    // Set the TX and RX pins by using the function select on the GPIO
    // Set datasheet for more information on function select
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    
    // Use some the various UART functions to send out data
    // In a default system, printf will also output via the default UART
    
    // Send out a string, with CR/LF conversions
    uart_puts(UART_ID, " Hello, UART!\n");
    printf("Iniciando o sistema.\n");
     
     //inicio da main normalgit status
    stdio_init_all();
    inicializador_perifericos();
    
    while (true) {
        exibir_menu();
        char comando = getchar(); // Lê o comando do teclado via uart
        
          switch (comando){
            case 'r':
            case 'R': //acende o led vermelho
               ligar_led(GPIO_RED_LED);
               printf("Led vermelho acesso.\n");
               break;
            case 'b':
            case 'B': //acende o led azul
               ligar_led(GPIO_BLUE_LED);
               printf("Led azul acesso.\n");
               break;
            case 'g':
            case 'G': //acedde led verde
               ligar_led(GPIO_GREEN_LED);
               printf("Led verde acesso.\n");
               break;
            case 'w':
            case 'W': // acende a luz branca(white)
               gpio_put(GPIO_RED_LED,1); 
               gpio_put(GPIO_BLUE_LED,1); 
               gpio_put(GPIO_GREEN_LED,1);
               printf("Todos os leds acessos, luz branca.\n");
               break;
            case 'd':
            case 'D': // acende a luz branca(white)
               gpio_put(GPIO_RED_LED, 0); 
               gpio_put(GPIO_BLUE_LED, 0); 
               gpio_put(GPIO_GREEN_LED, 0);
               printf("Todos os LEDs desligados.\n");
               break;
            case 'z':
            case 'Z': // ativa o buzer por 2s
               gpio_put(GPIO_BUZZER_B,1);
               sleep_ms(2000);
               gpio_put(GPIO_BUZZER_B,0);
               printf("Buzzer ligado por 2 segundos.\n");
               break;
            case 'x':
            case 'X': // reebot, sistema reiniciado e placa em modo bootloader
              printf("Reiniciando o sistema...\n");
              sleep_ms(300); // atraso antes de reiniciar para garatir a impressao
              reset_usb_boot(0, 0); //entra em modo bootloader
              break;
            default:
              printf("Comando invalido: %c\n", comando);
              break;     
          }
    }
    return 0;
}