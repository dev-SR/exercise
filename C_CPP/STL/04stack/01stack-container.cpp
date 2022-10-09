#include <iostream>
#include <list>
#include <stack>
using namespace std;

int main() {
    stack<char, list<char>> st;
    st.push('a');
    st.push('b');

	 cout << st.top() << endl; // b
    return 0;
}