#ifndef temperature_read_h
#define temperature_read_h

#include "pico/stdlib.h"

uint16_t init_temp_sensor();
float adc_to_celsius(uint16_t adc_val);


#endif // temperature_read_h