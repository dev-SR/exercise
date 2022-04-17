#include <stdio.h>
int main() {
    int a[] = {1, 2, 3, 4};
    printf("%d\n", a);    //!6422032
    printf("%d\n", *a);   //!1
    printf("%d\n", a[0]); //!1
    printf("%p\n", a);    //000000000061FE10

    char c[] = "abc";
    printf("%s\n", c);     //!abc
    printf("%c\n", c);     // ♀/../ⁿ ->garbage
    printf("1.n %d\n", c); // 6422028

    char *p = &c[0];
    printf("%p\n", p); //000000000061FDFC
    // printf("%c\n", *p); //a
    // printf("%s\n", *p); //prints nothing
    printf("%s\n", p); //!abc
    printf("%c\n", p); //ⁿ

    char ch = 'x';
    char *pCh = &ch;
    printf("%s\n", pCh); //xabc  <- with '%s' it prints out character x
    // then continue to print garbage values until a null character is
    //found.
    // printf("%s", *pCh); //prints nothing
    printf("%c", *pCh); //x
}