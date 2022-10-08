#include <iostream>
#include <memory>
using namespace std;

int main() {
    auto x = make_shared<int>(5);

    shared_ptr<int> y = x;
    if (x == y) {
        cout << "x and y are pointing to the same memory" << endl;
    }

    return 0;
}