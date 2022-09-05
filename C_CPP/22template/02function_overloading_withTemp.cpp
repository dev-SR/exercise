#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
// !v1
void print() {
    cout << "void"
         << "\n";
}
template <typename X>
void print(X a) {
    // Function code;
    cout << "f(X a): " << a << "\n";
}

template <typename X, typename Y>
void print(X a, Y b) //overloading function template func()
{
    cout << "f(X a,Y b): " << a << " " << b << "\n";
}

// !v2
void myPrint() {
    cout << "NOTHING HERE" << '\n';
}

template <typename T>
void myPrint(T only) {
    cout << only << '\n';
}

template <typename T, typename... Args>
void myPrint(T first, Args... rest) {
    cout << first << ' ';
    myPrint(rest...);
}

int main() {
    print();
    print(1);
    print(1, 2);

    myPrint();                 //print AT OK
    myPrint("TT");             //print TT OK
    myPrint("TT", "KK");       //print TT KK
    myPrint("TT", "KK", "JJ"); //print TT KK JJ
}