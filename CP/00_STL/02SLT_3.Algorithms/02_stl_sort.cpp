#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"

bool compare(int a, int b) {
    cout << "Comparing " << a << " and " << b << endl;
    return a > b;
}
int main() {
    int n, key;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, compare);

    for (int i = 0; i < n; i++) {
        cout << a[i] << ", ";
    }
    return 0;
}