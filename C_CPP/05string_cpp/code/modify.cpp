#include <iostream>
using namespace std;

int main() {
    string name = "Jhon";
    // append
    name.append("Smith");
    cout << name << endl; // JhonSmith

    // insert at a particular position
    name.insert(4, " ");
    cout << name << endl; // Jhon-Smith

    // erase a particular position
    int chars_to_erase = 6;
    name.erase(4, chars_to_erase);
    cout << name << endl; // Jhon

    // replace a particular position
    int chars_to_replace = 4;
    name.replace(0, chars_to_replace, "Robert");
    cout << name << endl; // Robert

    // clear
    name.clear();
    cout << name << endl; // (empty string)

    return 0;

    // clear the string
    name.clear();

    return 0;
}