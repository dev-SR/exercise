#include <bits/stdc++.h>
using namespace std;
int main() {
    // The name of the array is a constant pointer to the first element.
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << a << endl;     // 0x65febffdc0
    cout << &a[0] << endl; // 0x65febffdc0
    // dereferencing like a pointer
    cout << *a << endl;       // 1
    cout << *(a + 1) << endl; // 2

    int *p = &a[0];
    cout << a << " " << &a << endl; // 0x65febffdc0 0x65febffdc0
    cout << p << " " << &p << endl; // 0x65febffdc0 0x65febffdb8
    cout << *p << endl;             // 1
    cout << *(p + 1) << endl;       // 2
    // we can use [] as well
    cout << p[1] << endl; // 2

    cout << sizeof(p) << endl; // 8 ; size of int pointer
    cout << sizeof(a) << endl; // 40 ; size of int arrary
}