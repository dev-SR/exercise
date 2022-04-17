#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

int main() {
    int n;
    cout << sizeof(n) << endl;   // 4bytes = 32bits
    cout << sizeof(int) << endl; // 4bytes = 32bits

    cout << "Character: " << sizeof(char) << endl;          // 1byte = 8bit
    cout << "Bool: " << sizeof(bool) << endl;               // 1byte = 8bit
    cout << "Int: " << sizeof(int) << endl;                 // 4byte = 32bit
    cout << "Long: " << sizeof(long) << endl;               // 4byte = 32bit
    cout << "Long long: " << sizeof(long long) << endl;     // 8byte = 64bit
    cout << "Float: " << sizeof(float) << endl;             // 4byte = 32bit
    cout << "Double: " << sizeof(double) << endl;           // 8byte = 64bit
    cout << "Long double: " << sizeof(long double) << endl; // 16byte = 128bit
    cout << "Pointer: " << sizeof(void *) << endl;          // 8byte = 64bit

    char A = 'A';
    int AA = A;
    cout << A << endl;              // A
    cout << AA << endl;             // 65
    cout << A + 1 << endl;          // 66
    cout << AA + 1 << endl;         // 66
    cout << (char)(AA + 1) << endl; // B
    cout << (char)(A + 1) << endl;  // B

    int a = 10;
    bool aa = a;
    cout << aa << endl; // 1
    aa = "Hello";
    cout << aa << endl; // 1
    aa = "";
    cout << aa << endl; // 1
    aa = true;
    cout << aa << endl; // 1
    aa = false;
    cout << aa << endl; // 0
    aa = 0;
    cout << aa << endl; // 0

    return 0;
}