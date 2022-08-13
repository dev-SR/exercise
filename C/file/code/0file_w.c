#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
int main() {
    // declare file pointer/handler
    FILE *fp;

    // open a existing/new file and assign it's address to the file handler
    // char fileName[] = "new.my";
    // fp = fopen(fileName, "w");
    fp = fopen("new.my", "w");

    // write to the file with
    // fprintf(file_pointer,format_string,...(n input for n format specifier specified in the format string))
    fprintf(fp, "This file is created by my program!; Additionally this a formatted string \n");
    fprintf(fp, "Feeling Great\n");
    fprintf(fp, "Additionally; `fprintf()` takes formatted string:");
    for (int i = 0; i < 5; i++) {
        fprintf(fp, "Formatted string with format specifier `%%d` -> %d\n", i);
    }

    // close the file with
    fclose(fp);

    // opening again but for appending
    fp = fopen("new.my", "a");
    fprintf(fp, "Again opening the file but for appending this line");

    return 0;
}