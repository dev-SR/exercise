#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
    char binary[] = "10110";
    int decimal = 0, i, power, len;
    len = strlen(binary);
    power = len - 1;
    decimal = 0;

    for (i = 0; i < len; i++) {
        int b = binary[i] - '0';
        //'0'(48) - '0'(48) = 0
        // '1'(49) - '0'(48) = 1
        // decimal = decimal + (b * pow(2, power));
        decimal += b * pow(2, power);
        power--;
    }
    printf("%d", decimal);

    return 0;
}
