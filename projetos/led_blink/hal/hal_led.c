#include "hal_led.h"
#include "led_embutido.h"
#include "pico/stdlib.h"

void piscar_led(){
    static bool estado = false;
    
    led_estado(estado);
    estado = !estado;
}

void led_init_hal(){
    led_init();
}