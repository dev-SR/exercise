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
    cout << RED << "swap()" << reset << endl;
    int a = 10;
    int b = 20;
    swap(a, b);
    cout << "a: " << a << ", b:" << b << endl;

    cout << RED << "min(),max()" << reset << endl;
    cout << "min: " << min(a, b) << endl;
    cout << "max: " << max(a, b) << endl;

    cout << RED << "reverse()" << reset << endl;
    int ar[] = {1, 2, 3, 4, 5};
    reverse(ar, ar + 4);
    for (int i : ar) {
        cout << i << " ";
    }

    return 0;
}