#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

void updateArray(int arr[], int i, int val) {
    arr[i] = val;
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n); // 1 2 3 4 5
    // actual array is updated.
    updateArray(arr, 2, 10);
    print(arr, n); // 1 2 10 4 5

    // sorting
    sort(arr, arr + n);
    print(arr, n); // 1 2 4 5 10

    return 0;
}