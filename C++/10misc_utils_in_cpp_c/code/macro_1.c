#include <stdio.h>
#define SWAP(a, b) \
    {              \
        a ^= b;    \
        b ^= a;    \
        a ^= b;    \
    }

void main() {
    int a = 10, b = 20;
    printf("a=%d,b=%d\n", a, b);
    SWAP(a, b);
    printf("a=%d,b=%d\n", a, b);
}
