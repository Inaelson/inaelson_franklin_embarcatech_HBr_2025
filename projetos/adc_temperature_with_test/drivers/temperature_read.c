#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "temperature_read.h"

uint16_t init_temp_sensor() {
    static uint16_t adc_val; // Variável para armazenar o valor do ADC
    
    // Inicializa o ADC
    adc_init();
    
    adc_set_temp_sensor_enabled(true); // Habilita o sensor de temperatura
    adc_select_input(4); // Seleciona o canal ADC 4 (sensor de temperatura)
    
    adc_val = adc_read(); // Lê o valor do ADC
    return adc_val;
}

float adc_to_celsius(uint16_t adc_val){

    // Converte o valor do ADC em voltagem assumindo uma referência de 3.3V e um ADC de 12 bits
    float voltage = 3.3f * (adc_val / 4095.0f);
    // float voltage = (3.3f / 4095) * adc_val;

    // Converte a voltagem em temperatura Celsius
    float temperature_celsius = 27 - (voltage - 0.706f) / 0.001721f; // Fórmula de conversão do datasheet

    return temperature_celsius; // Retorna a temperatura em Celsius
}