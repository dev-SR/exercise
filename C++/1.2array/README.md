# Array

- [Array](#array)
  - [Creating Array](#creating-array)
  - [Working with Array](#working-with-array)
  - [Array and Pointer](#array-and-pointer)
  - [Passing Array To a Function](#passing-array-to-a-function)
    - [UseCases:](#usecases)
      - [Partial Array Processing](#partial-array-processing)
      - [Modify Received Array](#modify-received-array)
        - [ex: find all occurrences](#ex-find-all-occurrences)

## Creating Array

```cpp
int a[100];
int a[100] = {0};
int a[100] = {1,2,3};
int a[] = {1,2,3};
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

Note that `a[]` for fun() is just a `pointer` even if square brackets are used as the name of an array acts as a special kind of variable -- a `pointer` -- which stores the starting address of the array.

- Because an array is not a single item, the **array contents are not passed "by value"** as we are used to with normal variables.
- When an array is sent into a function, **only its starting address is really sent**. This means the f**unction will always have access to the actual array sent in**
- Returning an array from a function works similarly, but we need pointers to use them well

So, We can use **any of the below** code to declare the function which is intended to receive an array as an argument.

```cpp
return_type function(type arrayname[])
return_type function(type arrayname[SIZE])
return_type function(type *arrayname)
```

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

### UseCases:

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

#### Modify Received Array

Functions have access to the actual array sent in and can modify it

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

##### ex: find all occurrences

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
