#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"

int main() {
    /**
     * setw Syntax
     * cout<< setw(n)<<value...
     * 
     * Print the next value in a field of with n aligned to the right of the field
    */
    cout << 1 << endl;
    cout << setw(5) << 1 << endl;
    cout << setw(5) << 10 << endl;
    cout << setw(5) << 90 << endl;
    cout << setw(5) << 100 << endl;
    /**
     ┌───┐───┐───┐───┐───┐
     │ 1 │   │   │   │   │
     └───┘───┘───┘───┘───┘
     ┌───┐───┐───┐───┐───┐
     │   │   │   │   │ 1 │
     └───┘───┘───┘───┘───┘
     ┌───┐───┐───┐───┐───┐
     │   │   │   │ 1 │ 0 │
     └───┘───┘───┘───┘───┘
     ┌───┐───┐───┐───┐───┐
     │   │   │   │ 9 │ 0 │
     └───┘───┘───┘───┘───┘
     ┌───┐───┐───┐───┐───┐
     │   │   │ 1 │ 0 │ 0 │
     └───┘───┘───┘───┘───┘
*/
    return 0;
}

/**
 * Output:
 
 1
    1
   10
   90
  100
*/