#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
int string_len(char str[]) {
    int len;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
int main() {

    printf("%d\n", string_len("hello"));       // 5
    printf("%d\n", string_len("hello world")); // 11

    char str[10];
    printf("Enter More String:\n");
    while (1 == scanf("%s", str)) {
        printf("%d\n", string_len(str));
    }

    return 0;
}

/*
Enter More String:
a
1
a b a
1
1
1
 */