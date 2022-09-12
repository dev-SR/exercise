#include <iostream>
using namespace std;

int main() {
    string name = "Jhon Smith.";
    // find first occurrence of any of the characters in the string
    cout << "Pos. of first occurrence of any of the vowels is: " << name.find_first_of("aeiou") << endl; // 2
    cout << name.find_last_of(".;,") << endl;                                                            // 10
    cout << name.find_first_not_of("Jhon") << endl;                                                      // 4
    cout << name.find_last_of("Smith") << endl;                                                          // 9
    cout << name.find_last_not_of("Smith.") << endl;                                                     // 4
}