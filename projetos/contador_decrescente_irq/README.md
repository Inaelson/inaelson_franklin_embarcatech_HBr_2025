
# Contador decrescente com registro de eventos por interrupção

Este projeto implementa um contador decrescente controlado por interrupção, exibindo as alterações de estado em tempo real.

## Objetivo

Desmontrar o uso de IRQs e aplicações em tempo real utilizando um contador que registra a quantidade de cliques em uma determinado intervalo de tempo, exibindo as informações no display OLED.

##  Lista de materiais: 

| Componente            | Conexão na BitDogLab      |
|-----------------------|---------------------------|
| BitDogLab (RP2040)    | -                         |
| Botão de pressão tátil | Botão A: GPIO5 / Botão B: GPIO6 |
| Display OLED I2C 128x64 | I2C_SDA = GPIO14 / I2C_SCL = GPIO15; |

## Execução

1. Abra o projeto no VS Code, usando o ambiente com suporte ao SDK do Raspberry Pi Pico (CMake + compilador ARM);
2. Compile o projeto normalmente (Ctrl+Shift+B no VS Code ou via terminal com cmake e make);
4. Conecte sua BitDogLab via cabo USB e coloque a Pico no modo de boot (pressione o botão BOOTSEL e conecte o cabo);
5. Copie o arquivo .uf2 gerado para a unidade de armazenamento que aparece (RPI-RP2);
6. A Pico reiniciará automaticamente e começará a executar o código;

## Lógica

- Ao pressionar o botão A, se inicia uma contagem regressiva de 9 até 0, habilitando as interrupções dos botões. Se pressionar o Botão B durante a contagem, é acrescido +1 na contagem de cliques;
- Quando o contador chega a 0, as interrupções são desabilitadas, não sendo possível modificar a quantidade de cliques. Somente ao pressionar o botão A que o processo se inicia novamente com o número de cliques resetado em 0.


##  Arquivos

- `contador_descrente_irq.c`: Código principal do projeto;
- `button_irq.c`: Configurações das interrupções para os botões;
- `button_irq.h`: Arquivo de cabeçalho para o "button_irq.c";
- `ssd1306.h`, `ssd1306_i2c.c`, `ssd1306_i2c.h`: Arquivos padrão com as configurações do display OLED;
- `ssd1306_font.h`: Arquivo de cabeçalho contendo um mapa dos caracteres para exibição no display OLED;

---

## 📜 Licença
MIT License - MIT GPL-3.0.
