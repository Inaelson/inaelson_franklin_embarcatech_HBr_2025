#include "hal_temperature.h"
#include "temperature_read.h"
#include <stdio.h>


void ler_temperatura() {
    // Inicializa o ADC
    uint16_t adc_val = init_temp_sensor(); // Chama a função para inicializar o ADC

    float temperature_celsius = adc_to_celsius(adc_val); // Chama a função para converter o valor do ADC em Celsius
    printf("Temperature: %.2f °C\n", temperature_celsius);
}