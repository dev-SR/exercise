#include "mod1.h"
#include <stdio.h>

void print_mod1() {
    Led led = LED_ON;
    printf("This is mod1, led: ");
    print_led_state(led);
    printf("\n");
}