#include <stdio.h>
#include "pico/stdlib.h"
#include "temperature_read.h"
#include "hal_temperature.h"



int main()
{
    stdio_init_all();

    while (true) {
        // Lê a temperatura e imprime no console
        ler_temperatura();
        sleep_ms(1000);
    }
}
