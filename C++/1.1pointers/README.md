# Pointer & Reference

- [Pointer & Reference](#pointer--reference)
  - [Pointer](#pointer)
    - [Address Of Operator(`&`)](#address-of-operator)
    - [Pointer Variables](#pointer-variables)
    - [Dereference Operator(`*`)](#dereference-operator)
    - [NULL ptr](#null-ptr)
    - [Pass By References - Using Pointers](#pass-by-references---using-pointers)
  - [Reference operator(`&`)](#reference-operator)
    - [Differences between pointers and references in C++](#differences-between-pointers-and-references-in-c)
    - [Pass By Reference - Reference Variables](#pass-by-reference---reference-variables)

## Pointer

### Address Of Operator(`&`)

To get the address of a variable, use the `&` operator.

```cpp
 int a = 10;
    cout << &a << endl; // 0x59ca3ffd2c
```

### Pointer Variables

A pointer variable is a variable that stores the address of another variable. To declare a pointer variable, use the `*` operator.

```cpp
    int a = 10;
    int *p;
    p = &a;
    cout << &a << endl; // 0xd8609ff95c -> address of a
    cout << p << endl;  // 0xd8609ff95c -> address of a
    cout << &p << endl; // 0xd8609ff950 -> address of p itself
```

<div align="center">
 <img src="img/ptr.jpg" alt="ptr.jpg" width="400px">
</div>

### Dereference Operator(`*`)

An interesting property of pointers is that they can be **used to access the variable they point to directly**. This is done by preceding the pointer name with the dereference operator (`*`). The operator itself can be read as `"value pointed to by"`

- `&value => address`
- `*address => value`

```cpp
 int a = 10;
 int *p;
 p = &a;
 cout << *p << endl; // 10
```

### NULL ptr

Sometimes, it is useful to make our pointer variables point to nothing. This is done by assigning the `NULL` pointer .

```cpp
int *p = 0;
int *q = NULL;
```


### Pass By References - Using Pointers

```cpp
void watchVideo(int views) {
    views = views + 1;
}

int main() {
    int views = 100;
    watchVideo(views);
    cout << "views: " << views << endl;//100
}
```

vs:

```cpp
void watchVideo(int *viewsPtr) // int *viewsPtr=&views
{
    *viewsPtr = *viewsPtr + 1;
}

int main() {
    int views = 100;
    watchVideo(&views);
    cout << "views: " << views << endl; // 101
}
```

## Reference operator(`&`)

A reference is an `alias` for an already existing variable. Once a reference is initialized to a variable, it cannot be changed to refer to another variable. Hence, a reference is similar to a `const pointer`.

```cpp
int main() {
    int x = 10;
    int &y = x;
    y++;
    x++;
    cout << x << " " << &x << endl; // 12 0x7ffc8b9d8b50
    cout << y << " " << &y << endl; // 12 0x7ffc8b9d8b50
}
```

<div align="center">
<img src="img/ref.jpg" alt="ref.jpg" width="400px">
</div>

### Differences between pointers and references in C++

C and C++ support pointers which are different from most of the other programming languages. Other languages including C++, Java, Python, Ruby, Perl and PHP support references.

- [https://www.educative.io/edpresso/differences-between-pointers-and-references-in-cpp](https://www.educative.io/edpresso/differences-between-pointers-and-references-in-cpp)
- [https://www.geeksforgeeks.org/pointers-vs-references-cpp/](https://www.geeksforgeeks.org/pointers-vs-references-cpp/)
- [https://techdifferences.com/difference-between-pointer-and-reference-2.html](https://techdifferences.com/difference-between-pointer-and-reference-2.html)

Major dif:

- The reference is an alias for a variabl  whereas pointers are used to store address of variable.
- A reference **must be initialized on declaration** while it is not necessary in case of pointer.
- References **cannot have a null value** assigned but pointer can.

**When to use What:**

The performances are exactly the same, as **references are implemented internally as pointers**. But still we can keep some points in mind to decide when to use what :

- Use `references`
  - In function parameters and return types.
- Use `pointers`:
  - Use pointers if pointer arithmetic or passing NULL-pointer is needed. For example for arrays (Note that array access is implemented using pointer arithmetic).
  - To implement data structures like linked list, tree, etc and their algorithms because to point different cell, we have to use the concept of pointers

### Pass By Reference - Reference Variables

```cpp
// pass by value
void applyTax(int income) {
    float tax = 0.1;
    income = income - (income * tax);
}
int main() {
    int income = 100;
    applyTax(income);
    cout << "Income after tax: " << income << endl; // 100
}
```

vs

```cpp
// pass by reference
void applyTax(int &income) {
    float tax = 0.1;
    income = income - (income * tax);
}
int main() {
    int income = 100;
    applyTax(income);
    cout << "Income after tax: " << income << endl; // 90
}
```

