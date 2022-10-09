#include <iostream>
#include <list>
using namespace std;

// printing the elements of a list
void print(list<int> &lst) {
    list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); ++it)
        cout << *it << " ";
    cout << '\n';
}

int main() {
    list<int> lst = {1, 2, 3, 4};
    lst.push_back(5);
    print(lst);        // 1 2 3 4 5
    lst.push_front(0); // O(1), whereas vector::insert is O(n)
    print(lst);        // 0 1 2 3 4 5

    return 0;
}