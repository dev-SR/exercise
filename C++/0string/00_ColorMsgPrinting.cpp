#include <bits/stdc++.h>
using namespace std;
//https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
int main() {
    string test = "this is testing";

    cout << setfill('*') << setw(80) << "*" << endl;

    cout << endl;
    cout << "\x1B[32m*" << setfill('*') << setw(80) << "\x1B[32m*" << endl;

    cout << endl;
    cout << "\x1B[32m*" << setfill('*') << setw(30) << "\x1B[32m*";
    cout << "\x1B[32mCOLOR";
    cout << setfill('*') << setw(30) << "\x1B[32m*" << endl;
    cout << endl;

    cout << "\x1B[31mRED" << endl;
    cout << "\x1B[31m" << test << endl;
    cout << "\x1B[31m" << test << endl;
    cout << "\x1B[31m" << test << "\033[0m" << endl;
    cout << "Back to White" << endl;

    printf("\x1B[32mGREEN\n");
    printf("\x1B[33mBLUE\n");
    printf("\x1B[34mPURPLE\n");
    printf("\x1B[35mTexting\n");
    printf("\x1B[36mTexting\n");
    printf("\x1B[36mTexting\n");
    printf("\x1B[36mTexting\n");
    printf("\x1B[37mTexting\n");
    printf("\x1B[93mTexting\n");
    printf("\033[3;42;30mTexting\n");
    printf("\033[3;43;30mTexting\n");
    printf("\033[3;44;30mTexting\n");
    printf("\033[3;104;30mTexting\n");
    printf("\033[3;100;30mTexting\n");

    printf("\033[3;47;35mTexting\n");
    printf("\033[2;47;35mTexting\n");
    printf("\033[1;47;35mTexting\n");

    return 0;
}