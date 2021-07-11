#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
int main() {
    int io_count = 0;
    const int max_io_count = 5;
    float io_array[max_io_count];

    for (io_count = 0; io_count < max_io_count; io_count++) {
        float value;
        printf("Insert an amount of money (0 to end):\n");
        printf("[%d/%d] ", io_count + 1, max_io_count);
        scanf("%f", &value);

        if (value == 0) {
            break;
        }

        io_array[io_count] = value;
    }

    printf("------------------\n");

    float sum = 0;
    for (int i = 0; i < io_count; i++) {
        sum += io_array[i];
        printf(" %d | " GRN "%9.2f $\n" NC, i, io_array[i]);
    }

    printf("------------------\n");
    printf("SUM  " CYN "%9.2f $\n" NC, sum);

    return 0;
}
// Insert an amount of money (0 to end):
// [1/5] 213
// Insert an amount of money (0 to end):
// [2/5] 34
// Insert an amount of money (0 to end):
// [3/5] 243
// Insert an amount of money (0 to end):
// [4/5] 562
// Insert an amount of money (0 to end):
// [5/5] 45
// ------------------
//  0 |    213.00 $
//  1 |     34.00 $
//  2 |    243.00 $
//  3 |    562.00 $
//  4 |     45.00 $
// ------------------
// SUM    1097.00 $