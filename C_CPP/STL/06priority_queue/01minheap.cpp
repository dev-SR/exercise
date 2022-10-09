#include <iostream>
#include <queue> //Header-file for queue

using namespace std;

int main() {
    // Min Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5); //{5}
    pq.push(2); //{2,5}
    pq.push(8); //{2,5,8}

    cout << pq.top() << endl; // 2

    return 0;
}