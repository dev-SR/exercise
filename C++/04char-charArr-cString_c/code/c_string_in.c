#include <stdio.h>
int main() {
    int i, t;
    char s[1000];
    scanf("%d", &t);
    while (t--) {
        scanf(" %[^\n]", s);
        printf("> %s\n", s);
    }
}