#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(char a[]) {
    int i = 0;
    int j = strlen(a) - 1;
    while (i < j) {
        if (a[i] == a[j]) {
            i++;
            j--;
        } else
            return false;
    }
    return true;
}

int main() {
    char a[100];
    cin.getline(a, 100);
    if (isPalindrome(a)) {
        cout << "Palindrome String" << endl;
    } else
        cout << "Not Palindrome String" << endl;
}
/**
 * OUTPUT: 
 * 
 * abcba
 * Palindrome String  
*/