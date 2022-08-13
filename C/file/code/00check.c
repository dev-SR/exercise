#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fp;
    fp = fopen("x.txt", "r");
    if (!fp) {
        perror("Error "); // Error : No such file or directory
        return EXIT_FAILURE;
    }
    return 0;
}