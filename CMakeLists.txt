# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(controle-de-pinos-bitdoglab C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(controle-de-pinos-bitdoglab controle-de-pinos-bitdoglab.c src/buzzer.c src/leds.c src/menu.c src/uart.c)

pico_set_program_name(controle-de-pinos-bitdoglab "controle-de-pinos-bitdoglab")
pico_set_program_version(controle-de-pinos-bitdoglab "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(controle-de-pinos-bitdoglab 1)
pico_enable_stdio_usb(controle-de-pinos-bitdoglab 1)

# Add the standard library to the build
target_link_libraries(controle-de-pinos-bitdoglab
        hardware_pwm
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(controle-de-pinos-bitdoglab PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries
target_link_libraries(controle-de-pinos-bitdoglab 
        
        )

pico_add_extra_outputs(controle-de-pinos-bitdoglab)

