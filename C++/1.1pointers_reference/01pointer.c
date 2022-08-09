#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define NC "\e[0m"
int main() {
    // Declare and Access
    int a = 12;
    int *ptr = &a;
    printf("ptr: %p  %x  %X", ptr, ptr, ptr);

    // !GET content of pointer
    int n1 = *ptr;
    printf("\nContent: %d", a);    // 12
    printf("\nContent: %d", *ptr); // 12
    printf("\nContent: %d", n1);   // 12

    // !SET new value using pointer
    *ptr = 99;
    printf("\nNew Content: %d", a);    // 99
    printf("\nNew Content: %d", *ptr); // 99

    // !void Pointers
    void *vPtr = &a;
    // int n3 = *vPtr; // warning: dereferencing 'void *' pointer
    // must cast a void pointer before indirection
    int n3 = *((int *)vPtr);          // converting to an integer
    printf(RED "\nn3:" NC " %d", n3); // 99
}