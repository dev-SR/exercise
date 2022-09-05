#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fp_in, *fp_out;
    char *input_file = "main.jpg";
    char *output_file = "copied.jpg";
    // char ch;
    int ch; // `fgetc` returns int!! -> see the difference with `char ch`;

    fp_in = fopen(input_file, "rb");
    if (!fp_in) {
        perror("Error ");
        return EXIT_FAILURE;
    }

    fp_out = fopen(output_file, "wb");

    while ((ch = fgetc(fp_in)) != EOF)
        fputc(ch, fp_out);

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
