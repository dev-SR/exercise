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

    //2D arrays Deceleration/Initialization:
    int ar1[2][3];
    int ar2[2][3] = {{1, 2, 3}, {3, 4, 5}};
    int ar3[][3] = {{1, 2, 3}, {3, 4, 5}};
    char ar4[3][2] = {{'A', 'B'}, {'C', 'D'}, {'E', 'F'}};
    char ar5[][4] = {{'A', 'B', '\0'}, {'C', 'D', '\0'}, {'E', 'F', '\0'}};
    char ar6[][4] = {"abc", "def", "efg", "hij"};

    cout << CYN << "ar3[0][0]: " << reset << ar3[0][0] << endl; //1
    cout << CYN << "ar3[0]   : " << reset << ar3[0] << endl;    //0x61fdb0
    cout << CYN << "ar4[0][0]: " << reset << ar4[0][0] << endl; //A
    cout << CYN << "ar4[0]   : " << reset << ar4[0] << endl;    //ABCDEF
    cout << CYN << "ar5[0]   : " << reset << ar5[0] << endl;    //AB
    cout << CYN << "ar6[0]   : " << reset << ar6[0] << endl;    //abc

    //So, Creating

    /**
    {{'A', 'B', '\0'}, {'C', 'D', '\0'}, {'E', 'F', '\0'}};
       ┏━━━┓━━━┓━━━┓     
       ┃ A ┃ B ┃\0 ┃
       ┗━━━┛━━━┛━━━┛
       ┏━━━┓━━━┓━━━┓     
       ┃ C ┃ D ┃\0 ┃
       ┗━━━┛━━━┛━━━┛     
    {"abc", "def", "efg", "hij"};
       ┏━━━┓━━━┓━━━┓━━━┓      
       ┃ a ┃ b ┃ C ┃\0 ┃
       ┗━━━┛━━━┛━━━┛━━━┛
       ┏━━━┓━━━┓━━━┓━━━┓      
       ┃ d ┃ e ┃ f ┃\0 ┃
       ┗━━━┛━━━┛━━━┛━━━┛
       ┏━━━┓━━━┓━━━┓━━━┓      
       ┃ e ┃ f ┃ g ┃\0 ┃
       ┗━━━┛━━━┛━━━┛━━━┛       
   */

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