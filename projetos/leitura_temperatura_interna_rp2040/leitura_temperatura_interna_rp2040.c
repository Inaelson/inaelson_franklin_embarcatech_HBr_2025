#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"


int main()
{
    stdio_init_all();

    adc_init();
    adc_set_temp_sensor_enabled(true);

    while (true) {
        adc_select_input(4);
        uint16_t raw = adc_read();

        // Converte o valor lido para tensão (3.3V / 4096 * raw)
        const float resolution = 3.3f / (4096);
        float voltage = raw * resolution;

        // Fórmula da documentação do RP2040 para conversão em Celsius (datasheet)
        float temperature = 27 - (voltage - 0.706f) / 0.001721f;

        printf("Temperatura: %.2f C\n", temperature);
        sleep_ms(1000);
    }
}
