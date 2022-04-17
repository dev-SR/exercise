#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[10];
    //The name of the array is a constant pointer to the first element.
    cout << a << endl;     //0x61fdf0
    cout << &a[0] << endl; //0x61fdf0 

    a[0] = 5;
    a[1] = 10;
    cout << *a << endl;       //5
    cout << *(a + 1) << endl; //10

    int *p = &a[0];
    cout << a << " " << &a << endl; //0x61fdf0 0x61fdf0
    cout << p << " " << &p << endl; //0x61fdf0 0x61fde8

    cout << sizeof(p) << endl; //8 ; size of int pointer
    cout << sizeof(a) << endl; //40 ; size of int arrary
}