#include <stdio.h>
#include <string.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

/*
 ? String Searching and Tokenization
 *
 !  - strchr: Locate first occurrence of character in string
 !  - strstr: Locate substring
 !  - strtok: Split string into tokens
 *

 *  - Task 1: strchr
 *    Find all the occurrences of a character(`s`) in a string and print:
 ?    "This is a sample string"
 !        ^  ^   ^      ^
 *  - Task 2: strstr
 *    Find the first occurrence of a string in another string(`sample`) and print:
 ?    "This is a sample string"
 !               ------
 *
 *  - Task 3: strtok
 *    Store string tokens in a matrix and print:
 *    str: "This, is a. sample-string" , delim:" ,.-"
 ?    [0] This
 ?    [1] is
 ?    [2] a
 ?    [3] sample
 ?    [4] string
 */

int find_all_occurrences(char str[], char c, int indexes[]) {
    int found = 0;
    char *pstr = str;

    do {
        pstr = strchr(pstr, c);
        if (pstr) {
            int offset = pstr++ - str;
            // pstr++;
            /*
            char *a = "Hello";
            char *f = strchr(a, 'o');
            printf("%p\n", f);   //00405068
            printf("%p\n", a);   //00405064
            printf("%d", f - a); //4 = offset=(found_address - base_address )
            */
            indexes[found++] = offset;
        }
    } while (pstr); // while (pstr!=NULL)
    return found;
}

void print_occurrences(char str[], int occurrences_indexes[], int found) {
    char pattern[strlen(str) + 1];
    // memset() is used to fill a block of memory with a particular value.
    memset(pattern, ' ', sizeof(pattern));
    for (int i = 0; i < found; i++) {
        pattern[occurrences_indexes[i]] = '^';
    }
    pattern[sizeof(pattern) - 1] = '\0';
    printf(GRN "%s\n" NC, str);
    printf(RED "%s\n" NC, pattern);
}

/* return -1 if sub isn't in str OR the starting index of sub in str */
int find_substring(char str[], char sub[]) {
    char *psub = strstr(str, sub);
    return psub ? psub - str : -1;
}

void print_substring(char str[], char sub[], int index) {
    printf("Find substring \"%s\":\n", sub);
    printf(GRN "%s\n" NC, str);
    if (index >= 0) {
        printf(RED);
        for (int i = 0; i < index + strlen(sub); i++) {
            printf("%c", i < index ? ' ' : '-');
        }
        printf(NC);
    }
}

int main() {
    printf("\n=== String Searching  ===\n\n");

    char str[] = "This, is a. sample-string";
    int occurrences_indexes[sizeof(str)];
    char ch;
    printf("Enter a char to find in the string: ");
    scanf("%c", &ch);
    int found = find_all_occurrences(str, ch, occurrences_indexes);
    print_occurrences(str, occurrences_indexes, found);

    char substring[] = "sample";
    int index = find_substring(str, substring);
    print_substring(str, substring, index);

    return 0;
}
