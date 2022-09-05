#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    if (a.length() == b.length()) {
        return a < b;
    }
    return a.length() > b.length();
}

int main() {
    //!CIN->single world and GETLINE->single line----------------------
    cout << "CIN->single world and GETLINE->single line-------------------" << endl;
    string w;
    string line;
    string line2;

    cout << "ERROR!! line[cin]+line[cin]+x[cin]-------------------------" << endl;
    cout << "1. enter: 'a line'" << endl;
    cin >> line;
    cout << "2. enter: 'a line'" << endl;
    cin >> line2;
    cout << endl
         << "1. output: " << line << endl;
    cout << "2. output: " << line2 << endl;
    cout << endl
         << "x. enter: 'a line'" << endl;
    cin >> w;
    cout << "x. output: " << w << endl;
    cout << endl;

    // ERROR!! line[cin]+line[cin]+x[cin]-----------------
    //      1. enter: 'a line'
    // in-> a line
    //      2. enter: 'word'
    // in->                     <--error
    //      1. output: a        <--error
    //      2. output: line     <--error
    //      x. enter: 'a line'
    // in-> a line
    //      x. output: a        <--error

    cout << "RESOLVE!!line[cin]+discard+line[getline]+x[cin]-----------------" << endl;
    cin.ignore(100, '\n');
    cout << "discarded all above" << endl;
    //clear buffer before taking new line
    //?cin.ignore(n,delim)
    /**
     * ?n:
     * number of characters to discard.If this is exactly
     * numeric_limits<streamsize>::max(), there is no limit:
     * As many characters are extracted as needed until delim
     * (or the end-of-file) is found.
     *
     * ?Delimiting character:
     * The function stops extracting characters
     * as soon as an extracted character compares equal to this.
    */

    cout << "1. enter: 'a line'" << endl;
    cin >> line;
    cout << "2. enter: 'a line'" << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, line2);
    cout << endl
         << "1. output: " << line << endl;
    cout << "z: discarded: 'line' form 'a line' in 1." << endl;
    cout << "2. output: " << line2 << endl
         << endl;

    cout << "CLEAN!!! Single Line Inputs: !!----------------------------------" << endl;
    cout << "enter:'a line'" << endl;
    getline(cin, line);
    cout << "output: " << line << endl;
    cout << "enter:'a line'" << endl;
    getline(cin, line);
    cout << "output: " << line << endl;
    cout << endl;

    cout << "Array of String!! [Taking multiple lines at once]: " << endl;
    cout << "Enter no. of line to take input:" << endl;
    int n;
    cin >> n;
    cin.get();

    string s[100]; //Array of String

    for (int i = 0; i < n; i++) {
        getline(cin, s[i]);
    }
    cout << endl
         << "output: " << endl;
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }

    //Sorting Array of String
    sort(s, s + n, compare);
    cout << endl
         << "sorted: " << endl;
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }
}
