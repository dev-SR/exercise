#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

void updateArrayPassByValue(array<int, 5> arr, int i, int val) {
    arr[i] = val;
}

void updateArrayPassByReference(array<int, 5> &arr, int i, int val) {
    arr[i] = val;
}

void print(const array<int, 5> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    array<int, 5> arr = {1, 2, 3, 4, 5};
    print(arr); // 1 2 3 4 5
    updateArrayPassByValue(arr, 2, 10);
    print(arr); // 1 2 3 4 5
    updateArrayPassByReference(arr, 2, 10);
    print(arr); // 1 2 10 4 5

    // sorting
    sort(arr.begin(), arr.end());
    print(arr); // 1 2 4 5 10

    // fill
    array<int, 5> arr2;
    arr2.fill(10);

    print(arr2); // 10 10 10 10 10
}