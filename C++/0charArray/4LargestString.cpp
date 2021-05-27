#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    char a[1000];
    char largest[1000];
    int len = 0;
    int largest_len = 0;

    //IF INPUT:
    // 3'\n'
    // abc
    // abcdddd -> terminates here at 2nd time instead of 3rd

    //because after cin ->3, getline reads \n as the first string
    //HACK!!
    cin.get(); // consume '\n'

    for (int i = 0; i < n; i++) {
        cin.getline(a, 1000);
        len = strlen(a);
        if (len > largest_len) {
            largest_len = len;
            strcpy(largest, a);
        }
    }
    cout << endl
         << largest << " len: " << largest_len << endl;
}

// 3
// abc
// abcdddd
// aa
// abcdddd len: 7