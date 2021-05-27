#include <bits/stdc++.h>
using namespace std;

void spiralPrint(int a[100][100], int m, int n) {
    int startRow = 0;
    int startCol = 0;
    int endRow = m - 1;
    int endCol = n - 1;
    /**
 * 
 *      sc⇢       ⇠ec
 *  sr⇣ | --------- |
 *      |           |
 *      |           |
 *      |           |
 *  er⇡ | --------  |
*/
    //Print
    while (startRow <= endRow and startCol <= endCol) {
        //⇢
        for (int i = startCol; i <= endCol; i++) {
            cout << a[startRow][i] << " ";
        }
        startRow++;

        //⇣
        for (int i = startRow; i <= endRow; i++) {
            cout << a[i][endCol] << " ";
        }
        endCol--;

        //⇠
        for (int i = endCol; i >= startCol; i--) {
            cout << a[endRow][i] << " ";
        }
        endRow--;

        //⇡
        for (int i = endRow; i >= startRow; i--) {
            cout << a[i][startCol] << " ";
        }
        startCol++;
    }
}

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
    cout << "output:" << endl;

    spiralPrint(a, m, n);
}

/**
3 3
1 2 3
4 5 6
7 8 9
output:
1 2 3 6 9 8 7 4 5 
*/