#include <iostream>
#include <utility>

using namespace std;

template <typename T1, typename T2>
void print(pair<T1, T2> &p) {
    cout << "Pair(" << p.first << ", " << p.second << ")" << endl;
}

int main() {
    // pair of different data type
    pair<int, string> p1(1, "Hello");
    print(p1); // Pair(1, Hello)
    // pair of same data type
    pair<int, int> p2(10, 20);
    print(p2); // Pair(10, 20)
    // make pair function
    pair<int, string> p3;
    p3 = make_pair(1, "one");
    print(p3); // Pair(1, one)
}
