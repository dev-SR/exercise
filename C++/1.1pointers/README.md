# Pointer

- [Pointer](#pointer)
	- [Address Of Operator(`&`)](#address-of-operator)
	- [Pointer Variables](#pointer-variables)
	- [Dereference Operator(`*`)](#dereference-operator)
	- [NULL ptr](#null-ptr)
	- [Pass By References - Using Pointers](#pass-by-references---using-pointers)
	- [Reference operator(`&`)](#reference-operator)
	- [Pass By Reference - Reference Variables](#pass-by-reference---reference-variables)

## Address Of Operator(`&`)

To get the address of a variable, use the `&` operator.

```cpp
 int a = 10;
    cout << &a << endl; // 0x59ca3ffd2c
```

## Pointer Variables

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

## Dereference Operator(`*`)

An interesting property of pointers is that they can be **used to access the variable they point to directly**. This is done by preceding the pointer name with the dereference operator (`*`). The operator itself can be read as `"value pointed to by"`

- `&value => address`
- `*address => value`

```cpp
 int a = 10;
 int *p;
 p = &a;
 cout << *p << endl; // 10
```

## NULL ptr

Sometimes, it is useful to make our pointer variables point to nothing. This is done by assigning the `NULL` pointer .

```cpp
 int *p = NULL;
```


## Pass By References - Using Pointers

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

## Pass By Reference - Reference Variables

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
