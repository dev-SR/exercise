

#include <stdio.h>
#include <string.h>

void main() {
    char c[10] = "1234";
    int zero = '0'; //48
    int n = c[0];   //49
    n = n - zero;
    printf("%d", n);
}