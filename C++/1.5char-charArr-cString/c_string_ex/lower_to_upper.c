#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
int main() {
    char s[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    printf("%s\n", s);

    for (int i = 0; i < 5; i++) {
        if (s[i] >= 97 && s[i] <= 122) {
            s[i] = 'A' + (s[i] - 'a'); // A+(c-a) => 65+ (99-97) => 67 => C
        }
    }
    printf("%s\n", s);
    printf("%d", 'A');
    return 0;
}
