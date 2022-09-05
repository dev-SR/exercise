#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[] = {1, 2, 3};
    char b[] = "abc";

    cout << a << endl; //   0x61fdfc
    //* Watch Out the Difference from an Array.
    // cout prints all the elements from the string until it founds null character
    cout << b << endl; //!  abc

    int i = 10;
    int *p = &i;
    char *c = &b[0];
    //Also, character pointer doesn't print address but prints all the el it points to.
    cout << c << endl;  //!  abc
    cout << *c << endl; //!  a
    cout << p << endl;  //   0x61fdec
    cout << *p << endl; //   10

    char c1 = 'x';
    char *pc = &c1;
    cout << c1 << endl; //a
    cout << pc << endl; //a☺?
    //Though with a single character it also print everything 
    // until a null character is found , but this time with 
    //some garbage characters after the character..
    cout << "end" << endl;
    char str[] = "xyz"; //recommended
    char *pstr = "xyz"; //must be avoided
}   

