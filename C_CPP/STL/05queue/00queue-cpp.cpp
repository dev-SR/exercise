#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(1); //{1}
    q.push(2); //{1,2}
    q.push(3); //{1,2,3}

    cout << q.front() << endl; // 1
    cout << q.back() << endl;  // 3

    q.back() = 5;             //{1,2,5}
    cout << q.back() << endl; // 5
    q.back()++;               //{1,2,6}
    cout << q.back() << endl; // 6
    q.back() += 4;            //{1,2,10}
    cout << q.back() << endl; // 10

    q.pop();                   //{2,10}
    cout << q.front() << endl; // 2
    cout << q.back() << endl;  // 10

    cout << q.size() << endl;  // 2
    cout << q.empty() << endl; // 0

    return 0;
}