#include "../includes/menu.h"
#include <stdio.h>

void exibir_menu() {
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
