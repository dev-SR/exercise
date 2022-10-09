# Algorithms in STL

- [Algorithms in STL](#algorithms-in-stl)
	- [sort()](#sort)
		- [sorting primitive array](#sorting-primitive-array)
		- [sorting vector](#sorting-vector)
		- [sorting in descending order](#sorting-in-descending-order)
		- [sorting complex data type in custom order](#sorting-complex-data-type-in-custom-order)
	- [next_permutation()](#next_permutation)
	- [`*max_element(startaddress, endaddress)`](#max_elementstartaddress-endaddress)

## sort()


### sorting primitive array

- `sort(startaddress, endaddress)`: So actually sort() sorts in the range of `[startaddress,endaddress)`

```cpp
#include <algorithm> //  sort
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *first = arr;
    int *last = arr + n;
    //`arr` is address of first element, `arr+n` is address of last element
    sort(first, last);
    show(arr, n);//0 1 2 3 4 5 6 7 8 9
}
```

### sorting vector

```cpp
int main() {
    vector<int> v = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    auto first = v.begin();
    auto last = v.end();
    sort(first, last);
    show(v);
    sort(first, last, greater<int>());
    show(v);
    return 0;
}
```

### sorting in descending order

- `sort(startaddress, endaddress, greater<int>())`

```cpp
#include <algorithm> //  sort
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *first = arr;
    int *last = arr + n;
    sort(first, last, greater<int>());
    show(arr, n);//9 8 7 6 5 4 3 2 1 0
}
```

### sorting complex data type in custom order

- `sort(startaddress, endaddress, compare)`

For example, we want to sort a vector of pairs in descending order of second element of pair.

```cpp
#include <algorithm> //  sort
#include <iostream>
#include <vector>
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}

int main() {
    vector<pair<int, int>> v = {
        {4, 8},
        {3, 4},
        {8, 2},
        {5, 6},
    };
    auto first = v.begin();
    auto last = v.end();
    sort(first, last, compare);
    for (auto x : v) {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}
```

output:

```bash
4 8
5 6
3 4
8 2
```

We can also use `lambda` function to do the same thing.

```cpp
    sort(first, last, [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });
```

## next_permutation()

- `next_permutation(startaddress, endaddress)`: It generates the next permutation of the array in lexicographical order.

```cpp
#include <algorithm> //  next_permutation
#include <iostream>
using namespace std;
int main() {
    string s = "abc";
    auto first = s.begin();
    auto last = s.end();
    sort(first, last); // sort should be applied if we want all permutations
    do {
        cout << s << endl;
    } while (next_permutation(first, last));
}
/*
abc
acb
bac
bca
cab
cba
 */
```

## `*max_element(startaddress, endaddress)`

- `max_element(startaddress, endaddress)`: It returns the address of maximum element in the range `[startaddress,endaddress)`
- `*max_element(startaddress, endaddress)`: It returns the maximum element in the range `[startaddress,endaddress)`

```cpp
#include <algorithm> //  max_element
#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *first = arr;
    int *last = arr + n;
    cout << max_element(first, last) << endl;  // 0xea42fffccc **address of the max element**
    cout << *max_element(first, last) << endl; // 9
    return 0;
}
```