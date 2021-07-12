#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

#include <stdlib.h>

int main() {
    printf(GRN "**********Initializing a String**********\n" NC);
    char str[10] = {'H', 'e', 'l', 'l', 'o'};
    char str1[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char str2[] = "Hello";
    printf("%s\n", str);
    printf("%s\n", str1);
    printf("%s\n", str2);

    /*  
index  0   1   2   3   4   5
     ┌───┐───┐───┐───┐───┐───┐
     │ H │ e │ l │ l │ o │\0 │
     └───┘───┘───┘───┘───┘───┘
Hex   48  65  6C  6F  21  00
*/
    printf(GRN "**********Accessing a String**********\n" NC);
    str[0] = 'X';
    printf("%s\n", str);
    /*  
index  0   1   2   3   4   5
     ┌───┐───┐───┐───┐───┐───┐
     │ X │ e │ l │ l │ o │\0 │
     └───┘───┘───┘───┘───┘───┘
Hex   48  65  6C  6F  21  00
*/
    // Not allowed
    // str = "Another String";

    printf(GRN "**********Constant String**********\n" NC);
    printf(YEL "With char *s and const char *s\n" NC);
    const char sc[] = "Hello";
    // sc[0] = 'Y'; //compile time error
    printf("%s\n", sc);

    printf(YEL "With char *s and const char *s\n" NC);
    char *s = "Hello!";
    printf("char *s = %s\n", s);
    // s[0] = 'Y'; //Not Allowed runtime error
    //prints nothing as The contents of `s` should not be changed
    // printf("char *s = %s\n", s);
    //though this is allowes
    s = "Another String";
    //`s` is a pointer variable, that can be changed to point elsewhere.
    printf("char *s = %s\n", s);
    const char *s2 = "Hello!"; //compile time error safety
    // s2[0] = 'Y'; //compile time error
    printf("const char *s2 = %s\n", s2);
    s2 = "Another String"; //allowed
    printf("const char *s = %s\n", s2);
    /*  IN C++   
            char *s = "Hello"; -> is not allowed
        ISO C++ forbids converting a string constant to 'char*'
        though,
            const char *s = "Hello"; -> is allowed
    */

    printf(GRN "**********String Input**********\n" NC);
    char input_str[10];
    printf("Please enter a word: ");
    scanf("%s", input_str);    //hello world
    printf("%s\n", input_str); //hello
    //fgets() (Should no longer be used)
    //gets() (Should no longer be used)
    //https://www.studymite.com/blog/strings-in-c

    //getline()  (Preferred Method)
    int bytes_read;
    int size = 10;
    char *string;
    printf("Please enter a string: ");
    /* These 2 lines are very important. */
    string = (char *)malloc(size); //#include <stdlib.h>
    bytes_read = getline(&string, &size, stdin);
    printf("%s", string);
    if (bytes_read == -1) {
        puts("ERROR!");
    } else {
        puts(string);
        printf("\nCurrent size for string block: %d", bytes_read);
    }
}