# Array

- [Array](#array)
  - [Creating Array](#creating-array)
  - [Working with Array](#working-with-array)
  - [Array and Pointer](#array-and-pointer)
  - [Passing Array To a Function](#passing-array-to-a-function)
    - [🎗️🎗️🎗️ C/CPP ✂️modifies✂️ Original array | Pass By Reference/Address](#️️️-ccpp-️modifies️-original-array--pass-by-referenceaddress)
      - [🧠🧠 Arrays are passed by References only; 🧠🧠But Others are by Value🧠🧠](#-arrays-are-passed-by-references-only-but-others-are-by-value)
    - [🌟🌟🌟Returning (Local) Array From the Function in C/C++ | `int* fn(){} ~ int *p = fn()`](#returning-local-array-from-the-function-in-cc--int-fn--int-p--fn)
    - [Enabling Pass by Value in C/CPP](#enabling-pass-by-value-in-ccpp)
    - [Example](#example)
      - [Partial Array Processing](#partial-array-processing)
      - [sorting](#sorting)
      - [Find all occurrences](#find-all-occurrences)

## Creating Array

```cpp
int a =100
int a{100} //single integer of value 100

//array of 100 integers
int a[100];
int a[100] = {5}; //C style; first number is 5, rest are 0
int a[100] = {1,2,3}; // 1 2 3 0 0 0 0 0 0 0.....

//auto size
int a[] = {1,2,3};
int a[]{1, 2, 3};

//array of strings
string fruits[4] = {"Apple", "Banana", "Orange"};
```

## Working with Array

```cpp
int main() {
    int marks[100] = {0};

    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    // Assign a value
    marks[0] = -1;

    // Input
    for (int i = 1; i <= n; i++) {
        cout << "Enter the marks of student " << i << ": ";
        cin >> marks[i];
    }

    // Output
    for (int i = 1; i <= n; i++) {
        cout << "Student " << i << " marks: " << marks[i] << endl;
    }
    return 0;
}
```

## Array and Pointer

 The `name` of the array is a `constant pointer` to the `first` element.

```cpp
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << a << endl;     // 0x65febffdc0
    cout << &a[0] << endl; // 0x65febffdc0
    // dereferencing like a pointer
    cout << *a << endl;       // 1
    cout << *(a + 1) << endl; // 2
```

using `p` as a pointer to the first element of the array `a`:

```cpp
    int *p = &a[0];
    cout << a << " " << &a << endl; // 0x65febffdc0 0x65febffdc0
    cout << p << " " << &p << endl; // 0x65febffdc0 0x65febffdb8
    cout << *p << endl;             // 1
    cout << *(p + 1) << endl;       // 2
    // we can use [] as well
    cout << p[1] << endl;      // 2

    cout << sizeof(p) << endl; // 8 ; size of int pointer
    cout << sizeof(a) << endl; // 40 ; size of int array
```

## Passing Array To a Function

- [https://www.codingninjas.com/blog/2021/08/31/passing-arrays-to-functions-in-c-c/](https://www.codingninjas.com/blog/2021/08/31/passing-arrays-to-functions-in-c-c/)
- [https://www.scaler.com/topics/passing-array-to-function-in-c-cpp/](https://www.scaler.com/topics/passing-array-to-function-in-c-cpp/)
- [https://www.geeksforgeeks.org/return-local-array-c-function/](https://www.geeksforgeeks.org/return-local-array-c-function/)

**A whole array cannot be passed as an argument to a function in C++**. You can, however, pass a `pointer` to an array without an index by specifying the **array’s name**.

```kotlin
int fun(int a[]) {
    cout << sizeof(a) << endl;  // 8 -> 'a' is effectively a pointer
    cout << *a << endl;         // 1
    cout << *(a + 1)<< endl;    // 2
    return 0;
}
int fun2(int *a) {
    cout << sizeof(a) << endl;              // 8
    cout << *a << endl;                     // 1
    cout << *(a + 1) << endl;               // 2
    cout << a[0] << endl;                   // 1
    return 0;
}

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    cout << sizeof(a) << endl;              // 20
    fun(a);
    fun2(a);
}
```

> Note that `a[]` for fun() is just a `pointer` even if square brackets are used as the name of an array acts as a special kind of variable -- a `pointer` -- which stores the starting address of the array.

**Points to remember:**

- Passing arrays to functions in C/C++ are **passed by reference**. Even though we do not create a reference variable, **the compiler passes the pointer to the array**, _making the original array available** for the called function’s use_. **Thus, if the function modifies the array, it will be reflected back to the original array.**
- The equivalence between arrays and pointers to an array is valid only and only for the function arguments.
- There is usually **no need to pass an array explicitly by reference** because arrays are always passed by reference.

So, We can use **any of the below** code to declare the function which is intended to receive an array as an argument.

```cpp
void fn(type *arrayname)
void fn(type arrayname[SIZE])
void fn(type arrayname[])
```

If an argument is a multidimensional array, its size must be specified. However, the size of the first dimension is optional.

```cpp
void fn(int arr[SIZE_X][SIZE_Y])
void fn(int arr[][SIZE_Y])
```

In C, when we pass an array to a function say fun(), it is **always treated as** a `pointer` by fun().
Therefore in C, **we must pass the size of the array as a parameter**. **Size may not be needed only in the case of** `‘\0’` terminated `character arrays`, size can be determined by checking the end of string character.

```cpp
void printArray(int a[], int size) { //or int *a
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main() {
    int a[5] = {1, 2, 3, 4, 5};
    //int len = sizeof(a) / sizeof(a[0]);
    int len = sizeof(a) / sizeof(int);//20,4
    printArray(a, len);
}
```

### 🎗️🎗️🎗️ C/CPP ✂️modifies✂️ Original array | Pass By Reference/Address

- [https://www.educative.io/answers/pass-by-value-vs-pass-by-reference](https://www.educative.io/answers/pass-by-value-vs-pass-by-reference)

```cpp
void fn(formal_parameters){

}

arguments = x,y;
fn(arguments/actual_parameters);
```

1. `Call By Reference`: It copies the address of an `argument` into the formal `parameter` of that function. In this method, the address is used to access the actual `argument` used in the function call. **It means that changes made in the `parameter` will alter the passing `argument`.**

2. `Call By Value`: It copies the value of an `argument` into the formal `parameter` of that function. **Hence, changes made to the `parameter` of the main function do not affect the original values that are passed as `arguments`.**

<div align="center">
<img src="img/pv.jpg" alt="pv.jpg" width="600px">
</div>

Passing arrays to functions in C/C++ are **passed by reference**. Even though we do not create a reference variable, **the compiler passes the pointer to the array**, _making the original array available** for the called function’s use_. **Thus, if the function modifies the array, it will be reflected back to the original array.** Functions have access to the actual array sent in and can modify it

```cpp
void modifyReceivedArr(int a[], int n) {
    for (int i = 0; i < n; i++)
        a[i] = n - i;
}

int main() {
    int ar[5];
    int n = sizeof(ar) / sizeof(int);
    modifyReceivedArr(ar, n);
    printArray(ar, n); // 5 4 3 2 1
}
```

#### 🧠🧠 Arrays are passed by References only; 🧠🧠But Others are by Value🧠🧠

**There is usually no need to pass an `array` explicitly by reference because arrays are always passed by reference.**

**But other types of variables are by default passed by value**. With pass by value, local parameters become copies of the original arguments that are passed in. Therefore, changes made in the function to the passed arguments do not affect the originals.

When needed we have to **explicitly use pass by References** to allow a function to access one of its parameters directly without creating a copy. We may be passing a complex data structure as a parameter, or we could be looking to optimize the function’s performance on a very large number of function calls using such techniques.**Pass by pointer works even more similarly to pass by reference and even achieves the same result:**

- [dev-SR/differences-between-pointers-and-references-in-cpp](https://github.com/dev-SR/exercise/tree/main/C%2B%2B/1.1pointers#differences-between-pointers-and-references-in-c)
- [https://www.geeksforgeeks.org/passing-by-pointer-vs-passing-by-reference-in-c/](https://www.geeksforgeeks.org/passing-by-pointer-vs-passing-by-reference-in-c/)

```cpp
// By Default arrays are always passed by reference.
void swapArr(int a[]) {
    int temp = a[0];
    a[0] = a[1];
    a[1] = temp;
}
/*
So, There is usually no need to pass an array `explicitly` by reference because arrays are always passed by reference. [CPP syntax]
 */
void swapArrRefs(int (&a)[2]) {
    int temp = a[0];
    a[0] = a[1];
    a[1] = temp;
}

// But other variables are passed by Value
void swapOtherVarsCallByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
// to modify the original values, we need to pass by address/reference
void swapOtherVarsCallByRefs_Pointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// CPP syntax
/*
Pass by reference is used to allow a function to modify a variable without having to create a copy of it.
 */
void swapOtherVarsCallByRefs_CPP_Refs(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int arr[2] = {1, 2};
    swapArr(arr);
    printArray(arr, 2); // 2 1
    swapArrRefs(arr);
    printArray(arr, 2); // 1 2

    int a = 1, b = 2;
    swapOtherVarsCallByValue(a, b);
    cout << a << " " << b << endl; // 1,2
    swapOtherVarsCallByRefs_Pointer(&a, &b);
    cout << a << " " << b << endl; // 2,1
    swapOtherVarsCallByRefs_CPP_Refs(a, b);
    cout << a << " " << b << endl; // 1,2

    return 0;
}
```


### 🌟🌟🌟Returning (Local) Array From the Function in C/C++ | `int* fn(){} ~ int *p = fn()`

We know that a function can not return more than one variable in C/C++. In some problems, we may need to return multiple values from a function, in such cases, an array could be returned from the function. **To return an array from a function we have to return the `pointer` of a data type of the array**.

Consider the below C++ program. Is it right way of returning array from a function?

```cpp
int *fun() {
    int arr[100];
    arr[0] = 10;
    arr[1] = 20;
    return arr;
}

int main() {
    int *ptr = fun();
    printf("%d %d", ptr[0], ptr[1]);
    return 0;
}
```

Warning:

```bash
In function 'int* fun()':
6:8: warning: address of local variable 'arr' returned [-Wreturn-local-addr]
    int arr[100];
        ^
```

The problem is, we return address of a local variable which is not advised as local variables may not exist in memory after function call is over.
**So in simple words, Functions can’t return arrays in C. However, in order to return the array in C by a function, one of the below alternatives can be used.**

Following are some correct ways of returning array:

- Using Dynamically Allocated Array
- Using static array
- Using struct

1. DMA


```cpp
int *fun() {
    // int *arr = new int[10];
    int *arr = (int *)malloc(10 * sizeof(int)); // in c
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    return arr;
}

int main() {
    int *p = fun();
    printArray(p, 10);
    free(p);
    return 0;
}
```

2. static array

```cpp
int *fun() {
    static int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    return arr;
}

int main() {
    int *p = fun();
    printArray(p, 10);
    return 0;
}
```

3. struct

```cpp
struct arrWrap {
    int arr[100];
};
struct arrWrap fun() {
    struct arrWrap x;
    for (int i = 0; i < 10; i++) {
        x.arr[i] = i;
    }
    return x;
}

int main() {
    struct arrWrap x = fun();
    printArray(x.arr, 10);
    return 0;
}
```

### Enabling Pass by Value in C/CPP

In order to pass an array as call by value we have to wrap the array inside a structure and have to assign the values to that array using an object of that structure. This will help us create a new copy of the array that we are passing as an argument to a function.

Lets understand this with a simple example.

- Create a structure which will act as an wrapper and will declare an array inside it.
- Assign the values to the array declared inside a structure using the object of a structure.
- Pass the address of the object to the function call so as to pass the complete array to a function.


```cpp
struct Wrapper {
    int arr[N];
};

// Array is passed by value wrapped in tmp
void compute(struct Wrapper tmp) {
    int *ptr = tmp.arr;
    int i;
    for (i = 0; i < N; ++i)
        ptr[i] = 100;
    printf("Values after modification \n");
    printArray(ptr, N); // 100 100 100 100 100
}

int main() {
    int i;
    struct Wrapper obj;
    for (i = 0; i < N; i++)
        obj.arr[i] = 10;
    compute(obj);
    printf("Values after calling function \n");
    printArray(obj.arr, N); // 10 10 10 10 10
    return 0;
}
```

### Example

#### Partial Array Processing

```cpp
int partialSum(int a[], int size) {//or int *a
    int ans = 0;
    for (int i = 0; i < size; i++) {
        ans += a[i];
    }
    return ans;
}

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int len = sizeof(a) / sizeof(a[0]);
    cout << partialSum(a + 3, len - 3) << endl; // 9 [4+5]
}
```

#### sorting


```cpp
void sort(int a[]) {
    int i, j, tmp;
    for (i = 0; i < 10; i++) {
        for (j = i + 1; j < 10; j++) {
            if (a[j] < a[i]) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void main() {
    int i;
    int arr[10] = {4, 3, 7, 12, 34, 76, 100, 76, 56, 1};
    sort(arr); // calling function and storing returned array
    printf("Sorted elements are \n");
    printArray(arr, 10); // 1 3 4 7 12 34 56 76 76 100
}
```



#### Find all occurrences

```c
#include <stdio.h>
#include <string.h>

int find_all_occurrences(char str[], char c, int indexes[]) {
    int found = 0;
    char *pstr = str;
    do {
        pstr = strchr(pstr, c);
        if (pstr) {
            int offset = pstr++ - str;
            /*
            char *a = "Hello";
            char *f = strchr(a, 'o');
            printf("%p\n", f);   //00405068
            printf("%p\n", a);   //00405064
            printf("%d", f - a); //4 = offset=(found_address - base_address )
            */
            indexes[found++] = offset;
            pstr++;
        }
    } while (pstr); // while (pstr!=NULL)
    return found;
}

void print_occurrences(char str[], int occurrences_indexes[], int found) {
    char pattern[strlen(str) + 1];
    memset(pattern, ' ', sizeof(pattern)); // similar to " "*10 in python
    for (int i = 0; i < found; i++) {
        pattern[occurrences_indexes[i]] = '^';
    }
    pattern[sizeof(pattern) - 1] = '\0';
    printf("%s\n", str);
    printf("%s\n", pattern);
}

int main() {
    char str[] = "This, is a. sample-string";
    int occurrences_indexes[sizeof(str)];
    int found = find_all_occurrences(str, 's', occurrences_indexes);
    print_occurrences(str, occurrences_indexes, found);
    return 0;
}
```

```bash
This, is a. sample-string
   ^   ^    ^      ^
```
