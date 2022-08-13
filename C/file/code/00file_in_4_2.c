#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
int main() {
    FILE *fp;

    fp = fopen("in4.txt", "r");

    char lines[10][100];
    int i = 0;
    char name[30];
    int age;
    // skip first line:
    fseek(fp, 8 + 2, SEEK_SET); // len("Name Age\n") = 8, SEEK_SET=0=> start from begin
    while (fscanf(fp, "%s %d", name, &age) != EOF) {
        printf("Name: %s ID: %d\n", name, age);
    }

    fclose(fp);

    return 0;
}
