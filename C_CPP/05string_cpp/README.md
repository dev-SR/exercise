# String in C

- [String in C](#string-in-c)
  - [Strings Initialization](#strings-initialization)
  - [Input](#input)
  - [String Traversal](#string-traversal)
  - [Modifying String](#modifying-string)
    - [Cpp String is `Mutable`](#cpp-string-is-mutable)
  - [Searching](#searching)
  - [Extracting Substrings](#extracting-substrings)
  - [String<->Number Conversion](#string-number-conversion)

Docs:

  - [https://cplusplus.com/reference/string/string/](https://cplusplus.com/reference/string/string/)


## Strings Initialization

```cpp
string s0;
s0 = "late init";

string s1("hello"); // or string s1{"hello"};
string s2 = "Hello World";

// initialization by another string
string s3(s2); // or {s2}

// initialization by part of another string
// [Str,start_index,no_of_chars_from_Str]
string s6(s2, 6, 6); // World

// char array to string
char a[] = "abc";
string s4 = a;

//concatenation
string s9 = s0 + s1 + s2 + s3 + s4;


// initialization by character with number of occurrence
string s5(5, '#'); // ######  or   s(4, 65) -> AAAA

// initialization by part of another string : iterator version
string s7(s2.begin(), s2.begin() + 5); // Hello

// Reverse Using  reverse iterators
string rev = string(s2.rbegin(), s2.rend()); // dlroW olleH

// assign a new value to the string, replacing its current contents.
// assign(str, pos, len);
string r = "old";
string b = "new-string";
r.assign(b, 0, 4); // new-
```

## Input

- Read a Char - `cin.get()`
- Read a Char Array - `cin.getline(char_array, size, delimiter)`
- Read a String - `cin`, `getline(cin, string_variable, delimiter)`

```cpp
string word;
cout << "Enter a word: ";
cin >> word;
cout << word << endl;
// discards the input buffer
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Enter a sentence: ";
string sentence;
getline(cin, sentence);
cout << sentence << endl;

cout << "Enter a paragraph: ";
string paragraph;
getline(cin, paragraph, '.');
cout << paragraph << endl;
```

```bash
Enter a word: this is a word
this
Enter a sentence: this is a sentence
this is a sentence
Enter a paragraph: this is a long
paragraph.
this is a long
paragraph
```

## String Traversal


```cpp
	// char[] vs string traversal
    char s[] = "hello";
    for (int i = 0; i < strlen(s); i++) {
        cout << s[i] << " ";
    }
    cout << endl;
    // or
    for (int i = 0; i < s[i] != '\0'; i++) {
        cout << s[i] << " ";
    }
    cout << endl;

	//string traversal

    string s1 = "hello";
    for (int i = 0; i < s1.length(); i++) {
        cout << s1[i] << " ";
    }
    cout << endl;
    // using for each loop
    for (char c : s1) {
        cout << c << " ";
    }
    cout << endl;
    // using iterators
    for (auto it = s1.begin(); it != s1.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;
    cout << "-> Modifying Without reference: for(char c:s)  " << endl;
    for (char c : s1) {
        if (c >= 'a') {
            c -= 32;
        }
        cout << c << " "; // H E L L O
    }
    cout << endl;
    cout << "After Modification:" << endl;
    for (char c : s1) {
        cout << c << " "; // h e l l o
    }
    cout << endl;
    cout << "-> Modifying With Reference: for(char &c:s)" << endl;
    for (char &c : s1) {
        if (c >= 'a') {
            c -= 32;
        }
        cout << c << " "; // H E L L O
    }
    cout << endl;
    cout << "After Modification:" << endl;
    for (char c : s1) {
        cout << c << " "; // H E L L O
    }
```

## Modifying String

```cpp
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
```

### Cpp String is `Mutable`

```cpp
    string s = "Hello";
    cout << s << endl;
    s[0] = 'X';
    cout << s << endl;// Xello
    s.append(" World");
    cout << s << endl;// Xello World
    return 0;
```

- See more here: [char s[] vs char *s](https://github.com/dev-SR/exercise/tree/main/C%2B%2B/1.5char-charArr-cString#char-smutable-vs-char-simmutable)

## Searching

```cpp
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
```

```cpp
int main() {
    string name = "Jhon Smith.";
    // find first occurrence of any of the characters in the string
    cout << "Pos. of first occurrence of any of the vowels is: " << name.find_first_of("aeiou") << endl; // 2
    cout << name.find_last_of(".;,") << endl;                                                            // 10
    cout << name.find_first_not_of("Jhon") << endl;                                                      // 4
    cout << name.find_last_of("Smith") << endl;                                                          // 9
    cout << name.find_last_not_of("Smith.") << endl;                                                     // 4
}
```

## Extracting Substrings

```cpp
#include <iostream>
using namespace std;

int main() {
    string name = "Jhon Snow Smith";
    size_t index = name.rfind(' ');

    // substr(pos, len) returns a substring of length len starting at pos
    // extract first name
    string first_name = name.substr(0, index);
    // extract last name
    string last_name = name.substr(index + 1);

    cout << "(" << first_name << ")" << endl; // (Jhon Snow)
    cout << "(" << last_name << ")" << endl;  // (Smith)

    return 0;
}
```

## String<->Number Conversion

```cpp

#include <iostream>
using namespace std;

int main() {

    string price = "123.45";
    double price_d = stod(price);
    cout << price_d + 1 << endl; // 124.45

    string price2 = "123.x45";
    double price2_d = stod(price2);
    cout << price2_d << endl; // 123

    int i = 123;
    string s = to_string(i);
    cout << s.insert(0, "N: ") << endl; // N: 123

    return 0;
}
```