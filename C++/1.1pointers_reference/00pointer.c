#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define NC "\e[0m"
int main() {
    int a = 10;
    int *p;
    p = &a;
    printf("Initial Content: %d\n", a);                 // 10
    printf("Initial Content of the pointer: %d\n", *p); // 10

    // changing the content thorough the variable itself:
    a = 20;
    printf("Content now: %d\n", a);                   // 20
    printf("Content of the pointer, now : %d\n", *p); // 20

    // changing the content thorough the pointer:
    *p = 30;
    printf("Content now: %d\n", a);                   // 30
    printf("Content of the pointer, now : %d\n", *p); // 30
}