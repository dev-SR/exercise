#include <stdio.h>
#include <stdlib.h>
int main() {
    int n = 3;
    // scanf("%d", &n);
    printf("Enter 3 Comments:\n");
    char OpIn[n][100];
    for (int i = 0; i < n; i++) {
        printf("comment[%d]: ", i);
        gets(OpIn[i]);
    }
    for (int i = 0; i < 4; i++) {
        printf("%s\n", OpIn[i]);
    }
    return 0;
}