#include "led.h"
#include <stdio.h>

void print_led_state(Led led) {
    printf("%s", led == LED_OFF ? "LED_OFF" : "LED_ON");
}