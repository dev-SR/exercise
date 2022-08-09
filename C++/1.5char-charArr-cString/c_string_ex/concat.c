#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
int main() {
    char s1[] = "Bangla", s2[] = "desh", s[12];
    int i, j, len1 = 6, len2 = 4;
    // copy from a
    for (i = 0, j = 0; i < len1; i++, j++) {
        s[i] = s1[i];
    }
    // copy from b
    for (i = 0; i < len2; i++, j++) {
        s[j] = s2[i];
    }
    s[j] = '\0'; // append terminator at the end
    printf("%s\n", s);

    return 0;
}
