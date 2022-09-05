#include <stdio.h>
int main() {
    FILE *fp;

    fp = fopen("in2.txt", "r");

    char names[10][100];
    int i = 0;
    while (fgets(names[i], 100, fp)) {
        printf("> %s", names[i]);
        i++;
    }

    fclose(fp);

    return 0;
}