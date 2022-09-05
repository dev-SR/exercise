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
    // char name[]{"Jhon"};                       //<-- string literal (invalid in c)
    char name2[] = "Jhon";                     // <-- string literal
    char name3[] = {'J', 'h', 'o', 'n', '\0'}; // <-- char array ; explicit null termination is required
    char name4[] = {'J', 'h', '\n', 'o', 'n', '\0'};
    printf("%s\n", name2); // Jhon
    printf("%s\n", name3); // Jhon
    printf("%s\n", name4);
    // Jh
    // on

    /*
index  0   1   2   3   4   5
     ┌───┐───┐───┐───┐───┐───┐
     │ H │ e │ l │ l │ o │\0 │
     └───┘───┘───┘───┘───┘───┘
Hex   48  65  6C  6F  21  00
*/
    printf(GRN "**********Accessing a String**********\n" NC);
    name2[0] = 'X';
    printf("%s\n", name2); // Xhon
    /*
index  0   1   2   3   4   5
     ┌───┐───┐───┐───┐───┐───┐
     │ X │ e │ l │ l │ o │\0 │
     └───┘───┘───┘───┘───┘───┘
Hex   48  65  6C  6F  21  00
*/
    printf(GRN "**********Constant String**********\n" NC);
    char assign[] = "Jhon";
    // Not allowed
    // assign = "Another String";
    // but
    assign[0] = 'A';
    printf("%s\n", assign); // Ahon
    // with const char s[] ->
    const char s[] = "Jhon";
    // sc[0] = 'Y'; // compile time error
    printf("%s\n", s); // char *s = Jhon

    // Allowing Assignment:
    char *s1 = "Jhon";
    // s[0] = 'Y'; //Not Allowed runtime error
    // prints nothing as The contents of `s` should not be changed
    printf("char *s = %s\n", s);
    // though this is allowed
    s1 = "Another String";
    //`s` is a pointer variable, that can be changed to point elsewhere.
    printf("char *s = %s\n", s1); // char *s = Another String

    const char *s2 = "Jhon!"; // compile time error safety
    // s2[0] = 'Y'; //compile time error
    printf("const char *s2 = %s\n", s2); // const char *s2 = Jhon!
    s2 = "Another String";               // allowed
    printf("const char *s = %s\n", s2);  // const char *s = Another String
    /*  IN C++
            char *s = "Hello"; -> is not allowed
        ISO C++ forbids converting a string constant to 'char*'
        though,
            const char *s = "Hello"; -> is allowed
    */

    printf(GRN "**********String Input**********\n" NC);
    char input_str[10];
    printf("Please enter a word: ");
    scanf("%s", input_str);    // hello world
    printf("%s\n", input_str); // hello
    // fgets() (Should no longer be used)
    // gets() (Should no longer be used)
    // https://www.studymite.com/blog/strings-in-c

    // getline()  (Preferred Method)
    int bytes_read;
    int size = 10;
    char *string;
    // printf("Please enter a string: ");
    // /* These 2 lines are very important. */
    // string = (char *)malloc(size); //#include <stdlib.h>
    // bytes_read = getline(&string, &size, stdin);
    // printf("%s", string);
    // if (bytes_read == -1) {
    //     puts("ERROR!");
    // } else {
    //     puts(string);
    //     printf("\nCurrent size for string block: %d", bytes_read);
    // }
}