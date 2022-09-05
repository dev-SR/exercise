#include <stdio.h>
enum LEVEL { EASY = 1,
             MEDIUM = 2,
             HARD = 3 };
int main() {
    printf("value: %d\n", EASY);   // value: 1
    printf("value: %d\n", MEDIUM); // value: 2
    printf("value: %d\n", HARD);   // value: 3

    return 0;
}
