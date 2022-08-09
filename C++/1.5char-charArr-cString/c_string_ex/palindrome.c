#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

#include <string.h>
int main() {
    char word[80], reverse_word[80];
    int i, j, len;
    scanf("%s", word);
    len = strlen(word);

    for (i = 0, j = len - 1; i < len; i++, j--) {
        reverse_word[i] = word[j];
    }

    reverse_word[len] = '\0';
    printf("%s\n", reverse_word);

    if (0 == strcmp(word, reverse_word)) {
        printf("%s is a palindrome word", word);
    } else {
        printf("%s is a not palindrome word", word);
    }

    return 0;
}
