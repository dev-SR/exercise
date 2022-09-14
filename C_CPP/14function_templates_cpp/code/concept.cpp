#include <iostream>
using namespace std;
// syntax for concept
template <typename T>
requires integral<T>
    T addNumber(T a, T b) {
    return a + b;
}
template <typename T>
requires is_integral_v<T>
    T addNumber2(T a, T b) {
    return a + b;
}

template <integral T>
T addNumber3(T a, T b) {
    return a + b;
}

auto addNumber4(integral auto a, integral auto b) {
	return a + b;
}

template <typename T>
T addNumber5(T a, T b) requires integral<T> {
	return a + b;
}

int main() {
    cout << addNumber(1, 2) << endl;
    // cout << addNumber(1.1, 2.1) << endl; // error
	cout << addNumber2(1, 2) << endl;
	cout<< addNumber3(1, 2) << endl;
	cout << addNumber4(1, 2) << endl;
	cout << addNumber5(1, 2) << endl;

    return 0;
}