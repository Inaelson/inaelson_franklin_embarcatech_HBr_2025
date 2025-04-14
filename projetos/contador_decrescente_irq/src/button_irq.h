#include "pico/stdlib.h"
#include "hardware/irq.h"
#include <stdio.h>

#ifndef button_irq_h
#define button_irq_h


#define BUTTON_A_PIN 5
#define BUTTON_B_PIN 6
#define DEBOUNCE_TIME 200

extern volatile uint8_t counter_click;
extern bool countdown_on;

void setup_buttons(void);
void button_irq_handler(uint gpio, uint32_t events);


#endif