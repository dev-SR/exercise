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

    int n = 5;
    n % 2 == 0 ? cout << "Even" << endl : cout << "Odd" << endl;

    string weather = n > 20 ? "Sunny" : "Rainy";
    cout << weather << endl;

    int a, b;
    char op;
    cin >> a >> op >> b;
    switch (op) {

    case '+':
        cout << a + b << endl;
        break;
    case '-':
        cout << a - b << endl;
        break;
    case '*':
        cout << a * b << endl;
        break;
    case '/':
        cout << a / b << endl;
        break;
    default:
        cout << "Invalid operator" << endl;
    }
    return 0;
}