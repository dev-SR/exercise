#include <bits/stdc++.h>
using namespace std;

// Function to print an array

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void countSort(int array[], int n) {
    int output[10];
    int count[10];
    int max = array[0];

    //! Find the largest element of the array
    for (int i = 1; i < n; i++) {
        if (array[i] > max)
            max = array[i];
    }

    //! Initialize count array with all zeros.
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
        output[i] = 0;
    }

    //! Frequency Count
    for (int i = 0; i < n; i++) {
        count[array[i]]++;
    }
    cout << "count : ";
    for (int i = 0; i <= max; i++) {
        cout << count[i] << " ";
    }
    cout << endl;

    //! Store the cumulative count of Freq. Count array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    cout << "presum: ";
    for (int i = 0; i <= max; i++) {
        cout << count[i] << " ";
    }
    cout << endl
         << endl;

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = n - 1; i >= 0; i--) {
        // cout << i << endl;
        // cout << "array     : ";
        // printArray(array, n);
        // cout << "count_pre : ";
        // printArray(count, max);
        // cout << "    ar[" << i << "] : " << array[i] << endl;
        // cout << " count[" << array[i] << "] : " << count[array[i]] << endl;

        // output[count[array[i]]-1] = array[i];
        // count[array[i]]--;
        // OR,>
        output[--count[array[i]]] = array[i];

        // cout << "output[" << count[array[i]] << "] = "
        //      << "ar[" << i << "] || " << output[count[array[i]]] << endl;
        // cout << "result[]  : ";
        // printArray(output, n);
        // cout << "count_post: ";
        // printArray(count, max);
        // cout << endl;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < n; i++) {
        array[i] = output[i];
    }
}

// Driver code
int main() {
    int array[] = {1, 3, 5, 3, 10, 7, 3, 5, 1};
    int n = sizeof(array) / sizeof(array[0]);
    cout << "arr   : ";
    printArray(array, n);
    countSort(array, n);
    cout << "result: ";
    printArray(array, n);
}