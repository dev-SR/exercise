# Lambda Function in C++

- [Lambda Function in C++](#lambda-function-in-c)
	- [Introduction](#introduction)
	- [Declaring and using lambda functions](#declaring-and-using-lambda-functions)
	- [Capture List](#capture-list)
	- [Capture all in context](#capture-all-in-context)


## Introduction

A mechanism to set up anonymous functions (without names). Once we
have them set up, we can either give them names and call them, or
we can even get them to do things directly.

## Declaring and using lambda functions

A lambda function signature:

```bash
[capture_list] (parameters) ->return_type{
	Function Body
};

```

example:


```cpp
#include <iostream>
using namespace std;

int main() {

    auto func = []() -> void {
        cout << "Hello World" << endl;
    };
    func();

    /* Call lambda directly after definiton */

    []() {
        cout << "Hello World" << endl;
    }();

    /* Lambda with parameters +return */
    auto res = [](int a, int b) -> int { return a + b; }(10, 20);
    cout << res << endl; // 30

    // inline with cout
    cout << [](int a, int b) { return a * b; }(2, 2) << endl; // 4

}
```


## Capture List

A lambda expression can refer to identifiers declared **outside** the lambda expression. If the identifier is a local variable or a reference with automatic storage duration, it is an up-level reference and must be "captured" by the lambda expression. Such a lambda expression must be introduced by `[lambda-capture]`, where `lambda-capture` specifies whether identifiers are captured by reference or by copy.


```cpp
	int a = 10;
    int b = 20;

    auto cap = [a, b]() {
        cout << a << " " << b << endl;
    };
    cap();// 10 20
```

Capturing by value: what we have in the lambda function is a copy:



```cpp
	int c = 0;
    auto cap_by_value = [c]() {
        cout << "Inner: " << c << endl;
    };
    for (int i = 0; i < 3; i++) {
        cout << "Outer: " << c << endl;
        cap_by_value();
        ++c;
    }
```

```bash
Outer: 0
Inner: 0
Outer: 1
Inner: 0
Outer: 2
Inner: 0
```

Capturing by reference:


```cpp
	int c = 0;
    auto cap_by_ref = [&c]() {
        cout << "Inner: " << c << endl;
    };
    for (int i = 0; i < 3; i++) {
        cout << "Outer: " << c << endl;
        cap_by_ref();
        ++c;
    }
```

```cpp
Outer: 0
Inner: 0
Outer: 1
Inner: 1
Outer: 2
Inner: 2
```

## Capture all in context


```cpp
	int i=0, j=0, k = 0;

    // capture everything by value
    auto cap_all_by_value = [=]() {
        cout << i << " " << j << " " << k << endl;
    };
    // capture everything by ref
    auto cap_all_by_ref = [&]() {
        cout << i << " " << j << " " << k << endl;
    };

    for (int a = 0; a < 3; a++) {
        cout << "Outer: " << i << " " << j << " " << k << endl;
        cap_all_by_value();
        cap_all_by_ref();
        ++i;
        ++j;
        ++k;
    }
```
