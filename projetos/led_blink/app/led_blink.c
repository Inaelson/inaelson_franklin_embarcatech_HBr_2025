#include "pico/stdlib.h"
#include "hal_led.h"

int main() {

    led_init_hal();

    while (true){
        piscar_led();
        sleep_ms(500);
    }
}