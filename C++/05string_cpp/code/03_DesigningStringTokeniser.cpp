#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORe(i, a, b) for (int i = a; i <= b; i++)

#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define FORS(i, a, b, step) for (int i = a; i < b; i += step)
#define RFORS(i, a, b, step) for (int i = a; i >= b; i -= step)

char *mystrtok(char *str, char delim) {
    //static variable to maintain state: how many token
    // have been read till now
    static char *input = NULL;

    if (str != NULL) {
        //if s is NOT NULL: we are making first call
        input = str;
    }

    //base case: after final token has been returned;
    if (input == NULL) {
        return NULL;
    }

    //start extracting tokens and store them in an array
    char *output = new char[strlen(input) + 1];
    int i = 0;
    for (; input[i] != '\0'; i++) {
        if (input[i] != delim) {
            output[i] = input[i];
        } else {
            //if we find any space or delim
            output[i] = '\0';
            input = input + i + 1; //move pointer to the next token;
            return output;
        }
    }
    // Corner Case : handle last token
    output[i] = '\0';
    input = NULL;
    return output;
}

int main() {
    char s[100] = "Today, is a rainy, day";

    char *ptr = mystrtok(s, ',');
    cout << ptr << endl;
    while (ptr != NULL) {
        ptr = mystrtok(NULL, ',');
        cout << ptr << endl;
    }
}