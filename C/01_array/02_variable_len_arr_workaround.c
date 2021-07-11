#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

#define LEN 5

void array_maker(int len) {
    int vla[len];

    for (int i = 0; i < len; i++) {
        vla[i] = i;
    }
    printf(GRN);
    for (int i = 0; i < len; i++) {
        printf("%d ", vla[i]);
    }
    printf(NC);
}

int main() {
    printf(GRN "=== Variable Length Arrays ===\n" NC);
    while (1) {
        int len;
        printf("\nEnter the len: ");
        scanf("%d", &len);

        if (len < 1) {
            printf(RED "exit!!" NC);
            break;
        }
        array_maker(len);
    }
}
// Enter the len: 5
// 0 1 2 3 4
// Enter the len: 1
// 0
// Enter the len: 3
// 0 1 2
// Enter the len: 0
// exit!!