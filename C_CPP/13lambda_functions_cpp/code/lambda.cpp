#include <iostream>
using namespace std;

int main() {

    auto func = []() -> void {
        cout << "Hello World" << endl;
    };
    func();

    /* Call lambda directly after definiton */

    []() {
        cout << "Hello World" << endl;
    }();

    /* Lambda with parameters +return */
    auto res = [](int a, int b) -> int { return a + b; }(10, 20);
    cout << res << endl; // 30

    // inline with cout
    cout << [](int a, int b) { return a * b; }(2, 2) << endl; // 4

    int a = 10;
    int b = 20;

    auto cap = [a, b]() {
        cout << a << " " << b << endl; // 10 20
    };
    cap();

    int c = 0;
    auto cap_by_value = [c]() {
        cout << "Inner: " << c << endl;
    };
    for (int i = 0; i < 3; i++) {
        cout << "Outer: " << c << endl;
        cap_by_value();
        ++c;
    }

    c = 0;
    auto cap_by_ref = [&c]() {
        cout << "Inner: " << c << endl;
    };
    for (int i = 0; i < 3; i++) {
        cout << "Outer: " << c << endl;
        cap_by_ref();
        ++c;
    }

    int i=0, j=0, k = 0;

    // capture everything by value
    auto cap_all_by_value = [=]() {
        cout << i << " " << j << " " << k << endl;
    };
    // capture everything by ref
    auto cap_all_by_ref = [&]() {
        cout << i << " " << j << " " << k << endl;
    };

    for (int a = 0; a < 3; a++) {
        cout << "Outer: " << i << " " << j << " " << k << endl;
        cap_all_by_value();
        cap_all_by_ref();
        ++i;
        ++j;
        ++k;
    }

    return 0;
}