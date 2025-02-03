# 🚦 Semáforo com Raspberry Pi Pico - BitDogLab

Projeto desenvolvido para demonstrar o uso da função `add_repeating_timer_ms()` do **Pico SDK** para controle de um semáforo de LEDs com temporização.

## Descrição
Este projeto simula um **semáforo** utilizando um **Raspberry Pi Pico** e três LEDs (vermelho, amarelo e verde). O sistema segue um fluxo cíclico com temporização de **3 segundos** para cada mudança de estado.

## Funcionalidades
- **Alternância de LEDs conforme um semáforo real**
  - 🔴 Vermelho → 🟡 Amarelo → 🟢 Verde → (reinicia o ciclo)
- **Temporização controlada**
  - Mudança de estado a cada **3 segundos** utilizando `add_repeating_timer_ms()`
- **Feedback via porta serial**
  - Exibe mensagens indicando o estado atual do semáforo
  - Exibe mensagem a cada 1 segundo para monitoramento

##  Estrutura do Projeto

| Arquivo           | Descrição                                       |
|-------------------|-----------------------------------------------|
| `temp_periodico.c`     | Código principal com controle dos LEDs        |
| `diagram.json`   | Arquivo de configuração para simulação no Wokwi |
| `wokwi.toml`     | Configurações do simulador Wokwi              |
| `CMakeLists.txt` | Arquivo de build do CMake                     |

##  Instalação
1. **Pré-requisitos**
   - Clonar o repositório:
     ```bash
     git clone https://github.com/JotaPablo/temp_periodico.git
     cd temp_periodico
     ```
   - Instalar o **Visual Studio** Code com as seguintes extensões:
     - **Raspberry Pi Pico SDK**
     - **Wokwi**

2. **Compilação**
   - Compile o projeto no terminal:
     ```bash
     mkdir build
     cd build
     cmake ..
     make
     ```
   - Ou através da extensão da Raspeberry Pi Pico no VS CODE

3. **Execução**
   - **Na placa física:** 
     - Conecte a placa ao computador em modo BOOTSEL.
     - Copie o arquivo `.uf2` gerado na pasta `build` para o dispositivo identificado como `RPI-RP2` ou Envie através da extensão da Raspeberry Pi Pico no VS CODE.
   - **No simulador Wokwi:** 
     - Abra o arquivo `diagram.json` no Wokwi e execute a simulação.

## Hardware
| Componente       | GPIO | Função                  |
|------------------|------|-------------------------|
| LED Vermelho     | 13   | Parar     |
| LED Verde        | 11   | Seguir    |
| LED Azul(Amarelo)         | 12   | Atenção     |


## Requisitos Atendidos
✅ Início do semáforo na cor vermelha

✅ Temporização de 3 segundos por cor

✅ Implementação da função callback do temporizador

✅ Impressão de mensagens a cada 1 segundo na porta serial
