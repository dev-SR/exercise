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
    char *input_file = "main.jpg";
    fp = fopen(input_file, "rb");

    fseek(fp, 0, SEEK_END);  // move to the file end
    double size = ftell(fp); // ftell() returns the current file position of the specified stream with respect to the starting of the file.

    printf("File Size: %.2f bytes\n", size);
    printf("File Size: %.2f Kb\n", size / 1024);
    return 0;
}
