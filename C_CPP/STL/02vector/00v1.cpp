#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &arr) {
    for (auto &i : arr)
        cout << i << " ";
    cout << endl;
}

int main() {
    vector<int> v{1, 2, 3};
    v.clear();
    cout << v.size() << endl;  // 0
    cout << v.empty() << endl; // 1
}