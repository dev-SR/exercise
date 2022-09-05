#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
#include <stdlib.h>
#include <string.h>

/**
 * === Get The Line === 
 *
 *  Implement a function that acquires a line from the console and 
 *  has this prototype:
 *
 *    int get_line(char dst[], int size)
 * 
 * Goals:
 *  - don't use scanf!
 *  - acquire a string up to the newline character
 *  - always put a null character at the end of the buffer
 *  - truncate the acquisition to leave space at the end of the buffer for the 
 * 	  null character
 *  - return the number of characters acquired, excluding the null character
 *  - implement a main loop that asks the user to insert a line, acquire it and
 *    print it
 *  - terminate the main loop when the user enters "END"
 * 
 */

#define BUF_SIZE 100

void clear_stdin() {
    int c = ' ';
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

int get_line(char dst[], int size) {
    int i;
    for (i = 0; i < size - 1; i++) {
        int c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        } else {
            dst[i] = (char)c;
        }
    }
    if (i == size - 1) {
        clear_stdin();
    }
    dst[i] = '\0';
    return i;
}

int main() {
    printf("\n=== Get The Line ===\n\n");

    char buffer[BUF_SIZE];

    do {
        printf("Enter a line:\n");
        int n = get_line(buffer, BUF_SIZE);
        printf(GRN "[%d] %s\n" NC, n, buffer);
    } while (strcmp(buffer, "END"));

    printf("\n\n=== ByteGarage ===\n\n");
    return 0;
}
/* 
Enter a line:
Hello World
[11] Hello World
Enter a line:   
This is a sentence.
[19] This is a sentence.
Enter a line:
*/