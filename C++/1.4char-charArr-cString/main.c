#include <stdio.h>
#include <stdlib.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
int main() {
    // char name[] = {"Jhon"}; // (invalid in c )

    // char name2[] = "Jhon";                     // <-- string literal
    // char name3[] = {'J', 'h', 'o', 'n', '\0'}; // <-- char array ; explicit null
    // printf("%s", name);

    // printf("%s", name2);
    // printf("%s", name3);

    char a[] = "hello"; // array version
    // char *p = "hello";  // pointer version

    // a = "new"; // invalid
    // p = "new"; // valid
    // with c
    // gets(a);
    // scanf("%s", a);
    // strcpy(a, "new");
    // a[0] = 'n';
    // a[1] = 'e';
    // a[2] = 'w';
    // a[3] = '\0';
    // // with c++
    // // cin >> a;
    // scanf("%s", p);not allowed
    // printf("%s\n", a);         // hello
    // printf("%s\n", p);         // hello
    // printf("%d\n", sizeof(a)); // 6bytes for array
    // printf("%d\n", sizeof(p)); // 4/8bytes for pointer + 6bytes for array
    // printf("%p\n", a);         // F804DFF6EA
    // printf("%p\n", &a);        // F804DFF6EA
    // printf("%p\n", p);         // F693395050
    // printf("%p\n", &p);        // F804DFF6E0
    // but if create dynamically allocate the string, we can change the element;
    // char *p = (char *)malloc(sizeof(char) * 6);
    // *(p) = 'h';
    // *(p + 1) = 'e';
    // *(p + 2) = 'l';
    // *(p + 3) = 'l';
    // *(p + 4) = 'o';
    // *(p + 5) = '\0';

    // *(p) = 'H'; // right, because the content hello3 points to lies on stack like other variables

    // int n, i;
    // char *ptr;
    // scanf("%d", &n);
    // ptr = (char *)malloc(n * sizeof(char));
    // for (i = 0; i < n; i++) {
    //     printf("Enter ptr[%d]: ", i);
    //     scanf(" %c", ptr + i);
    // }
    char *options[] = {"MEDIUM", "HARD", "EASY", "TOUGH"};
    options[3] = "VERY HARD"; // ok

    for (int i = 0; i < 5; i++) {
        printf("%s\n", options[i]);
    }
    return 0;
}
