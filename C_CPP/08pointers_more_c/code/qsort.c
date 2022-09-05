#include <stdio.h>
#include <stdlib.h>

int compareCB(const void *a, const void *b) {
    // printf("%d %d\n", *(int *)a, *(int *)b);
    //(int*): void pinter to int pointer | *(int*) : dereference
    return (*(int *)a - *(int *)b);
}

int main() {
    int i, n = 5;
    int arr[] = {60, 6, 100, 1, 200};

    qsort(arr, n, sizeof(int), compareCB);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    } // 1 6 60 100 200
    //(*(int *)b - *(int *)a); ->  200 100 60 6 1
    return 0;
}
