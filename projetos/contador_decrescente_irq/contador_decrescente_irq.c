#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "hardware/timer.h"
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "inc/ssd1306.h"
#include "hardware/i2c.h"
#include "src/button_irq.h"

const uint I2C_SDA = 14;
const uint I2C_SCL = 15;

uint8_t ssd[ssd1306_buffer_length];
volatile int8_t countdown_timer = 9;


// Preparar área de renderização para o display (ssd1306_width pixels por ssd1306_n_pages páginas)
struct render_area frame_area = {
    start_column : 0,
    end_column : ssd1306_width - 1,
    start_page : 0,
    end_page : ssd1306_n_pages - 1
};

struct repeating_timer countdown_realtime;

void send_text_to_render(char *text[], size_t linhas);
bool countdown_realtime_callback(struct repeating_timer *t);

int main()
{
    stdio_init_all();   // Inicializa os tipos stdio padrão presentes ligados ao binário
    sleep_ms(1000);

    // Inicialização dos botões
    setup_buttons();

    //Estado dos timers
    bool timers_started = false;


    // Inicialização do i2c
    i2c_init(i2c1, ssd1306_i2c_clock * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    // Processo de inicialização completo do OLED SSD1306
    ssd1306_init();


    calculate_render_area_buffer_length(&frame_area);

    // zera o display inteiro

    memset(ssd, 0, ssd1306_buffer_length);
    render_on_display(ssd, &frame_area);
    
    // Parte do código para exibir a mensagem no display (opcional: mudar ssd1306_height para 32 em ssd1306_i2c.h)
    char buffer_click[10];
    char buffer_timer[10];
    char *data_countdown[]= {
        buffer_click,
        buffer_timer
    };


    //Exibir mensagem inicial na tela

    
    char *text_init[] = {
        "  Bem vindo ao",
        "    contador",
        "      de",
        "    cliques"
    };
    send_text_to_render(text_init, count_of(text_init));

    while(true) {
        if (countdown_on && !timers_started) {
            add_repeating_timer_ms(-1000, countdown_realtime_callback, NULL, &countdown_realtime);
            memset(ssd, 0, ssd1306_buffer_length);
            timers_started = true;
        }

        if (!countdown_on && timers_started) {
            timers_started = false;
            countdown_timer = 9;
            memset(buffer_click, 0, sizeof(buffer_click));
        }

        if (countdown_on) {
            
            sprintf(buffer_click, "     %d", counter_click);
            sprintf(buffer_timer, "     %d", countdown_timer);
            char *text[] = {
                "Tempo restante",
                "",
                buffer_timer,
                "",
                "Cliques",
                "",
                buffer_click
            };
            send_text_to_render(text, count_of(text));
        }

        sleep_ms(100);
    }



    return 0;
}

void send_text_to_render(char *text[], size_t linhas) {

    int y = 0;
    for (uint i = 0; i < linhas; i++) {
        ssd1306_draw_string(ssd, 5, y, text[i]);
        y += 8;
    }

    render_on_display(ssd, &frame_area);
}


bool countdown_realtime_callback(struct repeating_timer *t){
            
    if(countdown_timer == 0){
        countdown_on = false;
        counter_click = 0;
        return false;
    } else {
        countdown_timer--;
    }
    
    return true;
};