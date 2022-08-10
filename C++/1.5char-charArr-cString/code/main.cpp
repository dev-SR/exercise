#include <bits/stdc++.h>
#include <cctype>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

int main() {
    // char ch = 'A';
    // char newLineChar = '\n';
    // cout << (int)ch << endl;          // 65
    // cout << (int)newLineChar << endl; // 10
    // cout << sizeof(char) << endl;     // 1
    // cout << sizeof(ch) << endl;       // 1

    // cout << "Letters" << endl;
    // for (int i = 0; i < 128; i++) {
    //     cout << i << " - " << (char)i << endl;
    // }

    // char ch;
    // ch = 'A';
    // cout << ch + 1 << endl; // 66
    // ch = ch + 1;
    // cout << ch << endl; // B
    // ch = cin.get();
    // // Testing
    // if (isupper(ch)) {
    //     cout << "Uppercase" << endl;
    // } else if (islower(ch)) {
    //     cout << "Lowercase" << endl;
    // } else if (isdigit(ch)) {
    //     cout << "Digit" << endl;
    // } else {
    //     cout << "Special character" << endl;
    // }
    // // Conversion
    // ch = toupper(ch);
    // cout << ch << endl;

    char ch = cin.get();
    int x = 0, y = 0;
    while (ch != '\n') {
        switch (ch) {
        case 'N':
            y++;
            break;
        case 'S':
            y--;
            break;
        case 'E':
            x++;
            break;

        case 'W':
            x--;
            break;
        }
        ch = cin.get();
    }
    cout << "X: " << x << " Y: " << y << endl;

    // 4cases
    if (x >= 0 && y >= 0) {
        for (int cnt = 1; cnt <= x; cnt++) {
            cout << "E";
        }
        for (int cnt = 1; cnt <= y; cnt++) {
            cout << "N";
        }
    }
    return 0;
}