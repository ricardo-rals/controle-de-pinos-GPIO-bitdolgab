# Projeto: Controle de Periféricos no Raspberry Pi Pico

## Descrição
Este projeto implementa um sistema de controle de periféricos utilizando a placa Raspberry Pi Pico W. Ele utiliza comunicação UART para receber comandos e controlar LEDs RGB e um buzzer, além de permitir entrar no modo bootloader.

## Funcionalidades
- **Controle de LEDs**: Acender e apagar LEDs vermelho, azul e verde individualmente, ou acender todos simultaneamente (luz branca).
- **Controle do Buzzer**: Emitir som em uma frequência específica por um tempo determinado.
- **Modo Bootloader**: Reiniciar a placa e colocá-la em modo bootloader via comando UART.
- **Menu Interativo**: Exibe um menu de controle via comunicação serial.

## Estrutura do Código
O código está organizado em funções principais para inicialização e controle dos periféricos:
- `pwm_init_buzzer(uint pin)`: Inicializa o PWM para controle do buzzer.
- `beep(uint note, uint duration)`: Gera um som no buzzer em uma frequência e duração específicas.
- `inicializador_perifericos()`: Inicializa os pinos GPIO para os LEDs.
- `ligar_led(uint gpio)`: Controla qual LED será aceso.
- `exibir_menu()`: Exibe o menu de controle via UART.

## Estrutura dos arquivos
```
project/
│
├── includes/
│   ├── buzzer.h
│   ├── leds.h
│   ├── menu.h
│   └── uart.h
│
├── src/
│   ├── buzzer.c
│   ├── leds.c
│   ├── menu.c
│   └── uart.c
├── controle-de-pinos-bitdoglab.c
├── CMakeLists.txt
└── README.md
```

## Requisitos de Hardware
- Raspberry Pi Pico.
- LEDs conectados aos pinos GPIO 11, 12 e 13.
- Buzzer conectado ao pino GPIO 21.
- Comunicação UART configurada nos pinos GPIO 4 (TX) e GPIO 5 (RX).

## Comandos UART
| Comando | Ação                              |
|---------|-----------------------------------|
| R       | Acender o LED vermelho           |
| B       | Acender o LED azul               |
| G       | Acender o LED verde              |
| W       | Acender todos os LEDs (luz branca)|
| D       | Desligar todos os LEDs           |
| Z       | Ativar o buzzer por 2 segundos   |
| X       | Reiniciar no modo bootloader     |

# Plano de Trabalho: Controle de Pinos GPIO da placa BitDogLab
### Divisão de Tarefas entre 9 Pessoas

## **Tarefas e Responsabilidades**

## Atividade 1: Conexão dos Componentes
**Responsável:** Ricardo

- Conectar o LED RGB aos GPIOs 11, 12 e 13.
- Conectar o buzzer ao GPIO 21.
- Verificar as conexões e garantir que estão corretas.

## Atividade 2: Implementação do Controle do LED Verde
**Responsável:** Adson e Dorivaldo

- Desenvolver a rotina para ligar o LED verde (GPIO 11) e desligar os demais LEDs.

## Atividade 3: Implementação do Controle do LED Azul
**Responsável:** Adson

- Desenvolver a rotina para ligar o LED azul (GPIO 12) e desligar os demais LEDs.

## Atividade 4: Implementação do Controle do LED Vermelho
**Responsável:** Guilherme Miller

- Desenvolver a rotina para ligar o LED vermelho (GPIO 13) e desligar os demais LEDs.

## Atividade 5: Implementação do Controle dos Três LEDs
**Responsável:** Isabella

- Desenvolver a rotina para ligar os três LEDs (luz branca) e desligar todos os LEDs.

## Atividade 6: Implementação do Controle do Buzzer
**Responsável:** Ricardo

- Desenvolver a rotina para acionar o buzzer por 2 segundos, emitindo sinal sonoro.

## Atividade 7: Implementação do Modo de Gravação
**Responsável:** Dorivaldo

- Desenvolver a rotina para sair do modo de execução e habilitar o modo de gravação via software (reboot) – rotina opcional.

## Atividade 8: Testes e Validação
**Responsável:** Pessoa 8

- Realizar testes de todas as rotinas implementadas.
- Validar a comunicação entre o computador e o microcontrolador utilizando o PuTTY.
- Documentar os resultados dos testes e fazer ajustes, se necessário.

## Atividade 9: Documentação
**Responsável:** Jabson

- Documentar o fluxo do código, destacando as responsabilidades de cada função.
- Elaborar o relatório final com a explicação do processo de desenvolvimento, problemas encontrados e soluções implementadas.
- Organizar o código-fonte de maneira limpa e comentada, para que outras pessoas possam entender facilmente.

## **Divisão das tarefas:**

| **Tarefa**                                     | **Responsável**
|------------------------------------------------|------------|
| Conexão dos Componentes                        |Ricardo           |
| Implantação do Controle do LED 1               |Adson  e Dorivaldo| 
| Implantação do Controle do LED 2               |Adson             | 
| Implantação do Controle do LED 3               |Guilherme Miller  |
| Implantação do Controle dos Três LEDs          |Isabella          |
| Implementação do Controle do Buzzer            |Ricardo           | 
| Implementação do Modo de Gravação              |Dorivaldo         | 
| Testes e Validação                             |Ricardo           | 
| Documentação                                   |Jabson            | 

## **Link com a produção do vídeo:**
https://www.youtube.com/shorts/YFatIZdGuIk

![BitDogLab](https://github.com/user-attachments/assets/a1e601b0-1de5-49ca-b32f-50024ebe994d)
