//C++
#include <bits/stdc++.h>
using namespace std;
//Define a comparator function
bool compare(int a, int b) {
    cout << "comparing " << a << " and " << b << endl;
    return a > b;
}

int main() {
    int n, key;
    cin >> n;
    int a[100];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    //Sort an array using sort() function
    /**
     * @param sort(s,e)  where [s,e)
     * */

    sort(a, a + n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " , ";

    cout << endl;

    /**
     * @param sort(s,e,comarator_function)
     * */
    //desc order
    sort(a, a + n, compare);
    for (int i = 0; i < n; i++)
        cout << a[i] << " , ";
}