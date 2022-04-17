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
    int a = 5;
    int b = 3;
    cout << (a << b) << endl; //(lelfshift) a<<b=a*2^b =  5*2^3 = 5*8 = 40
    cout << (a >> b) << endl; //(rightshift) a>>b=a/2^b =  5/2^3 = 5/8 = 0
}