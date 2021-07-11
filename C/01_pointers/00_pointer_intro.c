#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
int main() {
    // Declare and Access
    int a = 12;
    int *ptr = &a;
    printf(RED "ptr:" NC " %p  %x  %X", ptr, ptr, ptr);

    // !Indirection to GET the values
    int n1 = *ptr;
    int n2 = *ptr + 8;
    printf(RED "\na:" NC " %d", *ptr);
    printf(RED "\nn1:" NC " %d", n1);
    printf(RED "\nn2:" NC " %d", n2);

    // !Indirection to SET value
    *ptr = 99;
    printf(RED "\nnew a:" NC " %d", *ptr);

    // !Indirection and void Pointers
    void *vPtr = &a;
    // int n3 = *vPtr; // warning: dereferencing 'void *' pointer
    //must cast a void pointer before indirection
    int n3 = *((int *)vPtr);
    printf(RED "\nn3:" NC " %d", n3);

    //!Testing for a Null pointer
    printf(GRN "\ntesting for a Null pointer....\n" NC);
    int *p = NULL;
    // execute if pointer isn't NULL
    if (p)
        printf("1 | pointer value: %d\n", *p);

    // execute if pointer is NULL
    int someValue = 123;
    if (!p) {
        p = &someValue;
    }
    // execute if pointer isn't NULL
    if (p)
        printf("2 | pointer value: %d\n", *p);
    return 0;
}
