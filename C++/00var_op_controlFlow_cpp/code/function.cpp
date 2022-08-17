#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

// Forward Declarations
void printNumber(int n);

int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

/**
 * nCk = n! / (k! * (n-k)!)
 */
int binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int defaultParam(int n = 5) {
    cout << "n = " << n << endl;
    return 0;
}

int main() {
    printNumber(5);
    cout << binomialCoefficient(5, 2); // 10
    defaultParam();                    // n=5
    defaultParam(10);                  // n=10
    return 0;
}

// Declaration + Definition
void printNumber(int n) {
    cout << n << endl;
}
