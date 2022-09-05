#include <stdio.h>
#include <time.h>
void fn(int x, int n) {
    x = n * 2;
}
int main() {

    int i, j, x, n;
    clock_t start_time, end_time;
    double time_elapsed;

    start_time = clock();
    n = 12345678;
    for (int i = 0; i < 100000000; i++) {
        for (int j = 0; j < 10; j++) {
            x = n * 2;
        }
    }
    end_time = clock();
    time_elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time elapsed: %lf sec.\n", time_elapsed); //~1+sec

    start_time = clock();

    n = 12345678;
    for (int i = 0; i < 100000000; i++) {
        for (int j = 0; j < 10; j++) {
            fn(x, n);
        }
    }

    end_time = clock();

    time_elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time elapsed: %lf sec.", time_elapsed); //~2+sec

    return 0;
}
