# Map in C++

- [Map in C++](#map-in-c)
	- [Map](#map)
		- [Insert,Delete,Update](#insertdeleteupdate)
		- [Searching](#searching)

## Map

- store elements in `key-value` pairs.
- every key has to be unique


```cpp
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> mp;
    mp["easy"] = 1;   //{easy, 1}
    mp["hard"] = 2;   //{hard, 2}
    mp["medium"] = 3; //{medium, 3}

    //  Element Access
    cout << mp["easy"] << endl;
    //[] vs at()
    try {
        cout << mp.at("unkown") << endl; //  throws exception
    } catch (const exception &e) {
        cout << "Exception: key not found" << endl;
    }

    cout << mp["unkown"] << endl; //  inserts a new element with value 0 if not found
                                  // {unkown, 0}
    for (auto it : mp)
        cout << "{" << it.first << ", " << it.second << "}" << endl;
}

```

### Insert,Delete,Update

- `.insert({key,value})`

```cpp
    mp.insert({"new", 4}); // {new, 4}
```

- `.erase(key)`

```cpp
    mp.erase("new");
```

- update

```cpp
	 mp["easy"] = 5;
```

### Searching

```cpp
    auto it = mp.find("easy");
    if (it != mp.end()) {
        cout << "Found: " << it->first << ", " << it->second << endl;
    }

	 if (mp.find("tough") != mp.end())
        cout << "It is present" << endl;
    else
        cout << "It is not present" << endl;
```