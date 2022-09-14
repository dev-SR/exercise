#include <cstring>
#include <iostream>
using namespace std;

int main() {
    //
    const char *str = "Hello World";
    char target = 'l';
    const char *pFound = str;
    int count = 0;

    while ((pFound = strchr(pFound, target)) != NULL) {
        cout << "Found " << target << " at " << (pFound - str) << " (" << pFound << ")" << endl;
        ++count;
        ++pFound;
    }
    cout << "Found " << count << " " << target << "'s" << endl;

    const char *intput = "/home/user/Downloads/hello.cpp";
    const char *found = strrchr(intput, '/');
    if (found) {
        cout << "Found " << found + 1 << " at " << (found - intput) << endl;
    }

    return 0;
}