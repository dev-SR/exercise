#include <algorithm> //  sort
#include <iostream>
using namespace std;
void show(int a[], int array_size) {
    for (int i = 0; i < array_size; ++i)
        cout << a[i] << " ";
    cout << endl;
}
int main() {
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *first = arr;
    int *last = arr + n;
    //`arr` is address of first element, `arr+n` is address of last element
    sort(first, last);
    show(arr, n);
    sort(first, last, greater<int>());
    show(arr, n);

    return 0;
}