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
    char fileName[] = "new.my";

    fp = fopen("new.my", "w");

    for (int i = 0; i < 5; i++) {
        fprintf(fp, "This is line %d\n", i);
    }

    fclose(fp);

    // opening again but for appending
    fp = fopen("new.my", "a");
    fprintf(fp, "Again opening the file but for appending this line");

    return 0;
}
