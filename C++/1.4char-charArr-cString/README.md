# char, char[], C-Type String

- [char, char[], C-Type String](#char-char-c-type-string)
  - [Character Data Type](#character-data-type)
    - [Reading a Char using `cin.get()`](#reading-a-char-using-cinget)
    - [Ctype headers](#ctype-headers)
    - [Problems](#problems)
      - [Problems 1 : Shortest Path](#problems-1--shortest-path)
  - [C-Style Strings / Char[]](#c-style-strings--char)
    - [Initializing a C-Style String](#initializing-a-c-style-string)
    - [user input](#user-input)
      - [cin](#cin)
      - [cin.getline(arr,len)](#cingetlinearrlen)
      - [cin.getline(arr,len,delim)](#cingetlinearrlendelim)
      - [clearing input buffer🚀🚀](#clearing-input-buffer)
    - [CString Library Functions](#cstring-library-functions)
    - [🌟🌟`char s[]` vs `char *s`](#char-s-vs-char-s)
    - [`std::string` vs `char[]`](#stdstring-vs-char)
    - [🚀🚀Array of String : 2D Array of Characters/Array of Pointers to Strings](#array-of-string--2d-array-of-charactersarray-of-pointers-to-strings)

## Character Data Type

Ascii Encoding:

```cpp
int main() {
    char ch = 'A';
    char newLineChar = '\n';
    cout << (int)ch << endl;          // 65
    cout << (int)newLineChar << endl; // 10
    cout << sizeof(char) << endl;     // 1
    cout << sizeof(ch) << endl;       // 1
    cout << ch + 1 << endl;//66
    ch = ch + 1;
    cout << ch << endl;//B

    cout << "Letters" << endl;
    for (int i = 0; i < 128; i++) {
        cout << i << " - " << (char)i << endl;
    }

    return 0;
}
```

### Reading a Char using `cin.get()`

**cin.get() vs cin:**

- `cin.get()` reads all possible type of characters including `whitespace`.

- Generally, `cin` with an extraction operator `(>>)` **ignores when whitespace is found**. However, `cin.get()` **reads a string with the whitespace**.

```cpp
 char ch;
 ch = cin.get();
 cout << (int)ch << endl;
```

Now if Input whitespace is given `" "` and `Enter` is pressed Output will be `32`

```cpp
 char ch;
 cin >> ch;
 cout << (int)ch << endl;
```

But with `cin` Now if Input whitespace is given `" "` and `Enter` is pressed  nothing will happen as `cin` ignores the whitespace and continues to read the next character.

```cpp
char ch;
ch = cin.get();
if (ch == ' ') {
 cout << "Whitespace" << endl;
} else if (ch == '\n') {
 cout << "Newline" << endl;
} else if (ch >= 'A' && ch <= 'Z') {
 cout << "Uppercase letter" << endl;
} else if (ch >= 'a' && ch <= 'z') {
 cout << "Lowercase letter" << endl;
} else if (ch >= '0' && ch <= '9') {
 cout << "Digit" << endl;
} else {
 cout << "Special character" << endl;
}
```

### Ctype headers

`#include <cctype>`

- `isalnum` checks if a character is alphanumeric
- `isalpha` checks if a character is alphabetic
- `islower` checks if a character is lowercase
- `isupper` checks if a character is an uppercase character
- `isdigit` checks if a character is a digit
......

- [https://en.cppreference.com/w/cpp/header/cctype](https://en.cppreference.com/w/cpp/header/cctype)

```cpp
char ch;
ch = cin.get();//a
// Testing
if (isupper(ch)) {
 cout << "Uppercase" << endl;
} else if (islower(ch)) {
 cout << "Lowercase" << endl;//Lowercase
} else if (isdigit(ch)) {
 cout << "Digit" << endl;
} else {
 cout << "Special character" << endl;
}
// Conversion
ch = toupper(ch);
cout << ch << endl;//A
```

### Problems

#### Problems 1 : Shortest Path

Suppose you want to go to a location, located at `(X,Y)` starting from origin `(0,0)`. Your friend tells
you a long way by telling the steps you should walk in each direction (N,W,E or S). Find the shortest path.
Input & Output is a string. Refer Example:

- Input: `NNNEEWS`
- Output: `NNE`

<div align="center">
<img src="img/p.jpg" alt="p.jpg" width="400px">
</div>

```cpp
char ch = cin.get();
int x = 0, y = 0;
while (ch != '\n') {
 switch (ch) {
 case 'N':
  y++;
  break;
 case 'S':
  y--;
  break;
 case 'E':
  x++;
  break;
 case 'W':
  x--;
  break;
 }
 ch = cin.get();
}
cout << "X: " << x << " Y: " << y << endl;

if (x >= 0 && y >= 0) {

 //go in x direction
 for (int cnt = 1; cnt <= x; cnt++) {
  cout << "E";
 }
 //go in y direction
 for (int cnt = 1; cnt <= y; cnt++) {
  cout << "N";
 }
}
```

```bash
NNNEEWS
X: 1 Y: 2
ENN
```

## C-Style Strings / Char[]

- Sequence of characters stored in continguous memory (character array)
- Need to **explicitly** terminate by a `null` character.
- Character Arrays support **read**, **write** & **update**.

String Literals:

- Sequence of characters written in double quotes.
- Stored in **read only memory**
- Terminated by a Null Character

UnderStanding Null terminated:

```cpp
int n[10];
cout << n << endl; // address
char names[10];
cout << names << endl; //garbage
```

### Initializing a C-Style String

```cpp
char name[]{"Jhon"}; //(invalid in c)      // <-- string literal
char name2[] = "Jhon";                     // <-- string literal
char name3[] = {'J', 'h', 'o', 'n', '\0'}; // <-- char array ; explicit null
                                           // termination is required

// uses loop to print whole array
cout << name << endl;
cout << strlen(name) << endl; // 4
// in c
printf("%s\n", name2);
printf("%s\n", name3);
```

### user input

- `WORD`: use `cin` if you want to read a word (**no spaces**)
- `LINE` :use `cin.getline(arr,len)` if you want read a sentence (**including spaces**)
- `PARAGRAPH` :use `cin.getline(arr,len,delim)` if you want read a sentence (**including spaces**)

#### cin

```cpp
char word[100];
/**
 * directly input a list of characters and get it store inside the array
 * automatically; terminates with whitespace
 *
*/
cin >> word;          // hello how are you?
cout << word << endl; // hello
```

#### cin.getline(arr,len)

```cpp
char line[100];
cin.getline(line, 100); // hello how are you?
cout << line << endl;   // hello how are you?
```

#### cin.getline(arr,len,delim)

```cpp
char para[100];
cin.getline(para, 100, '.');
cout << endl << para << endl; //
```

```bash
I like coding
My favorite languages are C++, Java
Happy coding.

I like coding
My favorite languages are C++, Java
Happy coding
```

#### clearing input buffer🚀🚀

Problems arise when we want to read a word but give a sentence as input. In that case only the first word will be read by `cin`, rest of the sentence will be in `buffer`. Then if we try to read the next word/sentence, it will be read from the `buffer` and not from the keyboard.

```cpp
char username[20];
char fullName[100];
cin >> username;            // << dev-sr new
cout << username << endl;   // >> dev-sr
cin.getline(fullName, 100); // << (X)  do not takes input as reads from previous input (buffer)
cout << fullName << endl;   // >>   new  <- prints from buffer
```

Clearing Input Buffer:

```cpp
char username[20];
char fullName[100];
cin >> username;          // << dev-sr new
cout << username << endl; // >> dev-sr
// discards the input buffer
cin.ignore(numeric_limits<streamsize>::max(), '\n');
// in c
// while ((getchar()) != '\n');
cin.getline(fullName, 100); // << soikat rahman
cout << fullName << endl;   // >> soikat rahman
```

- [https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/](https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/)
- [https://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer](https://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer)

### CString Library Functions

[https://www.cplusplus.com/reference/cstring/](https://www.cplusplus.com/reference/cstring/)

```cpp
char name[100];
// name = "Jhon"; // error: char[100] is not assignable
//Copying:
strcpy(name, "Jhon");
cout << name << endl; // Jhon
//Concatenating:
strcat(name, " Smith");
cout << name << endl; // Jhon Smith
```

finding substring:

```cpp
char sentence[100] = "I love reading books on science";
char word[100];
cin >> word; // books

/*
    cout << strstr(sentence, word); // books on science

    strstr() returns a `pointer` to the first occurrence of the substring in the string.
    That's why it print `books on science`
*/

char *output = strstr(sentence, word);
if (output != NULL) {
    cout << word << " is found" << endl;
} else {
    cout << "Not found" << endl;
}
```

### 🌟🌟`char s[]` vs `char *s`

- [https://www.geeksforgeeks.org/whats-difference-between-char-s-and-char-s-in-c/](https://www.geeksforgeeks.org/whats-difference-between-char-s-and-char-s-in-c/)
- [https://overiq.com/c-programming-101/character-array-and-character-pointer-in-c/](https://overiq.com/c-programming-101/character-array-and-character-pointer-in-c/)
- [https://kelvinson.github.io/algos/2019/06/chars-arrays-string/](https://kelvinson.github.io/algos/2019/06/chars-arrays-string/)

```cpp
    char arr[] = "hello"; // array version
    char *ptr = "hello";  // pointer version

    printf("%s\n", arr); // hello
    printf("%s\n", ptr); // hello
```

The similarity is:

The type of both the variables is a pointer to char or (char*), so you can pass either of them to a function whose formal argument accepts an array of characters or a character pointer.

Here are the differences:

<div align="center">
<img src="img/char.jpg" alt="char.jpg" width="800px">
</div>

Assignment in details

<div align="center">
<img src="img/char_1.jpg" alt="char_1.jpg" width="800px">
</div>

### `std::string` vs `char[]`

- `char[]` can convert to `std::string` implicitly,
- `std::string` can convert to `char[]` with `.c_str()` or `.data()`

```cpp
char hello[] = "hello";
string str_hello = hello;           //char[] can implicitly converted to string

auto hello1 = str_hello.c_string();
char *hello2 = str_hello.data();
```

### 🚀🚀Array of String : 2D Array of Characters/Array of Pointers to Strings

```cpp
char options[][10] = {"MEDIUM", "HARD", "EASY", "TOUGH"};
// options[3] = "VERY HARD";   // invalid
char choose[10];
cin >> choose;
for (int i = 0; i < 4; i++) {
    if (strcmp(choose, options[i]) == 0) {
        cout << "You choose: " << options[i] << endl;
        break;
    }
}
```

alternative in c :

```cpp
char options[][10] = {{'M', 'E', 'D', 'I', 'U', 'M','\0'},
                      {'H', 'A', 'R', 'D', '\0'},
                      {'E', 'A', 'S', 'Y', '\0'}};
```

Array of Pointers to Strings in C:

```cpp
    char *options[] = {"MEDIUM", "HARD", "EASY", "TOUGH"};
    options[3] = "VERY HARD"; //ok

    for (int i = 0; i < 5; i++) {
        printf("%s\n", options[i]);
    }

    scanf("%s", options[0]);  // invalid
    strcpy(options[0], "M");  // invalid
    gets(options[0]);         // invalid
    strcat(options[0], "S");  // invalid

```

<div align="center">
<img src="img/aps.jpg" alt="aps.jpg" width="500px">
</div>

- [https://overiq.com/c-programming-101/array-of-pointers-to-strings-in-c/](https://overiq.com/c-programming-101/array-of-pointers-to-strings-in-c/)

In C++:

```cpp
string op[] = {"MEDIUM", "HARD", "EASY"};
char choose[10];
cin >> choose;
for (int i = 0; i < 4; i++) {
    if (strcmp(choose, op[i].c_str()) == 0) {// c_str() converts string to char*
        cout << "You choose: " << options[i] << endl;
        break;
    }
}
//or comparing string == string
string ch;
cin >> ch;
for (int i = 0; i < 4; i++) {
    if (ch == op[i]) {
        cout << "You choose: " << options[i] << endl;
        break;
    }
}
```

In Java:

```java
String[] ops = {"MEDIUM", "HARD", "EASY"};
```