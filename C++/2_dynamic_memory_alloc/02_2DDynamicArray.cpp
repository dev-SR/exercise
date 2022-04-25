#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"
// allocate memory for 2D array
int **allocateMemory(int n, int m) {
    int **p = new int *[n];
    for (int i = 0; i < n; i++) {
        p[i] = new int[m];
    }
    return p;
}

// take input 2d array
int **takeInput(int **p, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> p[i][j];
        }
    }
    return p;
}
// delete 2d array
void delete2d(int **arr, int r) {
    // delete blocks of memory
    for (int i = 0; i < r; i++) {
        delete[] arr[i];
    }
    // delete pointer to 2d arrays
    delete[] arr;
}
// print 2d array
int print(int **arr, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
int main() {
    /**
       int **p = new int*[2]; <- array of Integer Pointers
             ┃
             ▼
       ┏━━━━━━┓      ┏━━━━━━━━━━━━━━━┓
       ┃ p[0] ┃----> ┃ new int[n];   ┃
       ┗━━━━━━┛      ┗━━━━━━━━━━━━━━━┛
       ┏━━━━━━┓      ┏━━━━━━━━━━━━━━━┓
       ┃ p[1] ┃----> ┃ new int[n];   ┃
       ┗━━━━━━┛      ┗━━━━━━━━━━━━━━━┛

    */
    int r, c;
    cin >> r >> c;
    int **p = allocateMemory(r, c);
    p = takeInput(p, r, c);
    print(p, r, c);
    delete2d(p, r);
    return 0;
}