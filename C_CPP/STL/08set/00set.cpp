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

    cout << endl;
    //{1,2,3}
    set<int>::iterator it = s.find(10);
    if (it == s.end())
        cout << "not present\n";

    // {1,2,3}
    int found = s.count(1);
    if (found) {
        cout << "present\n";
    }

    return 0;
}