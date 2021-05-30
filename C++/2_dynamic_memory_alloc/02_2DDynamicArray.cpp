#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"

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
    //Create an array of row heads/ array of pointers
    int **p = new int *[r];

    //create an 2D array
    for (int i = 0; i < r; i++) {
        p[i] = new int[c];
    }

    //take input:
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> p[i][j];
        }
    }

    //print
    //take input:
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << GRN << p[i][j] << " ";
        }
        cout << endl;
    }
    //delete 2d arrays
    for (int i = 0; i < r; i++) {
        delete[] p[i];
    }
    //delete array of pointers
    delete[] p;

    return 0;
}