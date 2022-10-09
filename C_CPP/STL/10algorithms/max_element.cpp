#include <algorithm> //  max_element
#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *first = arr;
    int *last = arr + n;
    cout << max_element(first, last) << endl;  // 0xea42fffccc **address of the max element**
    cout << *max_element(first, last) << endl; // 9
    return 0;
}