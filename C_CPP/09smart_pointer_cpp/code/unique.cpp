#include <iostream>
#include <memory>
using namespace std;

int main() {
    unique_ptr<int> x(new int);

    *x = 5;
    cout << "Value: " << *x << endl;                 // Value: 5
    cout << "Address of pointer: " << &x << endl;    // Address of pointer: 0x301a5ff5e8
    cout << "Value: " << *x.get() << endl;           // Value: 5
    cout << "Address of value: " << x.get() << endl; // Address of value: 0x17c409840e0

    // delete x; // this is not needed, as the unique_ptr will delete the memory when it goes out of scope

    // / The following line will result in ERROR since
    // we are not allowed to copy a unique ptr
    // unique_ptr<int> ptr_copy = x;

    // The following code needs to be used to copy
    // the pointer.
    unique_ptr<int> ptr_copy = std::move(x);
    cout << *ptr_copy << endl;      // 5
    cout << ptr_copy.get() << endl; // 0x7ffeeb2b8b0c
    cout << x.get() << endl;        // 0 | `x is now a nullptr`

    return 0;
}