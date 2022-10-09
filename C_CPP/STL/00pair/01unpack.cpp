#include <iostream>
#include <tuple>//for tie()
#include <utility>//for pair
using namespace std;

int main() {
    pair<int, int> p1(1, 2);

    int a, b;
    tie(a, b) = p1;

    cout << a << " " << b << endl; // 1 2

    return 0;
}
