#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
int main() {
    char a[] = "hello";
    a[0] = 'x'; // ok
    // a = "another";     // error: assignment to expression with array type
    printf("%s\n", a); // xello

    const char s[] = "hello";
    // s[0] = 'x';    // error: assignment of read-only location 's[0]'
    // s = "another"; // error: assignment to expression with array type
    printf("%s\n", s);

    char *ss = "hello";
    // ss[0] = 'x';        // runtime error
    ss = "ss another";  // OK
    printf("%s\n", ss); // another

    /* here "hello" is `Immutable` which simply means unmodifiable or unchangeable. Once String object is created its data or state can't be changed but a new String object is created. */

    const char *sss = "hello";
    // sss[0] = 'x'; // compile time error :  error: assignment of read-only location '*sss'
    sss = "sss another";
    printf("%s\n", sss);
}
