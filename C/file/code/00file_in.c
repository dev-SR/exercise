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

    fp = fopen("in1.txt", "r");

    char names[10][10];
    int i = 0;
    while (fgets(names[i], 10, fp) != EOF) {
        printf("> %s\n", names[i]);
        i++;
    }

    fclose(fp);

    return 0;
}
