#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
int main() {
    FILE *fp_in, *fp_out;
    int n1, n2, sum;

    fp_in = fopen("in.my", "r");
    fp_out = fopen("out.my", "w");

    // fscanf(fp_in, "%d", &n1);
    // fscanf(fp_in, "%d", &n2);
    // or
    // fscanf(fp_in, "%d %d", &n1, &n2);

    // or
    // read as a line with fgets and then read two int
    // from that line with sscanf()
    char line[80];
    fgets(line, 80, fp_in);
    sscanf(line, "%d %d", &n1, &n2);
    printf("Line: %s\n", line); // Line: 1 2

    sum = n1 + n2;
    printf("%d + %d = %d", n1, n2, sum);
    fprintf(fp_out, "%d\n", sum);

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
