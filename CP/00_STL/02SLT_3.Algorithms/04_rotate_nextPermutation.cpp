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
    cout << GRN << setfill('*') << setw(20) << "*" << reset;
    cout << YEL << " rotate() " << reset;
    cout << GRN << setfill('*') << setw(20) << "*" << reset << endl;
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(int);
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    //! rotate(s,m,e);
    rotate(arr, arr + 2, arr + n);

    for (int i : arr) {
        cout << i << " ";
    }

    cout << endl;
    cout << RED << "with vector()" << reset << endl;
    vector<int> v{10, 20, 30, 40, 50};
    for (int i : v)
        cout << i << " ";
    cout << endl;

    rotate(v.begin(), v.begin() + 3, v.end());
    for (int i : v)
        cout << i << " ";

    cout << endl;
    cout << GRN << setfill('*') << setw(20) << "*" << reset;
    cout << YEL << " next_permutation() " << reset;
    cout << GRN << setfill('*') << setw(20) << "*" << reset << endl;
    vector<int> v1{1, 2, 3};
    for (int i : v1)
        cout << i << " ";

    cout << endl;
    next_permutation(v1.begin(), v1.end());
    for (int i : v1)
        cout << i << " ";

    return 0;
}
/* 
******************** rotate() ********************
10 20 30 40 50
30 40 50 10 20
with vector()
10 20 30 40 50
40 50 10 20 30
******************** next_permutation() **********
1 2 3
1 3 2
 */