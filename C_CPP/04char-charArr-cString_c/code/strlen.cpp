#include <cstring>
#include <iostream>
using namespace std;

int main() {
    const char str[] = "Hello World";

    // arrays decay to pointers when we use char*
    const char *pStr = "Hello World";

    // strlen ignores null character
    cout << "strlen(str[]) = " << strlen(str) << endl; // strlen(str[]) = 11

    // Included the null character
    cout << "sizeof(str[]) = " << sizeof(str) << endl; // sizeof(str[]) = 12

    // strlen still works with decayed arrays
    cout << "strlen(pStr) = " << strlen(pStr) << endl; // strlen(pStr) = 11

    // prints size of pointer
    cout << "sizeof(pStr) = " << sizeof(pStr) << endl; // sizeof(pStr) = 4

    return 0;
}
