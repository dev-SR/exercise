#include <stdio.h>
#include <string.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
/* Syntax
! `char *strtok(char *str, const char *delim)`

?- str: The string which is to be split
?- delim: The character on the basis of which the split will be done

Return value:
The function performs one split and returns a pointer to the token split up. A null pointer is returned if the string cannot be split.

* To find all possible splits of the string, based on a given delimiter,
* the function needs to be called in a loop.A sequence of calls to strtok()
* that operate on the same string  maintains a pointer that determines the 
* point from which to start  searching for the next token.

* So,In first call->
! - strtok(str) 
?On the first call to strtok() the string to be parsed should be specified in str.
* In each subsequent call->
! - strtok(NULL) 
?In each subsequent call that should parse the same string, str must be NULL.
//https://man7.org/linux/man-pages/man3/strtok.3.html
  */
int tokenize_string(char str[], const char delimiters[], int tok_max_len, char tokens[][tok_max_len]);
void print_tokens(int n_tokens, int tok_max_len, char tokens[][tok_max_len], char str[], const char delimiters[]);

int main() {
    printf(CYN "1. Extracting a single token\n" NC);
    char string[50] = "Hello world";
    // Extract the first token
    char *token = strtok(string, " ");
    printf(" %s\n", token); //printing the token

    printf(CYN "2. Extracting all possible tokens\n" NC);
    /**
 * So, strtok returns a token on each subsequent call
 * on the first call function should be passed with string argument for 's'
 * on subsequent calls we should pass the string argument as null
*/
    char s[50] = "Hello! We are learning about strtok";
    // Extract the first token
    char *tokens = strtok(s, " ");
    // loop through the string to extract all other tokens
    while (tokens != NULL) {
        printf(" %s\n", tokens); //printing each token
        tokens = strtok(NULL, " ");
    }
    printf("\n");

    printf(CYN "3. Example\n" NC);

    char str[] = "This, is a. sample-string";
    const char delimiters[] = " ,.-";
    int tok_max_len = sizeof(str);
    char tok[tok_max_len][tok_max_len], str_cpy[tok_max_len];
    strncpy(str_cpy, str, tok_max_len);

    int n_tokens = tokenize_string(str_cpy, delimiters, tok_max_len, tok);
    print_tokens(n_tokens, tok_max_len, tok, str, delimiters);

    return 0;
}
/* !!! print(int rows, int cols, char arr[rows][cols]) is not a valid declaration in C++ */
int tokenize_string(char str[], const char delimiters[], int tok_max_len, char tokens[][tok_max_len]) {
    int i;
    char *ptok = str;
    for (i = 0; ptok; i++) {
        ptok = strtok(i == 0 ? ptok : NULL, delimiters);
        strncpy(tokens[i], ptok, ptok ? tok_max_len : 0);
    }
    return i - 1;
}

void print_tokens(int n_tokens, int tok_max_len, char tokens[][tok_max_len], char str[], const char delimiters[]) {
    printf("Tokenization with delimiters: " GRN " \"%s\"\n" NC, delimiters);
    printf("%s\n", str);
    for (int i = 0; i < n_tokens; i++) {
        printf("[%d] %s\n", i, tokens[i]);
    }
}

/* 
1. Extracting a single token
 Hello
2. Extracting all possible tokens
 Hello!
 We
 are
 learning
 about
 strtok

3. Example
Tokenization with delimiters:  " ,.-"
This, is a. sample-string
[0] This
[1] is
[2] a
[3] sample
[4] string
 */