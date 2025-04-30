# 🌡️ Leitura de Temperatura Interna no RP2040

Este projeto inclui testes unitários usando o framework Unity, para validar a conversão do valor do ADC em graus Celsius com base na fórmula oficial do datasheet.


## 🎯 Objetivo

Demonstrar como utilizar o canal 4 do ADC do RP2040 para obter a temperatura interna do chip, convertendo os dados lidos em graus Celsius e a implementação de testes unitários para garantir que a conversão do valor do ADC para temperatura seja feita corretamente.

## 🧰 Lista de Materiais

| Componente             | Observações                            |
|------------------------|----------------------------------------|
| BitDogLab (RP2040)     | Sensor interno — sem conexão externa   |

## ▶️ Execução

1. Abra o projeto no VS Code com o ambiente preparado para o Raspberry Pi Pico (CMake + compilador ARM);
2. Compile o projeto (`Ctrl+Shift+B` ou via terminal com `cmake` e `make`);
3. Conecte sua BitDogLab via cabo USB;
4. Coloque a placa em modo boot (pressione o botão **BOOTSEL** e conecte o cabo USB);
5. Copie o arquivo `.uf2` gerado para a unidade de armazenamento que aparecer (`RPI-RP2`);
6. A placa reiniciará automaticamente e começará a executar o código.


## ✅ Execução dos Testes

Este projeto utiliza o framework [Unity](http://www.throwtheswitch.org/unity) para testes unitários.

> [!NOTE]
> - Unity já incluído na pasta `test/unity`;
> - Testes implementados em `test/test_temperature_read.c`;


### 🔧 Como executar os testes

1. Coloque a placa no modo BOOTSEL e copie o arquivo `tests.uf2` para a unidade `RPI-RP2` que aparecer;

2. A placa será reiniciada automaticamente e os testes serão executados;

3. Abra um terminal serial (por exemplo, com `minicom`, `PuTTY`, ou o monitor serial do VS Code) com as seguintes configurações:

   ```
   Baud rate: 115200
   Porta:     (verifique qual foi atribuída ao seu dispositivo)
   ```

4. O resultado dos testes será exibido no terminal serial, com mensagens como:

   ```
   Unity test run 1 of 1
   test_known_reference_temperature: PASS
   -----------------------
   1 Tests 0 Failures 0 Ignored
   OK
   ```

## 🧠 Lógica do Projeto

- O programa inicializa o ADC interno e habilita o sensor de temperatura do RP2040;
- O canal **ADC 4** é selecionado, pois é reservado para leitura da temperatura interna;
- A cada segundo:
  - O valor bruto do ADC é lido;
  - Ele é convertido para voltagem (baseado em 3.3V e resolução de 12 bits);
  - A voltagem é convertida para temperatura (°C), conforme fórmula do datasheet;
- A temperatura é exibida no terminal serial com duas casas decimais de precisão.

Claro! Abaixo está a versão em **Markdown** com as duas seções ajustadas:

---

### 🧪 Lógica dos Testes

O teste unitário implementado em `test/test_temperature_read.c` tem o objetivo de validar a função `adc_to_celsius`, que converte um valor de ADC bruto em temperatura.

**Como o teste funciona:**

- Um valor de tensão é simulado indiretamente ao passar um valor bruto de ADC equivalente à tensão de 0.706 V, que segundo o datasheet do RP2040 representa **aproximadamente 27°C**.
- Esse valor é passado para a função `adc_to_celsius`.
- O resultado retornado é comparado com o valor esperado (27.0) com uma margem de tolerância de `±0.1°C` usando a macro `TEST_ASSERT_FLOAT_WITHIN()` do Unity.

Este teste garante que a conversão esteja funcionando corretamente dentro de uma margem aceitável.

---

## 📁 Arquivos

```
.
├── app/                        # Código principal do aplicativo
│   └── adc_temperature_with_test.c
├── drivers/                   # Lógica de conversão e acesso ao ADC
│   └── temperature_read.c
├── hal/                       # Camada de abstração de hardware (HAL)
│   └── hal_temperature.c
├── include/                   # Arquivos de cabeçalho (.h) acessíveis globalmente
│   ├── temperature_read.h
│   └── hal_temperature.h
├── test/                      # Código de testes unitários
│   ├── test_temperature_read.c
│   └── unity/                 # Framework Unity para testes
│       └── src/
└── CMakeLists.txt             # Arquivo de configuração principal do CMake
```

---

## 📜 Licença

Este projeto está licenciado sob a [MIT License](https://opensource.org/licenses/MIT).