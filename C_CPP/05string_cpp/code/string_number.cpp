#include <iostream>
using namespace std;

int main() {

    string price = "123.45";
    double price_d = stod(price);
    cout << price_d + 1 << endl; // 124.45

    string price2 = "123.x45";
    double price2_d = stod(price2);
    cout << price2_d << endl; // 123

    int i = 123;
    string s = to_string(i);
    cout << s.insert(0, "N: ") << endl; // N: 123

    return 0;
}