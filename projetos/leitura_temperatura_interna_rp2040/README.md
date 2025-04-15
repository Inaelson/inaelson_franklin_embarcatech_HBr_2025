# Leitura de temperatura interna do RP2040

Este projeto realiza a leitura da temperatura interna do chip RP2040 utilizando o ADC interno, exibindo os valores em tempo real via terminal serial.

## Objetivo

Demonstrar como utilizar o canal 4 do ADC do RP2040 para obter a temperatura interna do microcontrolador, convertendo os dados lidos em graus Celsius.

##  Lista de materiais: 

| Componente             | Conexão na BitDogLab             |
|------------------------|----------------------------------|
| BitDogLab (RP2040)     | - (sensor interno, sem conexão externa) |

## Execução

1. Abra o projeto no VS Code, usando o ambiente com suporte ao SDK do Raspberry Pi Pico (CMake + compilador ARM);
2. Compile o projeto normalmente (Ctrl+Shift+B no VS Code ou via terminal com cmake e make);
4. Conecte sua BitDogLab via cabo USB e coloque a Pico no modo de boot (pressione o botão BOOTSEL e conecte o cabo);
5. Copie o arquivo .uf2 gerado para a unidade de armazenamento que aparece (RPI-RP2);
6. A Pico reiniciará automaticamente e começará a executar o código;

## Lógica

- O programa inicializa o ADC interno e habilita o sensor de temperatura embutido no RP2040;
- O canal ADC 4 é selecionado, pois é o canal dedicado à leitura do sensor interno;
- A cada segundo, o valor bruto do ADC é lido, convertido em voltagem e transformado em temperatura (°C) utilizando a fórmula fornecida no datasheet do RP2040;
- A temperatura é exibida no terminal serial com precisão de duas casas decimais;

##  Arquivos

- `leitura_temperatura_interna_rp2040.c`: Código principal do projeto, contendo a configuração do ADC, leitura do sensor interno e conversão para temperatura em graus Celsius;

---

## 📜 Licença
MIT License - MIT GPL-3.0.
