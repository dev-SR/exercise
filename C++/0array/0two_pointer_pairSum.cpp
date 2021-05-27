#include <bits/stdc++.h>
using namespace std;
// Given a sorted array, Find Pair of Element that sum to K(Given)
int main() {
    int n, key;
    int a[] = {1, 3, 5, 7, 10, 11, 12, 13};
    int s = 16;

    // cin >> n;
    // for (int i = 0; i < n; i++) {
    //     cin >> a[i];
    // }

    int i = 0;
    int j = sizeof(a) / sizeof(int) - 1;
    // int j = sizeof(a) / sizeof(a[0]) - 1;

    while (i < j) {
        int cs = a[i] + a[j];
        if (cs > s) {
            j++;
        } else if (cs < s) {
            i++;
        } else if (cs == s) {
            cout << a[i] << " and " << a[j] << endl;
            i++;
            j--;
        }
    }
}