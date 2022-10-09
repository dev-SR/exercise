# Pair

- [Pair](#pair)
	- [Intro](#intro)
	- [Unpacking with `tie(int &, int &) = pair1;`](#unpacking-with-tieint--int---pair1)
	- [Nested Pairs](#nested-pairs)

## Intro

Pair in C++ behaves similarly to `tuple` in python. It consists of two elements `{first, second}`, the first element is referred to as `first` while the second element is referred to as `second`. This order must be fixed `(first, second)`. The header file for Pair in C++ is `<utility>`

```cpp
#include <iostream>
#include <utility>

using namespace std;

template <typename T1, typename T2>
void print(pair<T1, T2> &p) {
    cout << "Pair(" << p.first << ", " << p.second << ")" << endl;
}

int main() {
    // pair of different data type
    pair<int, string> p1(1, "Hello");
    print(p1); // Pair(1, Hello)

    // pair of same data type
    pair<int, int> p2(10, 20);
    print(p2); // Pair(10, 20)

    // make pair function
    pair<int, string> p3;
    p3 = make_pair(1, "one");
    print(p3); // Pair(1, one)
}
```

- `make_pair()` It makes it possible to create a value pair **without having to explicitly write the data types**.

## Unpacking with `tie(int &, int &) = pair1;`

```cpp
#include <iostream>
#include <tuple>//for tie()
#include <utility>//for pair
using namespace std;

int main() {
    pair<int, int> p1(1, 2);

    int a, b;
    tie(a, b) = p1;

    cout << a << " " << b << endl; // 1 2

    return 0;
}
```

## Nested Pairs

```cpp
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

int main() {
    pair<int, pair<int, int>> p(1, {2, 3}); // p(1,mak_pair(2,3))
    int a = p.first;
    int b = p.second.first;
    int c = p.second.second;
    cout << a << " " << b << " " << c << endl; // 1 2 3

    pair<pair<int, int>, int> p1;
    p1 = make_pair(make_pair(1, 2), 3);
    int d = p1.first.first;
    int e = p1.first.second;
    int f = p1.second;
    cout << d << " " << e << " " << f << endl; // 1 2 3

    // pair of vector
    pair<vector<int>, vector<int>> p3;
    p3 = make_pair(vector<int>{1, 2, 3}, vector<int>{4, 5, 6});
    cout << "Printing pair of vector\n";
    vector<int> X, Y;
    tie(X, Y) = p3;
    for (auto &i : X)
        cout << i << " ";
    cout << endl;
    for (auto &i : Y)
        cout << i << " ";

    return 0;
}
```



