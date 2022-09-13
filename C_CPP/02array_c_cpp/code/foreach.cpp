#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    for (auto &i : arr) // `&` is required, otherwise `i` makes new copy, not reference
        if (i % 2 == 0)
            i = 0;

    for (const auto &i : arr) // reference to avoid copy
        cout << i << endl;
    return 0;
}