# String in C

- [String in C](#string-in-c)
  - [Strings Initialization](#strings-initialization)
  - [Input](#input)
  - [String Traversal](#string-traversal)
  - [Cpp String is `Mutable`](#cpp-string-is-mutable)

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

## Cpp String is `Mutable`

```cpp
    string s = "Hello";
    cout << s << endl;
    s[0] = 'X';
    cout << s << endl;// Xello
    s.append(" World");
    cout << s << endl;// Xello World
    return 0;
```

