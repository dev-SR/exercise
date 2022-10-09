// CPP program to illustrate pair in STL
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

int main() {
    pair<int, pair<int, int>> p(1, {2, 3}); // p(1,mak_pair(2,3))
    int a = p.first;
    int b = p.second.first;
    int c = p.second.second;
    cout << a << " " << b << " " << c << endl; // 1 2 3

    pair<pair<int, int>, int> p1;
    p1 = make_pair(make_pair(1, 2), 3);
    int d = p1.first.first;
    int e = p1.first.second;
    int f = p1.second;
    cout << d << " " << e << " " << f << endl; // 1 2 3

    // pair of vector
    pair<vector<int>, vector<int>> p3;
    p3 = make_pair(vector<int>{1, 2, 3}, vector<int>{4, 5, 6});
    cout << "Printing pair of vector\n";
    vector<int> X, Y;
    tie(X, Y) = p3;
    for (auto &i : X)
        cout << i << " ";
    cout << endl;
    for (auto &i : Y)
        cout << i << " ";

    return 0;
}
