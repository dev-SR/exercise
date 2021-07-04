#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"

template <typename T>
T myMax(T x, T y) {
    return (x > y) ? x : y;
}

int main() {
    cout << myMax<int>(3, 7) << endl;        // Call myMax for int
    cout << myMax<double>(3.0, 7.0) << endl; // call myMax for double
    cout << myMax<char>('g', 'e') << endl;   // call myMax for char
    return 0;
}