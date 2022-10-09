#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int z = 0;
    while (z <= 100) {
        q.push(z);
        z += 10;
    }
    cout << q.front() << "\n"; // 0
    cout << q.back() << "\n";  // 100
    cout << q.size() << "\n";  // 11
    cout << "The elements in the queue q are: \n";
    while (!q.empty()) {
        int first = q.front();
        cout << first << "\n";
        q.pop();
    }

    return 0;
}