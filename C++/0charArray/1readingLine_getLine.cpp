#include <bits/stdc++.h>
using namespace std;
void readline(char a[], int maxLen, char delim = '\n') {
    int i = 0;
    char ch = cin.get();

    while (ch != delim) {
        a[i] = ch;
        i++;
        if (i == (maxLen - 1)) {
            break;
        }
        ch = cin.get();
    }
    a[i] = '\0';
    return;
}
int main() {
    char a[100];
    cout << "\\n as delimeter: " << endl;
    readline(a, 100);
    cout << a << endl;
    cout << endl;
    char b[100];
    cout << "# as delimeter: " << endl;
    readline(b, 100, '#');
    cout << endl;
    cout << b << endl;

    //
    char c[100];
    cout << "In-built(): " << endl;
    cin.getline(c, 100, '#');
    cout << endl;
    cout << c << endl;
}

//OUTPUT:

// \n as delimeter:
//>> hello world
//   hello world

// # as delimeter:
//>> this is a para
//>> to test delimeter . #

// this is a para
// to test delimeter .

// In-built():
//>> this a is para
//>> to test built-in getline. #

// this a is para
// to test built-in getline.