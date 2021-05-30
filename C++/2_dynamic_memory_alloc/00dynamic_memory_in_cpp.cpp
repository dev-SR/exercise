#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"

void display(int *p, int n) {
    for (int i = 0; i < n; i++) {
        cout << p[i];
    }
}

int main() {
    int n;
    cin >> n;

    //allocate memory
    // int *p = new int[n];
    // or,
    int *p{new int[n]};

    for (int i = 0; i < n; i++) {
        cout << "el:";
        cin >> p[i];
    }
    display(p, n);

    //deallocate memory
    delete[] p;
    return 0;
}