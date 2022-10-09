#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack<int> s;
    s.push(1); //{1}
    s.push(2); //{1,2}
    s.push(3); //{1,2,3}

    cout << s.top() << endl; // 3 "** s[2] is invalid**"

    s.pop();                 //{1,2}
    cout << s.top() << endl; // 2

    cout << s.size() << endl;  // 2
    cout << s.empty() << endl; // 0

    return 0;
}