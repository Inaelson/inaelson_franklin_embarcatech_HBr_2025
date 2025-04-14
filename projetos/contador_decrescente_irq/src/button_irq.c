#include "button_irq.h"

volatile absolute_time_t last_irq_button_a = 0;
volatile absolute_time_t last_irq_button_b = 0;

volatile uint8_t counter_click = 0;
bool countdown_on = false;

// Estruturas de timer para cada botão
struct repeating_timer debounce_timer_a;
struct repeating_timer debounce_timer_b;

/** Função de callback para o debounce e reativação da interrupção do botão A **/
bool debounce_callback_a(struct repeating_timer *t)
{
    gpio_set_irq_enabled(BUTTON_A_PIN, GPIO_IRQ_EDGE_FALL, true); // Reativa a interrupção
    return false; // Retorna falso para não repetir a chamada

}

/** Função de callback para o debounce e reativação da interrupção do botão B **/
bool debounce_callback_b(struct repeating_timer *t)
{
    gpio_set_irq_enabled(BUTTON_B_PIN, GPIO_IRQ_EDGE_FALL, true); // Reativa a interrupção
    return false; // Retorna falso para não repetir a chamada
}

void button_irq_handler(uint gpio, uint32_t events){

    //Desativa a interrupção para evitar múltiplas chamadas
    gpio_set_irq_enabled(gpio, GPIO_IRQ_EDGE_FALL, false);

    if(gpio == BUTTON_A_PIN){
       add_repeating_timer_ms(DEBOUNCE_TIME, debounce_callback_a, NULL, &debounce_timer_a);
       printf("Botao A pressionado, timer iniciado\n");
       countdown_on = true;
    } else {
        add_repeating_timer_ms(DEBOUNCE_TIME, debounce_callback_b, NULL, &debounce_timer_b);
        if (countdown_on){
            counter_click++;
            // printf("Botao B pressionado, clique +1, contagem atual: %d\n", counter_click);  
        }
        } 
}

void setup_buttons(){
    //Inicializa o pino para o botão A como entrada e habilita o pull-up
    gpio_init(BUTTON_A_PIN);
    gpio_set_dir(BUTTON_A_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_A_PIN);
    
    //Inicializa o pino para o botão B como entrada e habilita o pull-up
    gpio_init(BUTTON_B_PIN);
    gpio_set_dir(BUTTON_B_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_B_PIN);

    //Habilita as interrupções nos botões A e B
    gpio_set_irq_enabled_with_callback(BUTTON_A_PIN, GPIO_IRQ_EDGE_FALL, true, &button_irq_handler);
    gpio_set_irq_enabled(BUTTON_B_PIN, GPIO_IRQ_EDGE_FALL, true);
    
    printf("Botoes e irqs ativados\n");
}
