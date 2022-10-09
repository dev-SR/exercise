#include <algorithm> //  sort
#include <iostream>
#include <vector>
using namespace std;
// bool compare(pair<int, int> p1, pair<int, int> p2) {
//     return p1.second > p2.second;
// }

int main() {
    vector<pair<int, int>> v = {
        {4, 8},
        {3, 4},
        {8, 2},
        {5, 6},
    };
    auto first = v.begin();
    auto last = v.end();
    sort(first, last, [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });
    for (auto x : v) {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}