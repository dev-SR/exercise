#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void show(vector<int> &v) {
    for (int &i : v) {
        cout << i << " ";
    }
    cout << endl;
}

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