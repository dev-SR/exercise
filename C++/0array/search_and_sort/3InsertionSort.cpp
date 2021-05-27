//Insertion sort : Insert the current element at 'right' position

// 1. If it is the first element, it is already sorted.return 1;
// 2. Pick next element
// 3. Compare with all elements in the sorted sub - list
// 4. Shift all the elements in the sorted sub - list that is
//    greater than the value to be sorted
// 5. Insert the value
// 6. Repeat until list is sorted

#include <bits/stdc++.h>
using namespace std;
void insertion_seach(int a[], int n) {
    for (int i = 1; i < n - 1; i++) {
        int ce = a[i];
        //pleace 'current element' at the right postition in
        // sorted part
        int j = i - 1;
        while (j >= 0 and a[j] > ce) {
            //shift right all the el than matches condition
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = ce;
    }
}

int main() {
    int n, key;
    cin >> n;
    int a[100];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    insertion_seach(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " , ";
}
