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

    fp = fopen("in3.txt", "r");

    char lines[10][100];
    int i = 0;
    char name[30];
    int age;
    // 1. Read Lines
    while (fgets(lines[i], 100, fp)) {
        printf("> %s", lines[i]);
        // 2. Now reads the formatted input from that line
        sscanf(lines[i], "%s %d", name, &age);
        printf("Name: %s ID: %d\n", name, age);
        i++;
    }

    fclose(fp);

    return 0;
}
