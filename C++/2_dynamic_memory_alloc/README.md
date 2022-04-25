# Dynamic Memory Allocation in C++

- [Dynamic Memory Allocation in C++](#dynamic-memory-allocation-in-c)
  - [Introduction](#introduction)
    - [`new`](#new)
      - [Initialize memory](#initialize-memory)
      - [Allocate block of memory](#allocate-block-of-memory)
    - [`delete`](#delete)
  - [One-Dimensional Array](#one-dimensional-array)
    - [ex1: manual Input](#ex1-manual-input)
    - [ex2: Random Number Generation](#ex2-random-number-generation)
  - [Two-Dimensional Array](#two-dimensional-array)

## Introduction

C++ allows us to allocate the memory of a variable or an array in run time. This is known as **dynamic memory allocation**.

In other programming languages such as Java and Python, the compiler automatically manages the memories allocated to variables. But this is not the case in C++.

In C++, we need to de-allocate the dynamically allocated memory manually after we have no use for the variable.

We can allocate and then de-allocate memory dynamically using the `new` and `delete` operators respectively.

- [https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/](https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/)

### `new`

```cpp
// Pointer initialized with NULL
// Then request memory for the variable
int *p = NULL;
p = new int;

            OR

// Combine declaration of pointer
// and their assignment
int *p = new int;
```

#### Initialize memory

We can also initialize the memory for built-in data types using new operator. For custom data types a constructor is required (with the data-type as input) for initializing the value. Here’s an example for the initialization of both data types :

`pointer-variable = new data-type(value);`

```cpp
int *p = new int(25);
float *q = new float(75.25);
// Custom data type
struct cust
{
    int p;
    cust(int q) : p(q) {}
};
cust* var1 = new cust;    // Works fine, doesn't require constructor
        //OR
cust* var1 = new cust();        // Works fine, doesn't require constructor

cust* var = new cust(25)        // Notice error if you comment this line
```

#### Allocate block of memory

new operator is also used to allocate a block(an array) of memory of type data-type.

`pointer-variable = new data-type[size];`
where size(a variable) specifies the number of elements in an array. Example:

```cpp
int *p = new int[10]
```

### `delete`

Since it is programmer’s responsibility to deallocate dynamically allocated memory, programmers are provided delete operator by C++ language.

Syntax: `delete pointer-variable;`

Here, pointer-variable is the pointer that points to the data object created by new.
Examples:

```cpp
delete p;
delete q;
```

To free the **dynamically allocated array** pointed by pointer-variable, use following form of delete:

`delete[] pointer-variable;`

Example:

```cpp
// It will free the entire array
   // pointed by p.
   delete[] p;
```

## One-Dimensional Array

### ex1: manual Input

```cpp
// allocate memory dynamically for 1d array
int *allocateMemory(int n) {
    int *arr = new int[n];
    return arr;
}
// take input
int *takeInput(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

// delete dynamically allocated 1d array
void delete1d(int *arr) {
    delete[] arr;
    cout << "Deleted !!!\n";
}

void display(int *p, int n) {
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int *p = allocateMemory(n);
    p = takeInput(p, n);
    display(p, n);
    delete1d(p);
}

```

### ex2: Random Number Generation

```cpp
// generate random array dynamically
int *generateRandomArray(int n) {
    // Use current time as seed for random generator
    srand(time(0)); // or time(NULL);
    /**
        Note: Without first calling srand(), program will create the same sequence of numbers each time it runs.
    */
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}
```

- [https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/](https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/)

## Two-Dimensional Array


```bash
       int **p = new int*[2]; <- array of Integer Pointers
             ┃
             ▼
       ┏━━━━━━┓      ┏━━━━━━━━━━━━━━━┓
       ┃ p[0] ┃----> ┃ new int[n];   ┃
       ┗━━━━━━┛      ┗━━━━━━━━━━━━━━━┛
       ┏━━━━━━┓      ┏━━━━━━━━━━━━━━━┓
       ┃ p[1] ┃----> ┃ new int[n];   ┃
       ┗━━━━━━┛      ┗━━━━━━━━━━━━━━━┛
```

```cpp
// allocate memory for 2D array
int **allocateMemory(int n, int m) {
    int **p = new int *[n];
    for (int i = 0; i < n; i++) {
        p[i] = new int[m];
    }
    return p;
}

// take input 2d array
int **takeInput(int **p, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> p[i][j];
        }
    }
    return p;
}
// delete 2d array
void delete2d(int **arr, int r) {
    // delete  allocated blocks
    for (int i = 0; i < r; i++) {
        delete[] arr[i];
    }
    // delete pointer to 2d arrays
    delete[] arr;
}
// print 2d array
int print(int **arr, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
int main() {
    int r, c;
    cin >> r >> c;
    int **p = allocateMemory(r, c);
    p = takeInput(p, r, c);
    print(p, r, c);
    delete2d(p, r);
    return 0;
}
```
