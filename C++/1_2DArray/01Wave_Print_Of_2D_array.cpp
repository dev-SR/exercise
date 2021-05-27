#include <bits/stdc++.h>
using namespace std;

/**
 *  
 * ⇣1  ⇡2  ⇣3  ⇡4
 * ⇣5  ⇡6  ⇣7  ⇡8 
 * ⇣9  ⇡10 ⇣12 ⇡12
 * ⇣13 ⇡14 ⇣15 ⇡16
 * 
 * *output: 1 5 9 13 ⤑ 14 10 6 2 ⤑ 3 7 12 15 ⤑16 12 8 4 
*/

int main() {

    int a[100][100] = {0};
    int m, n;
    cin >> m >> n;
    int val = 1;
    for (int row = 0; row <= m - 1; row++) {
        for (int col = 0; col <= n - 1; col++) {
            a[row][col] = val;
            val++;
            cout << a[row][col] << " ";
        }
        cout << endl;
    }
    //WAVE PRINT
    //if    col is  even ⤑ Top Down
    //              odd ⤑ Bottom UP
    for (int col = 0; col < n; col++) {
        if (col % 2 == 0) {
            //EVEN COL: Top Down
            for (int row = 0; row < m; row++) {
                cout << a[row][col] << " ";
            }
            cout << "> ";
        } else {
            //Bottom UP Direction
            for (int row = m - 1; row >= 0; row--) {
                cout << a[row][col] << " ";
            }
            cout << "> ";
        }
    }
}