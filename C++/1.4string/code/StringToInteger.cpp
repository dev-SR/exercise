//C++
#include <bits/stdc++.h>
using namespace std;

int main() {
    char c[10] = "1234";
    // string c = "1234";
    int n = c[0];   //49
    int zero = '0'; //48
    n = n - zero;   //1
    // fixing decimal place values
    n = n * 1000;
    cout << n << endl;

    //extracting all at once
    n = 0;
    for (int i = 0; c[i] != '\0'; i++) {
        n = n * 10 + c[i] - '0';
    }
    cout << n << endl;

    // https: //www.geeksforgeeks.org/converting-strings-numbers-cc/
    // built-in stoi and atoi
    n = atoi(c); // C,  works only for C-style strings (character array and string literal)
    cout << n << endl;
    n = stoi(c); //added in C++ , improved, works for both C++ strings and C style strings
    cout << n << endl;
}