#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int ar[5] = {1, 2, 3, 4, 5};
    cout << "Size in arr: " << size(ar) << endl;
    printArray(ar, size(ar));

    return 0;
}