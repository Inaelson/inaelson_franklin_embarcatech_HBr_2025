# Leitura de joystick analógico com temporizador

Este projeto realiza a leitura de um joystick analógico utilizando o ADC interno do RP2040, exibindo os valores lidos a partir de temporizadores periódicos.

## Objetivo

Demonstrar o uso do ADC e de temporizadores com callbacks no Raspberry Pi Pico, realizando leituras contínuas dos eixos X e Y de um joystick, e exibindo os valores em tempo real via terminal serial.

##  Lista de materiais: 

| Componente             | Conexão na BitDogLab             |
|------------------------|----------------------------------|
| BitDogLab (RP2040)     | -                                |
| Joystick analógico     | Eixo Y: GPIO26 / Eixo X: GPIO27  |

## Execução

1. Abra o projeto no VS Code, usando o ambiente com suporte ao SDK do Raspberry Pi Pico (CMake + compilador ARM);
2. Compile o projeto normalmente (Ctrl+Shift+B no VS Code ou via terminal com cmake e make);
4. Conecte sua BitDogLab via cabo USB e coloque a Pico no modo de boot (pressione o botão BOOTSEL e conecte o cabo);
5. Copie o arquivo .uf2 gerado para a unidade de armazenamento que aparece (RPI-RP2);
6. A Pico reiniciará automaticamente e começará a executar o código;

## Lógica

- O programa inicializa o ADC interno e configura os pinos correspondentes aos eixos do joystick;
- Um temporizador repetitivo é configurado para exibir os valores lidos dos eixos X e Y a cada 500ms;
- As leituras do joystick são feitas no loop principal a cada 100ms, sendo armazenadas em variáveis globais para acesso pelo callback do temporizador.

##  Arquivos

- `reader_joystick_adc.c`: Código principal do projeto, com configuração dos ADCs e temporizador;

---

## 📜 Licença
MIT License - MIT GPL-3.0.