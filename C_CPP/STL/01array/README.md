# array in C++ vs STL

- [array in C++ vs STL](#array-in-c-vs-stl)

```cpp
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
	//size 🌟
    int n = sizeof(arr) / sizeof(arr[0]);//sizeof(int)
    print(arr, n); // 1 2 3 4 5
    // actual array is updated.
    updateArray(arr, 2, 10);
    print(arr, n); // 1 2 10 4 5

    // 🌟sorting
    sort(arr, arr + n);
    print(arr, n); // 1 2 4 5 10
}
```

vs

```cpp
void updateArrayPassByValue(array<int, 5> arr, int i, int val) {
    arr[i] = val;
}

void updateArrayPassByReference(array<int, 5> &arr, int i, int val) {
    arr[i] = val;
}

void print(const array<int, 5> &arr) {
	//size 🌟
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

    // 🌟sorting
    sort(arr.begin(), arr.end());
    print(arr); // 1 2 4 5 10

    // 🌟fill
    array<int, 5> arr2;
    arr2.fill(10);

    print(arr2); // 10 10 10 10 10
}
```
