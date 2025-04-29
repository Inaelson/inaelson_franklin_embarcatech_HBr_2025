# Piscar LED da Raspberry Pi Pico W (Modularizado)

Este projeto é uma versão modularizada do exemplo **"blink"** padrão do Raspberry Pi Pico W, reorganizado conforme as boas práticas de estrutura de código exigidas pelo curso.

## Objetivo

Demonstrar a configuração básica do GPIO e temporização para piscar o LED onboard da Pico W, separando a lógica em módulos para melhor organização e reutilização de código.

---

## 📋 Estrutura do Projeto
```
.
├── include/
│   ├── led_embutido.h          # Cabeçalho com funções para comunicação com o hardware
│   └── hal_led.h        # Cabeçalho com funções abstraídas para uso no loop principal
├── app/
│   └── led_blink.c          # Aplicação principal (loop)
├── drivers/
│   └── led_embutido.c # Funções para comunicação direta com o hardware
├── hal/
│   └── hal_led.c # Funções para uso no loop principal
├── CMakeLists.txt     # Configuração de build
└── README.md          # Documentação
```

---

## 🔧 Lista de Materiais
| Componente              | Conexão/Conexão Interna          |
|-------------------------|----------------------------------|
| Raspberry Pi Pico W     | LED onboard (GPIO 25)            |

---

## 🚀 Execução

1. Abra o projeto no VS Code, usando o ambiente com suporte ao SDK do Raspberry Pi Pico (CMake + compilador ARM);
2. Compile o projeto normalmente (Ctrl+Shift+B no VS Code ou via terminal com cmake e make);
4. Conecte sua Raspberry Pi Pico W via cabo USB e coloque a Pico no modo de boot (pressione o botão BOOTSEL e conecte o cabo);
5. Copie o arquivo .uf2 gerado para a unidade de armazenamento que aparece (RPI-RP2);
6. A Pico reiniciará automaticamente e começará a executar o código;


---

## 📜 Licença
MIT License - **GPL-3.0**  