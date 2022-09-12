#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int capacity = 5;
    int *arrPointer = new int[capacity];
    int entries = 0;

    while (true) {
        cout << "Enter a number: ";
        cin >> arrPointer[entries];
        if (cin.fail())
            break; // if input is not a number
        entries++;

        // if array is full, resize it
        if (entries == capacity) {
            capacity *= 2;
            // create a temp array(2x size) and copy all elements
            // delete old arr
            // Have the `arrPointer` point to the new array `temp`

            int *temp = new int[capacity];
            for (int i = 0; i < entries; i++)
                temp[i] = arrPointer[i];
            delete[] arrPointer;
            arrPointer = temp;
        }
    }

    printArr(arrPointer, entries);

    return 0;
}