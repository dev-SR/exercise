#include <iostream>
using namespace std;

int main() {
    // substr(pos, len) returns a substring of length len starting at pos
    string name = "Jhon Snow Smith";

    size_t index = name.rfind(' ');

    // extract first name
    string first_name = name.substr(0, index);
    // extract last name
    string last_name = name.substr(index + 1);

    cout << "(" << first_name << ")" << endl; // (Jhon Snow)
    cout << "(" << last_name << ")" << endl;  // (Smith)

    return 0;
}