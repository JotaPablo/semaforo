#include <stdio.h>
#include "pico/stdlib.h"

#define RED_PIN 13
#define GREEN_PIN 11
#define BLUE_PIN 12


typedef enum { 
    VERMELHO, 
    AMARELO, 
    VERDE } EstadoSemaforo;



// Esta função alterna o estado do LED e imprime uma mensagem na saída serial.
bool semaforo_callback(struct repeating_timer *t) {
    
    static EstadoSemaforo estado = VERMELHO;

   switch (estado) {
        //Liga o Vermelho e desliga o Amarelo(Azul) e Verde. Coloca que o próximo estado é Amarelo(Azul)
        case VERMELHO:
            gpio_put(RED_PIN, true);
            gpio_put(BLUE_PIN, false);
            gpio_put(GREEN_PIN, false);
            printf("LED VERMELHO LIGADO\n");
            estado = AMARELO;  // Próximo estado
            break;

        //Liga o Amarelo(Azul) e desliga o Vermelho e Verde. Coloca que o próximo estado é Verde
        case AMARELO:
            gpio_put(RED_PIN, false);
            gpio_put(BLUE_PIN, true);
            gpio_put(GREEN_PIN, false);
            printf("LED AMARELO LIGADO\n");
            estado = VERDE;  // Próximo estado
            break;

        //Liga o Verde e desliga o Vermelho e Amarelo(Azul). Coloca que o próximo estado é Vermelho
        case VERDE:
            gpio_put(RED_PIN, false);
            gpio_put(BLUE_PIN, false);
            gpio_put(GREEN_PIN, true);
            printf("LED VERDE LIGADO\n");
            estado = VERMELHO;  // Reinicia o ciclo
            break;
    }
    
    return true;
}
int main()
{
    stdio_init_all();

    gpio_init(RED_PIN);              // Inicializa o pino do LED
    gpio_set_dir(RED_PIN, GPIO_OUT); // Configura o pino como saída
    gpio_init(GREEN_PIN);              // Inicializa o pino do LED
    gpio_set_dir(GREEN_PIN, GPIO_OUT); // Configura o pino como saída
    gpio_init(BLUE_PIN);              // Inicializa o pino do LED
    gpio_set_dir(BLUE_PIN, GPIO_OUT); // Configura o pino como saída

    struct repeating_timer timer;
    //Configura para chamar semaforo_callback a cada 3 segundos
    add_repeating_timer_ms(3000, semaforo_callback, NULL, &timer);
    
    //Ativa o LED inicialmente
    semaforo_callback(&timer);
    while (true) {
        printf("1 segundo passou\n");
        sleep_ms(1000);
    }
}
