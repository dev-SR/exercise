/*
Problem Statement:
Given a Line, print that line word by word punctuation removed and each word capitalized.

In: This is a test number 9.9
OUT:
This
Is
A
Test
Number
99

 */
#include <stdio.h>
#include <string.h>
int main() {

    char s[1000], ch;
    int i, len, is_word_started = 1;
    gets(s);
    len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            // first char of the word
            if (is_word_started) {
                is_word_started = 0; // so that next char is not mark as starting char
                ch = 'A' + (s[i] - 'a');
                printf("%c", ch);
            }
            // else print as it its
            else {
                printf("%c", s[i]);
            }

        } else if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            if (is_word_started) {
                is_word_started = 1; // so that next char is not mark as starting char
                                     // no need to do anything
            }
            printf("%c", s[i]);
        }
        // WhiteSpace is found
        else {
            if (!is_word_started) {
                // Mark current character as the starting point of new word
                is_word_started = 1;
                printf("\n");
            }
        }
    }

    return 0;
}
