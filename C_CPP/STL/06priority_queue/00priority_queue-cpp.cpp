#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;
    pq.push(5); //{5}
    pq.push(2); //{5,2}
    pq.push(8); //{8,5,2}

    cout << pq.top() << endl; // 8

    pq.pop();                 //{5,2}
    cout << pq.top() << endl; // 5

    priority_queue<int> p1;
    p1.push(30);
    p1.push(40);
    p1.push(50);
    p1.push(20);

    while (!p1.empty()) {
        cout << ' ' << p1.top();
        p1.pop();
    }
    // 50 40 30 20

    return 0;
}