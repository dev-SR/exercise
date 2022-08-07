#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
void printArr(const vector<int> &v) {
    // Printing elements
    for (int x : v) {
        cout << x << " ";
    }
    cout << '\n';
}
int main() {
    int a = 10;
    void *aa = &a; // it is valid
    void &ar = a;  // it is not valid
    return 0;
}
