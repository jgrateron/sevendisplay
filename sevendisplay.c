#include <stdio.h>
#include "pico/stdlib.h"

#define LED_A 19
#define LED_B 18
#define LED_C 15
#define LED_D 6
#define LED_E 2
#define LED_F 20
#define LED_G 21
#define SEVEN 7
#define MAX_NUMBER 16

int leds []    = {LED_A, LED_B, LED_C, LED_D, LED_E, LED_F, LED_G};

bool numeros [MAX_NUMBER] [SEVEN] = {
    {true,  true,  true,  true,  true,  true,  false},
    {false, true,  true,  false, false, false, false},
    {true,  true,  false, true,  true,  false, true},
    {true,  true,  true,  true,  false, false, true},
    {false, true,  true,  false, false, true,  true},
    {true,  false, true,  true,  false, true,  true},
    {true,  false, true,  true,  true,  true,  true},
    {true,  true,  true,  false, false, false, false},
    {true,  true,  true,  true,  true,  true,  true},
    {true,  true,  true,  true,  false, true,  true},
    {true,  true,  true,  false, true,  true,  true},
    {false, false, true,  true,  true,  true,  true},
    {true,  false, false, true,  true,  true,  false},
    {false, true,  true,  true,  true,  false, true},
    {true,  false, false, true,  true,  true,  true},
    {true,  false, false, false, true,  true,  true}};

int main(){
    stdio_init_all();
    
    for (int i = 0; i < SEVEN; i++){
        gpio_init(leds[i]);
        gpio_set_dir(leds[i], GPIO_OUT);
    }
    while (true){
        for (int i = 0; i < MAX_NUMBER; i++){
            for (int j = 0; j < SEVEN; j++){
                if (numeros[i][j]){
                    gpio_put(leds[j], 0);
                }
                else {
                    gpio_put(leds[j], 1);
                }
            }
            sleep_ms(1000);
        }
    }
    return 0;
}

