# Function Templates in C++

## Introduction

- Function templates are just blueprints, they're not real function declaration and definition
- Real function declarations and definitions, aka template instances are created when you call the function with arguments
- If the template parameters are of the same type (T,T), then the arguments you call the function with must also match, otherwise you get a compiler error
- Template instances won't always do what you want. A good example is when you call our maximum function with pointers. DISASTER!
- There are tools like cppinsights.io that can show you template instantiations. You can even use the debugger to infer that information from the activation record of a template function
- The arguments passed to a function template must support the operations that are done in the body of the function



```cpp
#include <iostream>
using namespace std;

template <typename T>
T maximum(T a, T b);

// template type parameter by reference
template <typename T>
const T &maximum_ref(const T &a, const T &b);

int main() {
    cout << "max(int): " << maximum(1, 2) << endl;
    cout << "max(double): " << maximum(1.1, 2.2) << endl;
    cout << "max(char): " << maximum('a', 'b') << endl;

    cout << "max_ref(int): " << maximum_ref(1, 2) << endl;
    cout << "max_ref(double): " << maximum_ref(1.1, 2.2) << endl;
    cout << "max_ref(char): " << maximum_ref('a', 'b') << endl;

	auto func =[]<typename T>(T a, T b) { return a > b ? a : b; };
	cout << "max_lambda(int): " << func(1, 2) << endl;
}

template <typename T>
T maximum(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
const T &maximum_ref(const T &a, const T &b) {
    return a > b ? a : b;
}
```

## Function templates with overloading

```cpp
template <typename T>
T maximum(T a, T b) {
    return a > b ? a : b;
}
template <typename T>
const char *maximum(const char *a, const char *b) {
    return strcmp(a, b) > 0 ? a : b;
}

template <typename T>
T *maximum(T *a, T *b) {
    return *a > *b ? a : b;
}
```

## Function templates with multiple parameters


```cpp
template <typename ReturnType, typename T, typename P>
ReturnType maximum(T a, P b) {
	return a > b ? a : b;
}

auto result = maximum<int,double,double>(1.1, 2.2);
```


## Bounded Type Parameters: Concept

- A concept is a set of requirements that a type must satisfy in order to be used in a template


```cpp
#include <iostream>
using namespace std;
// syntax for concept
template <typename T>
requires integral<T>
    T addNumber(T a, T b) {
    return a + b;
}
template <typename T>
requires is_integral_v<T>
    T addNumber2(T a, T b) {
    return a + b;
}

template <integral T>
T addNumber3(T a, T b) {
    return a + b;
}

auto addNumber4(integral auto a, integral auto b) {
	return a + b;
}

template <typename T>
T addNumber5(T a, T b) requires integral<T> {
	return a + b;
}

int main() {
    cout << addNumber(1, 2) << endl;
    // cout << addNumber(1.1, 2.1) << endl; // error
	cout << addNumber2(1, 2) << endl;
	cout<< addNumber3(1, 2) << endl;
	cout << addNumber4(1, 2) << endl;
	cout << addNumber5(1, 2) << endl;

    return 0;
}
```
