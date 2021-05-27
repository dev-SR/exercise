#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)

int main() {
    int i, n, c, temp, left[10], right[10];

    cout << "len: " << endl;
    cin >> n;
    cout << "1. left || 2. right" << endl;
    cin >> c;
    cout << "el: ";
    switch (c) {
    case 1:
        FOR(i, 0, n) {
            cin >> left[i];
        }
        /*To left Rotate arr[] of size n by 1*/
        temp = left[0];
        FOR(i, 0, n) {
            left[i] = left[i + 1];
        }
        left[n - 1] = temp;

        cout << setw(5);
        FOR(i, 0, n) {
            cout << left[i] << " ";
        }
        cout << "<<< ";
        break;
    case 2:
        FOR(i, 0, n) {
            cin >> right[i];
        }

        /*To right Rotate arr[] of size n by 1*/
        temp = right[n - 1];

        RFOR(i, n - 1, 0) {
            right[i] = right[i - 1];
        }
        right[0] = temp;

        cout << ">>> ";
        FOR(i, 0, n) {
            cout << right[i] << " ";
        }
        break;

    default:
        break;
    }
}
