/**
 * Given a 2D array of size N*N. Rotate the array 90 degres
 * anti-clockwisecin.ignore(numeric_limits<streamsize>::max(), '\n');
 
 * in: 
 * 4
 * 1 2 3 4
 * 5 6 7 8
 * 9 10 11 12
 * 13 14 15 16
 * 
 * out:
 * 4 8 12 16
 * 3 7 11 15
 * 2 6 10 14
 * 1 5 9  13
 * 
 * 
 approach:
 1st, Reverse arrays [with STL, without STL]:
 4 3 2 1
 8 7 6 5
 12 12 10 9
 16 15 14 13
 2nd,transpose of this array:
 We can transpose a matrix by switching its rows with its columns.
 4 8 12 16
 3 7 11 15
 2 6 10 14
 1 5 9  13
 * 
*/

#include <bits/stdc++.h>
using namespace std;
void rotate(int a[][100], int n) {
    //ROTATE without STL
    for (int row = 0; row < n; row++) {
        int start_col = 0;
        int end_col = n - 1;
        while (start_col < end_col) {
            swap(a[row][start_col], a[row][end_col]);
            start_col++;
            end_col--;
        }
    }
    //to take transpose
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                swap(a[i][j], a[j][i]);
            }
        }
    }
}

void rotate_stl(int a[100][100], int n) {
    //ROTATE with STL
    for (int i = 0; i < n; i++) {
        reverse(a[i], a[i] + n);
    }
    //to take transpose
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                swap(a[i][j], a[j][i]);
            }
        }
    }
}

int main() {
    int a[100][100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    rotate(a, n);

    cout << "Rotated Array:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}