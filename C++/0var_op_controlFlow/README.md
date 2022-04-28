# Basic

- [Basic](#basic)
  - [Variables, Datatypes & Storage](#variables-datatypes--storage)
    - [`sizeof()`](#sizeof)
    - [Data-Type Modifiers](#data-type-modifiers)
    - [Storage of Characters and Booleans](#storage-of-characters-and-booleans)
  - [Operators and Expressions](#operators-and-expressions)
    - [Bitwise Operators](#bitwise-operators)
  - [Flow Control - Branching](#flow-control---branching)
    - [Ternary Operator](#ternary-operator)
    - [🆕if statement with initializer(C++17 syntax)](#if-statement-with-initializerc17-syntax)
    - [`switch`](#switch)
  - [Flow Control - Loops](#flow-control---loops)
    - [while  loop](#while--loop)
    - [for loop](#for-loop)
    - [break](#break)
    - [continue](#continue)
    - [ex](#ex)
      - [print sum of 1 to N](#print-sum-of-1-to-n)
      - [special sum](#special-sum)
      - [fibonacci](#fibonacci)
  - [Function](#function)
    - [Forward Declaration](#forward-declaration)
    - [Default Parameters](#default-parameters)
    - [ex1 - Binomial Coefficient](#ex1---binomial-coefficient)

## Variables, Datatypes & Storage

### `sizeof()`

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << sizeof(n) << endl;   // 4bytes = 32bits
    cout << sizeof(int) << endl; // 4bytes = 32bits
    cout << "Character: " << sizeof(char) << endl;          // 1byte = 8bit
    cout << "Bool: " << sizeof(bool) << endl;               // 1byte = 8bit
    cout << "Int: " << sizeof(int) << endl;                 // 4byte = 32bit
    cout << "Long: " << sizeof(long) << endl;               // 4byte = 32bit
    cout << "Long long: " << sizeof(long long) << endl;     // 8byte = 64bit
    cout << "Float: " << sizeof(float) << endl;             // 4byte = 32bit
    cout << "Double: " << sizeof(double) << endl;           // 8byte = 64bit
    cout << "Long double: " << sizeof(long double) << endl; // 16byte = 128bit
    cout << "Pointer: " << sizeof(void *) << endl;          // 8byte = 64bit
}
```

### Data-Type Modifiers

In C++ programming, type modifiers are used to change the meaning of the fundamental data types.

There are four type modifiers in C++.

- `short`
- `long`
- `signed`
- `unsigned`

### Storage of Characters and Booleans

```cpp
 char A = 'A';
    int AA = A;
    cout << A << endl;              // A
    cout << AA << endl;             // 65
    cout << A + 1 << endl;          // 66
    cout << AA + 1 << endl;         // 66
    cout << (char)(AA + 1) << endl; // B
    cout << (char)(A + 1) << endl;  // B

    int a = 10;
    bool aa = a;
    cout << aa << endl; // 1
    aa = "Hello";
    cout << aa << endl; // 1
    aa = "";
    cout << aa << endl; // 1
    aa = true;
    cout << aa << endl; // 1
    aa = false;
    cout << aa << endl; // 0
    aa = 0;
    cout << aa << endl; // 0
```

## Operators and Expressions

### Bitwise Operators

```cpp
int main() {
    int a = 5;
    int b = 3;
    cout << (a << b) << endl; //(lelfshift) a<<b=a*2^b =  5*2^3 = 5*8 = 40
    cout << (a >> b) << endl; //(rightshift) a>>b=a/2^b =  5/2^3 = 5/8 = 0
}
```

## Flow Control - Branching

```cpp
    if (0)
        cout << "false";
    if (!0)
        cout << "true"; // true
```

### Ternary Operator

```cpp
 int a = 5;
    a % 2 == 0 ? cout << "Even" << endl : cout << "Odd" << endl;

    string weather = a > 20 ? "Sunny" : "Rainy";
    cout << weather << endl;
```

### 🆕if statement with initializer(C++17 syntax)

- it change from
  - `if (condition)` to
  - `if (initialize ; condition)`
- helps limiting scope inside if-else scope

```cpp
if (int i = 10; i % 2 == 0) {
        cout << "even" << endl;
    } else if (i % 2 == 1) {
        cout << "odd" << endl;
    }
```

### `switch`

```cpp
int main() {
    int a, b;
    char op;
    cin >> a >> op >> b;
    switch (op) {
  case '+':cout << a + b << endl;break;
  case '-':cout << a - b << endl;break;
  case '*':cout << a * b << endl;break;
  case '/':cout << a / b << endl;break;
  default:cout << "Invalid operator" << endl;
    }
}
```

## Flow Control - Loops

### while  loop

```cpp
    int T;
    cin >> T; // 3
    while (T--) {
        cout << T; // 2 1 0
    }
```

Print Range:

```cpp
int start, end;
cin>>start>>end;// 3 7
while(start <= end)
 {
  cout<<start<<"\n";
  start++;
 }
 // 3 4 5 6 7
```

### for loop

```cpp
int main() {
    int sum = 0;
    int N;
    cin >> N;
    for (; N != 0; N = N / 10) {
        sum += N % 10;
    }
    cout << sum << endl;
    return 0;
}

/**
 *    12345  % 10 = 5
 * (N/10) 1234   % 10 =+4
 * (N/10) 123    % 10 =+3
 * (N/10) 12     % 10 =+2
 * (N/10) 1      % 10 =+1
 * (N/10) 0
 */
```

### break

```cpp
int main() {
    int calories = 0;
    int time_spent = 0;
    int gf_calls_up = 10;

    while (calories < 30) {
        calories++;
        time_spent++;
        cout << "running & burning :" << (calories) << endl;
        if (time_spent == gf_calls_up) {
            cout << "gf called" << endl;
            break;
        }
    }
}
```

### continue

```cpp
int main() {
    int calories = 1;

    while (calories < 30) {
        // print "Well Done" and Skip "running & burning" after every 5 calories
        if (calories % 5 == 0) {
            cout << "Well Done" << endl;
            calories++; // don't forget this line->otherwise infinite loop
            continue;
            // skip below lines; go to next iteration
        }
        cout << "running & burning :" << (calories) << endl;
        calories++;
    }
}
```

```bash
running & burning :1
running & burning :2
running & burning :3
running & burning :4
Well Done
running & burning :6
running & burning :7
running & burning :8
running & burning :9
Well Done
running & burning :11
....
```

### ex

#### print sum of 1 to N

input:

```cpp
3
5
7
```

output:

```cpp
15
28
```

Explanation:

- `1+2+3+4+5 = 15`
- `1+2+3+4+5+6+7 = 28`

solution:

```cpp
void solve() {
    int n;
    cin >> n;
    int sum = 0;
    int i = 1;
    while (i <= n) {
        sum += i;
        i++;
    }
    cout << "Sum from 1 to " << n << " = " << sum << "\n";
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
```

#### special sum

Then read `N` numbers `a`, `b`, `c`, ..... and compute the sum of: `(a, b*b, c*c*c, ….....)`, that is the k-th number is repeated k times

Input:

```bash
2
3 5 7 2
4 1 2 3 4
```

Output:

```bash
62
288
```

Explanation:

- `(5 + 7*7 +2*2*2) = 62`
- `(1+2*2+3*3*3+4*4*4*4) = 288`

Solution:

```cpp
void solve() {
    int N;
    cin >> N;
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        int mul = 1;
        for (int j = 0; j < i; j++) {
            mul = n * mul;
        }
        sum = sum + mul;
    }
    cout << sum << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```

Solve 2:

```cpp
void solve() {
    int N;
    cin >> N;
    int sum = 0;
    int i = 1;
    while (i <= N) {
        int n;
        cin >> n;
        int mul = 1;
        int j = i;
        while (j > 0) {
            mul = n * mul;
            j--;
        }
        sum = sum + mul;
        i++;
    }
    cout << sum << endl;
}
```

#### fibonacci

```cpp
    int n = 10;
    for (int a = 0, b = 1, c = -1, i = 0; i < n;
         ++i, c = a + b, a = b, b = c)
        cout << a << " ";

    // 0 1 1 2 3 5 8 13 21 34
```

## Function

### Forward Declaration

```cpp
// Forward Declarations
void printNumber(int n);

int main() {
    printNumber(5);
}

// Declaration + Definition
void printNumber(int n) {
    cout << n << endl;
}
```

### Default Parameters

```cpp
int defaultParam(int n = 5) {
    cout << "n = " << n << endl;
    return 0;
}

int main() {
    defaultParam();                    // n=5
    defaultParam(10);                  // n=10
}
```

### ex1 - Binomial Coefficient

```cpp
int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
/**
 * nCk = n! / (k! * (n-k)!)
 */
int binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    printNumber(5);
    cout << binomialCoefficient(5, 2); // 10
    return 0;
}
```
