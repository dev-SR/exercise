# STL: Standard Template Library

- [STL: Standard Template Library](#stl-standard-template-library)
  - [Intro](#intro)
    - [Containers in STL](#containers-in-stl)
    - [Iterators](#iterators)
  - [array in C++ vs STL](#array-in-c-vs-stl)
  - [vector](#vector)
    - [initialize](#initialize)

## Intro

STL is an acronym for standard template library. It is a set of C++ template classes that provide generic classes and function that can be used to implement data structures and algorithms .STL is mainly composed of :

- Algorithms
- Containers
- Iterators

### Containers in STL

**Sequence Containers:** implement data structures which can be accessed in a sequential manner.

- `vector`
- `list`
- `dequeue`
- `arrays`
- `forward list`

**Container Adaptors :** provide a different interface for sequential containers.

- `queue`
- `priority_queue`
- `stack`

**Associative Containers :** implement sorted data structures that can be quickly searched ( O(log(n)) complexity)

- `set`
- `multiset`
- `map`
- `multimap`

**Unordered Associative Containers**: implement unordered data structures that can be quickly
searched

- `unordered set`
- `unordered multiset`
- `unordered map`
- `unordered multimap`

### Iterators

Iterators as an entity that helps us to access the data within a container with certain
restrictions.

**Input Iterators:**

A entity through which you can read data from container and move ahead.
For example - A Keyboard

**Output Iterators:**

A entity through which you can write into the container and move ahead.

**Forward Iterators:**

Iterator with functionalities of input and output iterator in single direction.
For Example - Singly Linked List

**Bidirectional Iterators:**

Forward Iterator that can move in both directions.

**Random Access Iterators:**

Random Access Iterator is an iterator that can read/write in both directions and also can take
jumps.

## array in C++ vs STL

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

## vector

- Dynamic arrays with the ability to resize itself automatically when an element is inserted
- Contiguous store locations, reallocation happens when
underlying array is full.

Methods:

- **`[]`**
- `at()`
- `back()`
- `begin()`
- `capacity()`
- **`pop_back()`**
- **`push_back()`**
- **`reserve()`**
- `resize()`
- **`size()`**
- **`clear()`**
- `empty()`
- `end()`
- `erase()`
- `front()`
- `insert()`

### initialize

```cpp
    // empty container constructor
    vector<int> v1;
    // fill constructor (4 int with value 10)
    vector<int> v2(4, 10);

    // range constructor
    int n[] = {1, 2, 3, 4};
    vector<int> v3(n, n + 4);

    // copy constructor
    vector<int> v4(v3);

    // assignment operator
    vector<int> v5;
    v5 = v3;

    // initializer list constructor
    vector<int> v6{1, 2, 3, 4};
    print(v6);

    // Another way
    vector<int> v7 = {1, 2, 3, 4};
    print(v7);
```


