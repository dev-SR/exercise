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

    // allocate memory
    // int *p = new int[n];
    // or,
    int *p{new int[n]};

    for (int i = 0; i < n; i++) {
        cout << "el[" << i << "] :";
        cin >> p[i];
    }
    display(p, n);
}
```

### ex2: Random Number Generation

```cpp

```cpp
int *getArray(int n);
void display(int *p, int n) {
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

int main() {
    // Example: DMA and returning pointer from functions:
	int n;
	cin>>n;
    int *p = getArray(n);
    display(p, n);
    delete[] p;
    return 0;
}

int *getArray(int n) {
    int *p = new int[n];
    // Use current time as seed for random generator
    srand(time(0)); // or time(NULL);
    /**
        Note: Without first calling srand(), program will create the same sequence of numbers each time it runs.
    */
    for (int i = 0; i < n; i++) {
        p[i] = rand() % 100;
    }
    return p;
}
```

- [https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/](https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/)
