#include <bits/stdc++.h>
using namespace std;
// Function to reverse a string
void reverseStr(string &str) {
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

// Driver program
int main() {
    string str = "Hello World";
    reverseStr(str);
    cout << str << endl;

    //Using inbuilt “reverse” function
    reverse(str.begin(), str.end());
    cout << str << endl;

    // Reverse string using the constructor
    string rev = string(str.rbegin(), str.rend());

    cout << rev << endl;
    return 0;
}