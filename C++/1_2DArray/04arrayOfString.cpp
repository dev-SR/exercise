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
    //with 2D array
    char ar[3][20] = {"Hello World", "Welcome", "Bye Bye"};
    for (int i = 0; i < 3; i++) {
        cout << ar[i] << endl;
    }
    //with String class:
    string names[] = {"Soikat Rahman", "Never ever"};
    for (int i = 0; i < 2; i++) {
        cout << names[i] << endl;
    }

    int n;
    cin >> n;
    cin.ignore(); //to ignore the enter after n;

    char a[10][100];
    for (int i = 0; i < n; i++) {
        cin.getline(a[i], 100);
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }

    // Search
    char key[100];
    cout << CYN << "Enter string to search: " << reset << endl;
    cin.getline(key, 100);
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(key, a[i]) == 0) {
            cout << "Found at:" << i + 1 << endl;
            break;
        }
    }
    if (i == n) {
        cout << "Not found!";
    }

    return 0;
}