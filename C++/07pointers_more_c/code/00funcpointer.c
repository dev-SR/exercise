#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}

int main() {
    int (*function_pointer)(int, int);
    function_pointer = &add;

    printf("Res: %d\n", function_pointer(10, 20)); // Res: 30

    function_pointer = &sub;
    printf("Res: %d", function_pointer(20, 10)); // Res: 10

    return 0;
}
