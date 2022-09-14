#include <iostream>
using namespace std;

template <typename T>
T maximum(T a, T b);

// template type parameter by reference
template <typename T>
const T &maximum_ref(const T &a, const T &b);

int main() {
    cout << "max(int): " << maximum(1, 2) << endl;
    cout << "max(double): " << maximum(1.1, 2.2) << endl;
    cout << "max(char): " << maximum('a', 'b') << endl;

    cout << "max_ref(int): " << maximum_ref(1, 2) << endl;
    cout << "max_ref(double): " << maximum_ref(1.1, 2.2) << endl;
    cout << "max_ref(char): " << maximum_ref('a', 'b') << endl;

    auto func = []<typename T>(T a, T b) { return a > b ? a : b; };
    cout << "max_lambda(int): " << func(1, 2) << endl;

    return 0;
}
template <typename T>
T maximum(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
const T &maximum_ref(const T &a, const T &b) {
    return a > b ? a : b;
}