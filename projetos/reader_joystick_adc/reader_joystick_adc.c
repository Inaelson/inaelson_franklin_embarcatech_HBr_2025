#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

#define JOYSTICK_Y_PIN 26 // Pino do eixo Y do Joystick
#define JOYSTICK_X_PIN 27 // Pino do eixo X do Joystick

volatile uint16_t y_raw, x_raw;

struct repeating_timer print_adc_reader;

bool print_adc_reader_callback(struct repeating_timer *t);


int main()
{
    stdio_init_all();

    adc_init(); 
    adc_gpio_init(JOYSTICK_Y_PIN); //Eixo Y no canal ADC 0 
    adc_gpio_init(JOYSTICK_X_PIN); //Eixo X no canal ADC 1



    //Timer para impressão dos valores no terminal á cada 500ms
    add_repeating_timer_ms(500, print_adc_reader_callback, NULL, &print_adc_reader);

    //Realiza a leitura dos dados a cada 100ms
    while (true) {
        adc_select_input(0); // Seleciona o pino do eixo Y
        y_raw = adc_read(); 
        adc_select_input(1); // Seleciona o pino do eixo X
        x_raw = adc_read(); 
        sleep_ms(100);
    }
}

bool print_adc_reader_callback(struct repeating_timer *t){
    printf("X = %d | Y = %d\n", x_raw, y_raw);
    return true;
}