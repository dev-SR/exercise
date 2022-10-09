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