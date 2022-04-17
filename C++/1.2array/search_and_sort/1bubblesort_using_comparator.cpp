#include <bits/stdc++.h>
using namespace std;

//allow bubble_sort to sort in desc order.
bool compare(int a, int b) {
    cout << endl;
    cout << "Comparing " << a << " and " << b << endl;
    return a < b;
}
void bubble_sort(int a[], int n) {
    //large element to the end
    for (int itr = 1; itr <= n - 1; itr++) {
        //Pairwise swapping in the unsorted array
        // upto (n-itr-1) as large elment will be in the end;
        for (int i = 0; i <= (n - itr - 1); i++) {
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        }
    }
}

//* Function pointer as _arg allowing bubble_sort() to receive a function.
void bubble_sort(int a[], int n, bool (&cmp)(int a, int b)) {
    for (int itr = 1; itr <= n - 1; itr++) {
        for (int i = 0; i <= (n - itr - 1); i++) {
            if (cmp(a[i], a[i + 1])) //calling cmp function
                swap(a[i], a[i + 1]);
        }
    }
}
int main() {
    int n, a[100];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    bubble_sort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    //passing function as param
    bubble_sort(a, n, compare);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}