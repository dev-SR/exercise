#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
int main() {
    int x = 1;
    int *p = NULL;
    if (p) {
        *p = 100;
        printf("content of *p: %d", *p);
    }
    p = &x;
    if (p) {
        *p = 10;
        printf("content of *p: %d", *p); // content of *p: 10
    }
}
