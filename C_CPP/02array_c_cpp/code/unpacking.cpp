#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[3] = {1, 2, 3};

    auto [x, y, z] = arr; // type must be 'auto'
    cout << x << y << z << endl;

    // auto [a, b] = arr; // Error| number of unpacking element must be equal to number of array element
    // cout << a << b << endl;
    return 0;
}