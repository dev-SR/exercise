#include "mod2.h"
#include <stdio.h>

void print_mod2() {
    Led led = LED_OFF;
    printf("This is mod2, led: ");
    print_led_state(led);
    printf("\n");
}