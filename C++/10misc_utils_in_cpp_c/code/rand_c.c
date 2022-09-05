#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    // time_t t;
    // srand((unsigned)time(&t));
    srand(time(NULL));

    const short int MAX = 100;
    const short int MIN = 20;
    int n = (rand() % (MAX - MIN + 1)) + MIN;

    printf("%d ", n);
    return 0;
}
