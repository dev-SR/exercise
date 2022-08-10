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
    char name[30];
    int id;

    fp = fopen("in1.my", "r");
    char line[80];
    while (fgets(line, 80, fp) != NULL) {
        // printf("%s", line);
        sscanf(line, "%s %d", name, &id);
        printf("Name: %s ID: %d\n", name, id);
    }

    fclose(fp);
    return 0;
}
