# Set

- [Set](#set)
	- [Set in Details](#set-in-details)
		- [Methods](#methods)
		- [Searching](#searching)
	- [Multiset](#multiset)
	- [unordered_set](#unordered_set)

## Set in Details

- store unique elements (no duplicates values) and
- also stored in a specifically sorted manner.
- The elements can be inserted or removed, but when inserted once, they cannot be modified.


```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    s.insert(1); //{1}
    s.insert(2); //{1,2}
    s.insert(3); //{1,2,3}
                 // elements are always sorted
    for (auto x : s)
        cout << x << " ";

    return 0;
}
```

### Methods

- has similar methods as vector

### Searching

```cpp
	set<int>::iterator it = s.find(10);
    if (it == s.end())
        cout << "not present\n";

    // {1,2,3}
    int found = s.count(1);
    if (found) {
        cout << "present\n";
    }
```

## Multiset

- It is similar to set, but it can store duplicate values.

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> ms;
    ms.insert(1); //{1}
    ms.insert(1); //{1,1}
    ms.insert(2); //{1,1,2}

    ms.erase(1); //{2} // erase all 1s

    multiset<int> ms1{1, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    //  only a single 1 will be erased
    ms1.erase(ms1.find(1));
    for (auto x : ms1)
        cout << x << " ";
}
```

## unordered_set

- it does not store elements in a sorted manner.
- it has a constant time complexity than set, except som when collision occurs.

