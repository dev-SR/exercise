#include <iostream>
#include <map>

using namespace std;

template <typename K, typename V>
void printMap(map<K, V> &m) {
    for (auto &i : m) {
        cout << "{" << i.first << ", " << i.second << "}" << endl;
    }
    cout << endl;
}

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
    printMap(mp);

    // insert
    mp.insert({"new", 4}); // {new, 4}
    printMap(mp);

    // erase
    mp.erase("new");
    printMap(mp);

    // update
    mp["easy"] = 5;

    // Searching and Counting

    //  find
    auto it = mp.find("easy");
    if (it != mp.end()) {
        cout << "Found: " << it->first << ", " << it->second << endl;
    }

    return 0;
}
