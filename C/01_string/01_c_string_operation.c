#include <stdio.h>
#include <string.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

int main() {
    printf(GRN "String Length:\n" NC);
    char s[] = "I love programming in C!";
    printf("%s\n", s);
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    // for (i = 0; s[i] != '\0'; i++) { // }

    printf("String length (from scratch): %d\n", i);
    printf("Sizeof string: %d\n", sizeof(s));
    printf("String length (built in): %d\n", strlen(s));

    printf(GRN "String Copy: strcpy, strncpy\n" NC);
    char another_string[] = "Programming is funny";
    printf(YEL "strcpy......................\n" NC);
    printf("1. Before copy: \"%s\"\n", s);
    //char *strcpy( char *dest, const char *src )
    strcpy(s, another_string);
    printf("2. After copy: \"%s\"\n\n", s);

    printf(YEL "strncpy.....................\n" NC);
    printf("3. Before copy: \"%s\"\n", s);
    /* char *strncpy( char *dest, const char *src, size_t n )
		n: The first n character copied from src to dest. 
	*/
    printf("4. After copy: \"%s\"\n\n", strncpy(s, "Hello World", 3));
    // The null char is missing!
    printf("5. Before copy: \"%s\"\n", s);
    printf("6. After copy: \"%s\"\n\n", strncpy(s, "Hello World", sizeof(s)));
    printf("7. Before copy: \"%s\"\n", s);
    char another_long_string[] = "This is a dummy very very long string...";
    strncpy(s, another_long_string, sizeof(s));
    s[sizeof(s) - 1] = '\0';
    printf("8. After copy: \"%s\"\n\n", s);

    /* String Compare: strcmp, strncmp */
    char str_1[] = "abc";
    char str_2[] = "abcaaaaa";

    printf("strcmp %s, %s: %d\n", str_1, str_2, strcmp(str_1, str_2));
    printf("strncmp %s, %s: %d\n", str_1, str_2, strncmp(str_1, str_2, 3));
    return 0;
}
/* 
I love programming in C!
String length (from scratch): 24
Sizeof string: 25
String length (built in): 24
String Copy: strcpy, strncpy
strcpy......................
1. Before copy: "I love programming in C!"
2. After copy: "Programming is funny"

strncpy.....................
3. Before copy: "Programming is funny"
4. After copy: "Helgramming is funny"

5. Before copy: "Helgramming is funny"
6. After copy: "Hello World"

7. Before copy: "Hello World"
8. After copy: "This is a dummy very ver"

strcmp abc, abcaaaaa: -1
strncmp abc, abcaaaaa: 0

 */