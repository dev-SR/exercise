#include <bits/stdc++.h>
using namespace std;
// {0,0} {0,1} {0,2}    :[0-2][j=i ->j++]
// {1,1} {1,2}          :[1-2][j=i ->j++]
// {2,2}                :[2-2][j=i ->j++]

void printSubString(char *a) {
    for (int i = 0; a[i] != '\0'; i++) {
        for (int j = i; a[j] != '\0'; j++) {
            cout << "printing in range :{" << i << "," << j << "}"
                 << " -> ";
            //Print all the chars from i to j
            for (int k = i; k <= j; k++) {
                cout << a[k];
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    char str[4] = "abc";
    printSubString(str);
}