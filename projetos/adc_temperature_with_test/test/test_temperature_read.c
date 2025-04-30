#include "unity.h"
#include "temperature_read.h"
#include "hardware/adc.h"
#include <stdio.h>

void setUp(void) {
    // Inicializa o hardware necessário
    adc_init();
}

void tearDown(void) {
    return;
}

void test_known_reference_temperature(void) {
    uint16_t adc_val = (uint16_t)((0.706f / 3.3f) * 4095.0f);   // Valor do adc de aproximadamente = 875
    float expected = 27.0f;
    float actual = adc_to_celsius(adc_val);
    TEST_ASSERT_FLOAT_WITHIN(0.1f, expected, actual);
}

// Função principal para executar todos os testes
int main(void) {
    stdio_init_all();

    // Aguarda a USB ficar disponível
    sleep_ms(2000);

    UNITY_BEGIN();
    RUN_TEST(test_known_reference_temperature);
    UNITY_END();

    while (true) {
        tight_loop_contents(); // mantém a USB ativa
    }

    return 0;
}
