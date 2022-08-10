#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

int main() {
    // char[] vs string traversal
    char s[] = "hello";
    for (int i = 0; i < strlen(s); i++) {
        cout << s[i] << " ";
    }
    cout << endl;
    // or
    for (int i = 0; i < s[i] != '\0'; i++) {
        cout << s[i] << " ";
    }
    cout << endl;

    string s1 = "hello";
    for (int i = 0; i < s1.length(); i++) {
        cout << s1[i] << " ";
    }
    cout << endl;
    // using for each loop
    for (char c : s1) {
        cout << c << " ";
    }
    cout << endl;
    // using iterators
    for (auto it = s1.begin(); it != s1.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;
    cout << "-> Modifing Without reference: for(char c:s)  " << endl;
    for (char c : s1) {
        if (c >= 'a') {
            c -= 32;
        }
        cout << c << " "; // H E L L O
    }
    cout << endl;
    cout << "After Modification:" << endl;
    for (char c : s1) {
        cout << c << " "; // h e l l o
    }
    cout << endl;
    cout << "-> Modifing With Reference: for(char &c:s)" << endl;
    for (char &c : s1) {
        if (c >= 'a') {
            c -= 32;
        }
        cout << c << " "; // H E L L O
    }
    cout << endl;
    cout << "After Modification:" << endl;
    for (char c : s1) {
        cout << c << " "; // H E L L O
    }
    /**
     * See reference in c++: https://www.geeksforgeeks.org/references-in-c/ , how its used In For Each Loops to modify all objects
     */

    return 0;
}