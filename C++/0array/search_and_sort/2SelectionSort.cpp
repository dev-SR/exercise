//Selection sort is an algorithm that selects the smallest element
//from an unsorted list in each iteration and places that element
//at the beginning of the unsorted list.

// selectionSort(array, size)
//   repeat (size - 1) times
//   set the first unsorted element as the minimum
//   for each of the unsorted elements
//     if element < currentMinimum
//       set element as new minimum
//   swap minimum with first unsorted position
// end selectionSort

#include <bits/stdc++.h>
using namespace std;
void selection_seach(int a[], int n) {
    //repeat for (n-1) times
    for (int i = 0; i < n - 1; i++) {
        //set the first unsorted element as the minimum
        int min_index = i;
        for (int j = i; j <= n - 1; j++) {
            if (a[j] < a[min_index])
                min_index = j;
        }
        //swap minimum with first unsorted position
        swap(a[i], a[min_index]);
    }
}

int main() {
    int n, key;
    cin >> n;
    int a[100];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    selection_seach(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " , ";
}
