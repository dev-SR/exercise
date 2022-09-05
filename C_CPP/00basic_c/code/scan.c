#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
int main() {

    int a;
    scanf("%d", &a);
    printf("%d\n", a);

    double x, y;
    scanf("%lf %lf", &x, &y);
    printf("%lf %lf\n", x, y);

    // At this point we're leaving the '\n' on stdin:
    // Therefore we have to eat it.
    getchar(); // <-- Makes eat the space characters, tabulations, newline.

    char c1;
    printf("Enter C1:");
    scanf("%c", &c1);
    printf("%c\n", c1);

    getchar(); // <-- Makes eat the space characters, tabulations, newline.

    char c2;
    printf("Enter C2:");
    c2 = getchar();
    printf("%c\n", c2);

    getchar(); // <-- Makes eat the space characters, tabulations, newline.

    char ch;
    do {
        printf("Enter a character | `q` to Quit\n");
        scanf("\n%c", &ch); /* '\n' <-- Makes `scanf` eat the newline. */
        // or
        // scanf(" %c", &ch); /* ' ' <-- Makes `scanf` eat the newline. */
        printf("%c\n", ch);
    } while (ch != 'q');

    return 0;
}
