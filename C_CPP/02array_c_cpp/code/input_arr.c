#include <stdio.h>

// take input
void takeInput(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void display(int *p, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
}

int main() {
    int arr[3];
    int n = 3;
    takeInput(arr, n);
    display(arr, n);
}
