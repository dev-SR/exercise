#include <bits/stdc++.h>
using namespace std;

int main() {
    // const pointer
    int a = 10;
    const int *p = &a;
    cout << "a = " << a << endl;   // 10
    cout << "p = " << p << endl;   // 0x7ffeeb0b9b50
    cout << "*p = " << *p << endl; // 10
    // can't modify original value through pointer
    *p = 20; // error: assignment of read-only variable 'a'
}