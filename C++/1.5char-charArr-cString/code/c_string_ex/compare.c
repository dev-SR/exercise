#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
#include <string.h>

int string_compare(char a[], char b[]) {
    for (int i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return -1;
    }

    //  aa == aa
    if (strlen(a) == strlen(b))
        return 0;
    if (strlen(a) > strlen(b))
        return 1;
    if (strlen(a) < strlen(b))
        return -1;
}

int main() {
    // How String Comparision Works!!!
    printf("%d\n", strcmp("aab", "aaa")); // 1 a>b
    printf("%d\n", strcmp("aaa", "aab")); //-1 a<b
    printf("%d\n", strcmp("ba", "ca"));   //-1
    printf("%d\n", strcmp("aa", "aa"));   // 0
    printf("%d\n", strcmp("aaa", "aa"));  // 1
    printf("\n");
    // using custom comparison:
    printf("%d\n", string_compare("aab", "aaa")); // 1
    printf("%d\n", string_compare("aaa", "aab")); //-1
    printf("%d\n", string_compare("ba", "ca"));   //-1
    printf("%d\n", string_compare("aa", "aa"));   // 0
    printf("%d\n", string_compare("aaa", "aa"));  // 1
    printf("%d\n", string_compare("aa", "aaa"));  // -1
}
