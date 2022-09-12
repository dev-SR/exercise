#include <iostream>
using namespace std;

int main() {
    string name = "Jhon Smith";
    // find first/last occurrence of a character
    cout << "Pos. of first occurrence of 'h' is: " << name.find('h') << endl; // 1
    cout << "Pos. of last occurrence of 'h' is: " << name.rfind('h') << endl; // 9

    // find first/last occurrence of a substring
    cout << "Pos. of first occurrence of 'Smith' is: " << name.find("Smith") << endl; // 5
    cout << "Pos. of last occurrence of 'Smith' is: " << name.rfind("Smith") << endl; // 5

    // find returns (size_t)/unsigned long long int
    size_t t = -1; // we can't store a negative value in size_t/unsigned long long int

    /* if we try to store a negative value in size_t/unsigned long long int, it will be converted to a very large positive value (largest possible value )*/

    cout << t << endl;                                                            // 18446744073709551615
    cout << "Pos. of first occurrence of 'Bob' is: " << name.find("Bob") << endl; // 18446744073709551615
    if (name.find("Bob") == -1) {
        cout << "Not found" << endl;
    }
    // instead of -1, we can use string::npos
    if (name.find("Bob") == string::npos) {
        cout << "Not found" << endl;
    }

    return 0;
}