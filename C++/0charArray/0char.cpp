#include <bits/stdc++.h>
using namespace std;

int main() {
    // Character Array:
    // char s[100];
    // char s[4] ={'A','B','D'};
    // char s[] = {'A','B','C'};
    // char s[]="Welcome";
    // char s[8]="Welcome";
    int b[] = {1, 2, 3};
    cout << b << endl; //address of b[0]

    char c_garbage[] = {'a', 'b', 'c'};
    cout << c_garbage << endl; //abc☺

    char c[] = {'a', 'b', 'c', '\0'};
    cout << c << endl;

    char s[] = "abc";
    cout << s << endl;

    cout << "size of " << c << " = " << sizeof(c) << endl;
    cout << "size of " << s << " = " << sizeof(s) << endl;
    cout << "strlen: " << strlen(s) << endl;
    //size() and length() both return the length of the std::string

    /**
    * strlen() searches for that NULL character and counts the number of memory address passed,
    * So it actually counts the number of elements present in the string before the NULL character,
    *  here which is 3.
    *
    * sizeof() operator returns actual amount of memory allocated for the operand passed to it.
    * Here the operand is an array of characters which contains 4 characters including Null character
    * and size of 1 character is 1 byte. So, here the total size is 4 bytes.
*/

    //! Convert string to char array in C++
    /**
    * Method 1 
    * A way to do this is to copy the contents of the string to char array. 
    * This can be done with the help of c_str() and strcpy() function of library cstring. 
    * The c_str() function is used to return a pointer to an array that contains a null 
    * terminated sequence of character representing the current value of the string.
    * 
    */
    // assigning value to string s
    string ss = "Convert string to char array";

    int n = ss.length();

    // declaring character array
    char char_array[n + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array, ss.c_str());

    for (int i = 0; i < n; i++)
        cout << char_array[i];

    //!Input
    char s1[10];
    cin >> s1;
    cout << s1 << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Get One Charater: " << endl;
    char c1 = cin.get();
    cout << c1 << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    /**
     * cin.get() is used for accessing character array.
     * It includes white space characters.
     *  Generally, cin with an extraction operator (>>)
     *  terminates when whitespace is found. 
     * However, cin.get() reads a string with 
     * the whitespace.
    */
    cout << "line: " << endl;
    char line[25];
    cin.get(line, 25);
    cout << line << endl;

    /**
     * get() extracts char by char from a stream and 
     * returns its value (casted to an integer) whereas
     * getline() is used to get a line from a file line 
     * by line. Normally getline is used to filter 
     * out 'delimiters' in applications where you have 
     * a flat file(with thousands of line) and
     *  want to extract the output(line by line) 
     * using certain delimiter and then do some 
     * operation on it.
    */
    cout << "line: [until @ is found] " << endl;
    char line1[25];
    cin.getline(line1, 25, '@');
    cout << line1;
}
// 0x61fe10
// abc☺
// abc
// abc
// size of abc = 4
// size of abc = 4
//>> abc
//   abc
// Get One Charater:
//>> a
//   a
// line:
//>> hello world
//   hello world
// line: [until @ is found]
//>> hello wold this is @ in the line
//   hello wold this is