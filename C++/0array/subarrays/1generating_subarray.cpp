#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a[100];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    //Generating All Subarray
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            //Elements of subarray(i,j)
            for (int k = i; k <= j; k++) {
                cout << a[k] << " ";
            }
            cout << endl;
        }
    }
}
