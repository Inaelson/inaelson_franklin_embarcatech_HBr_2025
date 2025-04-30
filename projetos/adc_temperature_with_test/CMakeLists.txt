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
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(adc_temperature_with_test C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(adc_temperature_with_test 
            app/adc_temperature_with_test.c 
            hal/hal_temperature.c
            drivers/temperature_read.c)

pico_set_program_name(adc_temperature_with_test "adc_temperature_with_test")
pico_set_program_version(adc_temperature_with_test "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(adc_temperature_with_test 0)
pico_enable_stdio_usb(adc_temperature_with_test 1)

# Add the standard library to the build
target_link_libraries(adc_temperature_with_test
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(adc_temperature_with_test PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        include)

# Add any user requested libraries
target_link_libraries(adc_temperature_with_test 
        
        hardware_adc
        )

pico_add_extra_outputs(adc_temperature_with_test)


#
# Add the following lines to enable the test framework
#

# Caminho da Unity
set(UNITY_DIR ${CMAKE_SOURCE_DIR}/test/unity)

# Adiciona um executável para os testes unitários
add_executable(tests 
    test/test_temperature_read.c
    drivers/temperature_read.c
    ${UNITY_DIR}/src/unity.c
)

pico_enable_stdio_usb(tests 1)
pico_enable_stdio_uart(tests 0)


# Inclui headers do projeto e da Unity
target_include_directories(tests PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${UNITY_DIR}/src
)

# Liga as bibliotecas necessárias
target_link_libraries(tests
    pico_stdlib
    hardware_adc
)

pico_add_extra_outputs(tests)