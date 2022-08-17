#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
void str_cpy(char a[], char b[]) {
    int i;
    for (i = 0; b[i] != '\0'; i++) //  or  for(i=0;s1[i];i++)
    {
        a[i] = b[i];
    }
    a[i] = '\0';
}
typedef struct {
    int id;
    char name[20];
} Student;

typedef struct {
    int id;
    char *name;
} Student2;

int main() {
    char a[20] = "Hello";
    char b[20];
    str_cpy(a, "New");
    printf("%s\n", a); // New
    str_cpy(b, "New");
    printf("%s\n", b); // New

    // with char name[]
    Student s;
    s.id = 191;
    // s.name = "New"; // error: assignment to expression with array type
    str_cpy(s.name, "New");
    printf("%s\n", s.name); // new

    // with char *name
    Student2 s2;
    s2.id = 191;
    s2.name = "New";
    printf("%s\n", s2.name); // new
    return 0;
}
