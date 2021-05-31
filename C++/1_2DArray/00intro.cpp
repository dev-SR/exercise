#include <bits/stdc++.h>
using namespace std;
int main() {

    //2D arrays Deceleration/Initialization:
    int ar1[2][3];
    int ar2[2][3] = {{1, 2, 3}, {3, 4, 5}};
    int ar3[][3] = {{1, 2, 3}, {3, 4, 5}};
    char ar4[3][2] = {{'A', 'B'}, {'C', 'D'}, {'E', 'F'}};
    char ar5[][4] = {"abc", "def", "efg", "hij"};

    cout << ar3[0][0] << endl; //1
    cout << ar3[0] << endl;    //0x61fdb0
    cout << ar4[0][0] << endl; //A
    cout << ar4[0] << endl;    //ABCDEF

    int a[100][100] = {0};
    int m, n;
    cin >> m >> n;

    for (int row = 0; row <= m - 1; row++) {
        for (int col = 0; col <= n - 1; col++) {
            cin >> a[row][col];
        }
    }
    cout << endl;
    for (int row = 0; row <= m - 1; row++) {
        for (int col = 0; col <= n - 1; col++) {
            cout << a[row][col] << " ";
        }
        cout << endl;
    }
}

//IN: 2 2

//IN: 1 2
//IN: 3 4

// 1 2
// 3 4