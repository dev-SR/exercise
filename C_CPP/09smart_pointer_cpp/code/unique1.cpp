#include <iostream>
#include <memory>
using namespace std;

int main() {
    unique_ptr<int> x(new int);
    *x = 5;
    unique_ptr<int> y = make_unique<int>(5); // y=5

    unique_ptr<int[]> arr(new int[5]);
    unique_ptr<int[]> arr2 = make_unique<int[]>(3); // arr2=new int[3];

    auto arr3 = make_unique<int[]>(3);

    arr[0] = 1;
    arr2[0] = 1;
    arr3[0] = 1;

    cout << "x: " << *x << endl;            // Value: 5
    cout << "y: " << *y << endl;            // Value: 5
    cout << "arr2[0]: " << arr2[0] << endl; // arr2[0]: 1
    cout << "arr[0]: " << arr[0] << endl;   // arr[0]: 1
    cout << "arr3[0]: " << arr3[0] << endl; // arr3[0]: 1

    return 0;
}