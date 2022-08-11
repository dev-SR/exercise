# char, char[], string

<div id='up'></div>

- [char, char[], string](#char-char-string)
  - [Character Data Type](#character-data-type)
    - [Reading a Char using `cin.get()`](#reading-a-char-using-cinget)
    - [Ctype headers](#ctype-headers)
    - [Problems](#problems)
      - [Problems 1 : Robot’s Grid Traversal](#problems-1--robots-grid-traversal)
      - [Problems 2 : Shortest Path](#problems-2--shortest-path)
  - [🌨️C-Style Strings / Char[]🌨️](#️c-style-strings--char️)
    - [Initializing and Accessing a C-Style String](#initializing-and-accessing-a-c-style-string)
    - [🌟🌟🌟`char s[]`(Mutable) vs `char *s`(Immutable)](#char-smutable-vs-char-simmutable)
    - [`std::string` vs `char[]`](#stdstring-vs-char)
    - [👉Input - Cpp](#input---cpp)
      - [cin](#cin)
      - [cin.getline(arr,len)](#cingetlinearrlen)
      - [cin.getline(arr,len,delim)](#cingetlinearrlendelim)
    - [👉Input - C](#input---c)
      - [Single Word | Taking Input as `char array` vs `char pointer`](#single-word--taking-input-as-char-array-vs-char-pointer)
      - [Single Line](#single-line)
        - [`gets`](#gets)
        - [`fgets`](#fgets)
        - [`scanf("%[^\n]",s);`](#scanfns)
      - [Multiple Lines](#multiple-lines)
      - [`getchar`](#getchar)
    - [👉clearing input buffer🚀](#clearing-input-buffer)
      - [C: Using `getchar()` | `while ((getchar()) != '\n')`](#c-using-getchar--while-getchar--n)
      - [CPP: Using ` cin.ignore(numeric_limits::max(),'\n'); `](#cpp-using-cinignorenumeric_limitsmaxn)
    - [🚀Array of String](#array-of-string)
      - [Using 2D Char Array | Array of Pointers to Strings](#using-2d-char-array--array-of-pointers-to-strings)
      - [String[] in Cpp](#string-in-cpp)
      - [Input: 2D Char Array | C](#input-2d-char-array--c)
      - [Input: Array of Pointers to Strings | C](#input-array-of-pointers-to-strings--c)
    - [🖐️CString Example](#️cstring-example)
      - [lowercase to uppercase](#lowercase-to-uppercase)
      - [binary to decimal](#binary-to-decimal)
      - [String Len](#string-len)
      - [String Copy](#string-copy)
      - [String Concatenation](#string-concatenation)
      - [String Comparison](#string-comparison)
      - [Palindrome](#palindrome)
      - [Problem 1](#problem-1)
    - [🌟CString Library Functions](#cstring-library-functions)

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
    char lowerCase = 'c';
    cout<< 'A' + (lowerCase - 'a') << endl; //C ; 65 + (99 - 97) => 65 + 2 = 67 => C
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

#### Problems 1 : Robot’s Grid Traversal

```bash
Given, a N*N Grid
0,0----------(0,N)
| ---------------- |
| ---------------- |
| ---------------- |
| ---------------- |
(N,0)---------(N,N)


A robot starting from (x,y) position, after moving U|D|R|L reaches (x',y') position
Take input initial(x,y) position and directions that the robot will move,
then print the final position (x',y')

# direction is in term of 2d array index arr[x][y] ; move down means x++

Example:
Move the robot in U|D|R|L direction (q to stop):
D
moved 🡣
R
moved 🡢
D
moved 🡣
R
moved 🡢
q
Final postion of the robot is: 4,4
```

```cpp
#include <stdio.h>
/*

 */
int main() {
    int x, y;
    char c;
    printf("Enter the initial position: ");
    scanf("%d %d", &x, &y);

    printf("Move the robot in U|D|R|L direction (q to stop):\n");
    while (1) {
        scanf("%c", &c);
        if (c == 'q')
            break;
        else if (c == 'U') {
            x--; // direction in term of 2d array index arr[x][y]
            printf("moved 🡡\n");
        }

        else if (c == 'D') {
            x++;
            printf("moved 🡣\n");

        } else if (c == 'R') {
            y++;
            printf("moved 🡢\n");

        } else if (c == 'L') {
            y--;
            printf("moved 🡠\n");
        }
    }
    printf("Final postion of the robot is: %d,%d", x, y);

    return 0;
}

```

**Grid with Obstacles:** Now consider if some obstacles are added to the grids; robot will not move through the obstacles and the robot will stay on the same cell after moving through an obstacle.

Sample:

```bash
Enter the initial position: 0 0
Please enter number of blocked cells:2
0 1
2 0
1 0 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
0 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
Move the robot in U|D|R|L direction (q to stop):
R
Obstacle ahead 🚩
D
moved 🡣
D
Obstacle ahead 🚩
R
moved 🡢
D
moved 🡣
q
Final postion of the robot is: 2,1
```

```c
#include <stdio.h>
int main() {
    int x, y;
    char c;
    printf("Enter the initial position: ");
    scanf("%d %d", &x, &y);

    int grid[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j] = 1;
        }
    }

    int n;
    printf("Please enter number of blocked cells:");
    scanf("%d", &n);
    int x_block, y_block;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x_block, &y_block);
        grid[x_block][y_block] = 0;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    printf("Move the robot in U|D|R|L direction (q to stop):\n");
    while (1) {
        scanf("%c", &c);
        if (c == 'q')
            break;
        else if (c == 'U') {
            if (grid[x - 1][y]) {
                x--;
                printf("moved 🡡\n");
            } else {
                printf("Obstacle ahead 🚩\n");
            }
        }

        else if (c == 'D') {
            if (grid[x + 1][y]) {
                x++;
                printf("moved 🡣\n");
            } else {
                printf("Obstacle ahead 🚩\n");
            }

        } else if (c == 'R') {
            if (grid[x][y + 1]) {
                y++;
                printf("moved 🡢\n");
            } else {
                printf("Obstacle ahead 🚩\n");
            }

        } else if (c == 'L') {
            if (grid[x][y - 1]) {
                y--;
                printf("moved 🡠\n");
            } else {
                printf("Obstacle ahead 🚩\n");
            }
        }
    }
    printf("Final postion of the robot is: %d,%d", x, y);

    return 0;
}
```

#### Problems 2 : Shortest Path

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

## 🌨️C-Style Strings / Char[]🌨️

[☝️ Top ☝️](#up)

**`{'J', 'h', 'o', 'n', '\0'}`:**

- Sequence of characters stored in contiguous memory (character array)
- Need to **explicitly** terminate by a `null` character.
- Character Arrays support **read**, **write** & **update**.

**String Literals:`"Jhon"`**

- Sequence of characters written in double quotes.
- Stored in **read only memory**
- Terminated by a Null Character

UnderStanding `Null` terminated `char` array

```cpp
int n[10];
cout << n << endl; // address
char names[10];
cout << names << endl; //garbage
```

### Initializing and Accessing a C-Style String

[☝️ Top ☝️](#up)

```cpp
    char name[]{"Jhon"};                       //<-- string literal (invalid in c)
    char name2[] = "Jhon";                     // <-- string literal
    char name3[] = {'J', 'h', 'o', 'n', '\0'}; // <-- char array ; explicit null termination is required
    char name4[] = {'J', 'h', '\n', 'o', 'n', '\0'};

    // uses loop to print whole array
    cout << name << endl;         // Jhon
    cout << name4 << endl;        // Jh'\n'on
    cout << strlen(name) << endl; // 4
    // in c
    printf("%s\n", name2); // Jhon
    printf("%s\n", name3); // Jhon
    printf("%s\n", name4); // Jh'\n'on

    //Accessing character in a String
    name2[0] = 'X';
    printf("%s\n", name2); // Xhon
```

### 🌟🌟🌟`char s[]`(Mutable) vs `char *s`(Immutable)

[☝️ Top ☝️](#up)

- [https://stackoverflow.com/questions/10186765/what-is-the-difference-between-char-array-and-char-pointer-in-c](https://stackoverflow.com/questions/10186765/what-is-the-difference-between-char-array-and-char-pointer-in-c)
- [https://www.geeksforgeeks.org/whats-difference-between-char-s-and-char-s-in-c/](https://www.geeksforgeeks.org/whats-difference-between-char-s-and-char-s-in-c/)
- [https://overiq.com/c-programming-101/character-array-and-character-pointer-in-c/](https://overiq.com/c-programming-101/character-array-and-character-pointer-in-c/)
- [https://kelvinson.github.io/algos/2019/06/chars-arrays-string/](https://kelvinson.github.io/algos/2019/06/chars-arrays-string/)

In c string is a **fixed size array of characters**. and the **array name** represent the **address of the first character**. Therefore, we can assign the address of the string to a pointer directly.The type of both the variables is a pointer to char or (char*), so you can pass either of them to a function whose formal argument accepts an array of characters or a character pointer.

```cpp
    char arr[] = "hello"; // array version
    char *ptr = "hello";  // assigning the address of the string to a pointer directly

    printf("%s\n", arr); // hello
    printf("%s\n", ptr); // hello

    // thing to note
    char c = 'a';
    char *p = &c;
    printf("%c\n", *p); // a
    // But
    char *cc = 'A'; // warning: initialization of 'char *' from 'int' makes pointer from integer without a cast
    printf("%c\n", *cc);
    return 0;

```

But char array`char s[]` and  char pointer `char *s` are not the same thing.

Here are the differences:

<div align="center">
<img src="img/char.jpg" alt="char.jpg" width="800px">
</div>

Assignment in details

<div align="center">
<img src="img/char_1.jpg" alt="char_1.jpg" width="800px">
</div>

See the mutability and immutability of `char s[]` and `char *s`

```c
    char a[] = "hello";
    a[0] = 'x'; // ok
    a = "another"; // error: assignment to expression with array type
    // this limitation can be overcome `strcpy()`; see below
    printf("%s\n", a); // xello

    const char s[] = "hello";
    s[0] = 'x'; // error: assignment of read-only location 's[0]'
    s = "another"; // error: assignment to expression with array type
    printf("%s\n", s);

    char *ss = "hello";
    ss[0] = 'x'; //runtime error
    ss = "another";     // OK
    printf("%s\n", ss); // another
    //here "hello" is `Immutable`

    const char *sss = "hello";
    sss[0] = 'x'; //compile time error :  error: assignment of read-only location '*sss'
    sss = "another";
    printf("%s\n", sss);
```

See the difference in **taking input** for `char s[]` and `char *s` here: [Taking Input as `char array` vs `char pointer`](#single-word--taking-input-as-char-array-vs-char-pointer)

<details>
  <summary><b>"char *s" is 🚀immutable🚀</b></summary>

We can say `char *s` is `immutable`. Immutable simply means **unmodifiable**. Once String is created its data can't be changed but a new String can be assigned as `ss` is just a pointer

```c
    char *s = "Hello";
    // s[0] = 'X'; // undefined behavior
    s = "another";
    printf("%s", s);

```

</details>

<details>
    <summary><b>"char s[]" is 🚀mutable🚀</b></summary>

```c
    char ch[20] = "Hello";
    ch[0] = 'X';
    printf("%s\n", ch); // Xello
```

Although `char s[]` is `mutable` , we can't perform operation like assignment or concatenation of a new string to it.This limitation can be overcome by function like `strcpy()` ,`strcat()` :

```c
    char ch[20] = "Hello";
    ch[0] = 'X';
    printf("%s\n", ch); // Xello
    strcat(ch, " World");
    printf("%s\n", ch); // Xello World
    strcpy(ch, "Hello World");
    printf("%s\n", ch); // Hello World
```

See when `strcpy` is need here [String Copy](#string-copy)
</details>

<details>
<summary><b>CPP string is 🚀 mutable🚀</b></summary>

```cpp
int main() {
    string s = "Hello";
    cout << s << endl;
    s[0] = 'X';
    cout << s << endl;// Xello
    s.append(" World");
    cout << s << endl;// Xello World
    return 0;
}
```

- [stackoverflow | Are C++ strings mutable UNLIKE Java strings?](https://stackoverflow.com/questions/28442719/are-c-strings-mutable-unlike-java-strings#:~:text=You%20can%20modify%20the%20string,into%20a%20mutable%20char%20array.)


</details>


<details>
<summary><b>Java String is 🚀immutable🚀</b></summary>
```java
   String s="Hello";
   //   s[0] = 'X'; // error: array required, but String found
   s.concat(" World");
   System.out.println(s);//will print `Hello` because strings are immutable objects
```

```java
//   therefore we have to change it completely
    String s = "Hello";
    s = s.concat (" World");
    System.out.println (s); //Hello World
```
</details>


<details>
<summary><b>Python String is 🚀immutable🚀</summary>


```python
s = "Hello"
# s[0] = 'X' #TypeError: 'str' object does not support item assignment
s + " World"
print(s) # Hello
s= s + " World"
print(s) # Hello World
```
</details>


### `std::string` vs `char[]`

[☝️ Top ☝️](#up)

- `char[]` can convert to `std::string` implicitly,
- `std::string` can convert to `char[]` with `.c_str()` or `.data()`

```cpp
char hello[] = "hello";
string str_hello = hello;           //char[] can implicitly converted to string

auto hello1 = str_hello.c_string();
char *hello2 = str_hello.data();
```

### 👉Input - Cpp

[☝️ Top ☝️](#up)

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

### 👉Input - C

[☝️ Top ☝️](#up)

- `WORD`: `scanf()` (**no spaces**)
- `LINE` :  (**including spaces**)
  - `gets()`
  - `scanf("%[^\n]s", str)`
- `PARAGRAPH` : `scanf("%[^\t|<r></r>]s", str)`
- `CHAR or CHAR By CHAR`: `getchar`

- [https://iq.opengenus.org/how-to-take-string-input-in-c/](https://iq.opengenus.org/how-to-take-string-input-in-c/)

#### Single Word | Taking Input as `char array` vs `char pointer`

The input function scanf can be used with `%s` format specification to read in a string of characters.

```c
    char firstName[10];
    char *secondName; // or char *secondName = "";

    printf("Enter FirstName:");
    scanf("%s", firstName);
    printf("Enter SecondName:");
    scanf("%s", secondName);
    printf("FirstName: %s, SecondName: %s", firstName, secondName);

    return 0;
```

```bash
Enter FirstName:soikat
Enter SecondName:rahman
FirstName: soikat, SecondName: (null)
```

Memory for `secondName` is not allocated and thus, we're trying to write in a non-authorized memory address. We're just declaring a pointer. You're not specifying how much memory to reserve for the string. We can statically declare this like `char firstName[10]` or dynamically allocate it like `char *secondName = (char *)malloc(10);`

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    char firstName[10];
    // char *secondName; // or char *secondName = "";
    char *secondName = (char *)malloc(10);
    printf("Enter FirstName:");
    scanf("%s", firstName);
    printf("Enter SecondName:");
    scanf("%s", secondName);
    printf("FirstName: %s, SecondName: %s", firstName, secondName);
    return 0;
}
```

- [https://stackoverflow.com/questions/10186765/what-is-the-difference-between-char-array-and-char-pointer-in-c](https://stackoverflow.com/questions/10186765/what-is-the-difference-between-char-array-and-char-pointer-in-c)
- [https://stackoverflow.com/questions/14707427/taking-string-input-in-char-pointer](https://stackoverflow.com/questions/14707427/taking-string-input-in-char-pointer)

The problem with the scanf function is that it terminates its input on the first white space it finds. A white space includes blanks,tabs,carraige returns,form feeds and new lines.

Therefore, if the following line of text is typed : `HELLO BOY`

then only the string `"HELLO"` will be read into the array address , since the blank space after the word 'NEW' will terminate the reading of string.
The unused locations are filled with garbage.

The scanf function automatically terminates the string that is read with a null character and therefore, the character array should be large enough to hold the input string plus the null character. Note that unlike previous scanf calls, in the case of character arrays, the ampersand `(&)` is not required before the variable name.

#### Single Line

- [https://www.geeksforgeeks.org/taking-string-input-space-c-3-different-methods/](https://www.geeksforgeeks.org/taking-string-input-space-c-3-different-methods/)

##### `gets`

Another method of reading **a string of text containing whitespaces** is to use the library function `gets`.

It reads characters from the keyboard until a **new line character** is encountered and then appends a null character to the string.
Unlike scanf, it does not skip whitespaces.

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    char fullName[20];
    printf("Enter your fullname:");
    gets(fullName);
    printf("%s", fullName);
    return 0;
}
```

> Note : `gets()` has been **removed** from `c11`. So it might give you a warning when implemented.
> We see here that it doesn’t bother about the size of the array. So, there is a chance of `Buffer Overflow`.

##### `fgets`

To overcome the above limitation, we can use `fgets` as :

- Syntax : `char *fgets(char *str, int size, FILE *stream)`
- Example : `fgets(str, 20, stdin)`; as here, 20 is MAX_LIMIT according to declaration.

```c
#include <stdio.h>
#define MAX_LIMIT 20
int main() {
    char fullName[MAX_LIMIT];
    char country[MAX_LIMIT];

    printf("Enter FullName:");
    fgets(fullName, MAX_LIMIT, stdin);
    printf("%s", fullName);
    printf("Enter Country Name:");
    fgets(country, MAX_LIMIT, stdin);
    printf("%s", country);

    return 0;
}

```

```c
Enter FullName:soikat rahman
soikat rahman
Enter Country Name:BD
BD
```

##### `scanf("%[^\n]",s);`

```c
int main() {
    char fullName[20];
    char country[20];
    printf("Enter your fullname:");
    scanf("%[^\n]", fullName);
    printf("%s\n", fullName);
    printf("Enter your country name:");
    scanf("%s", country);
    printf("%s", country);
}
```

Here, `[]`is the `scanset` character. `^\n` tells to take input until `newline` doesn’t get encountered. Here we used `^`(XOR -Operator ) which gives true until both characters are different. Once the character is equal to New-line (`‘\n’`),  `^` (XOR Operator ) gives false to read the string. So we use `“%[^\n]s”` instead of `“%s”`.

```bash
Enter your fullname:soikat rahman
soikat rahman
Enter your country name:BD
BD
```

#### Multiple Lines

- [http://www.c4learn.com/c-programs/accept-paragraph-using-scanf-in-c.html](http://www.c4learn.com/c-programs/accept-paragraph-using-scanf-in-c.html)

```c
#include <stdio.h>
int main() {
    char para[100];

    printf("Enter Paragraph :\n");
    scanf("%[^\t]s", para);

    printf("Accepted Paragraph : %s", para);

    return 0;
}
```

```bash
Enter Paragraph :
Hello World
this is an example of
multi-line input

Accepted Paragraph : Hello World
this is an example of
multi-line input
```

How ?: `scanf("%[^\t]s", para);`

- Here scanf will accept Characters entered with spaces.
- It also accepts the Words , new line characters .
- `%[^\t]s`  represent that all characters are accepted except `tab(t)`, whenever `t` will encountered then the process of accepting characters will be terminated.
- Press `tab` and then `enter` to terminate the process

Drawbacks :

- Paragraph Size cannot be estimated at Compile Time
- It’s vulnerable to buffer overflows

How to Specify Maximum Size to Avoid Overflow ?

```c
//------------------------------------
// Accepts only 10 Characters
//------------------------------------
scanf("%10[^\t]s", para);
```

```bash
Enter Paragraph :
aaaaaaaaaa aaaaaaaaa a aaaaaaaaaaaaa aaaaaaa
Accepted Paragraph : aaaaaaaaaa
```

#### `getchar`

```c
#include <stdio.h>
// #include <string.h>
void main() {
    char instr[100], ch;
    int i = 0;
    printf("Enter the line \n");
    do {
        ch = getchar();
        instr[i] = ch;
        i++;
    } while (ch != '\n');

    i = i - 1;
    instr[i] = '\0';
    printf("%s \n", instr);
}
```

```bash
Enter the line
hello world
hello world
```

### 👉clearing input buffer🚀

[☝️ Top ☝️](#up)

- [https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/](https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/)
- [https://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer](https://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer)

Problems arise when we want to read a word but give a sentence as input. In that case only the first word will be read by `cin`, rest of the sentence will be in `buffer`. Then if we try to read the next word/sentence, it will be read from the `buffer` and not from the keyboard.

```cpp
char username[20];
char fullName[100];
cin >> username;            // << hello world
cout << username << endl;   // >> hello
cin.getline(fullName, 100); // << (X)  do not takes input as reads from previous input (buffer)
//Or,  cin >> fullName;
cout << fullName << endl;   // >>   world  <- prints from buffer
```

incase of c:

```c
#include <stdio.h>
int main() {
    char str[80], ch;
    printf("Enter a word:");
    scanf("%s", str);
    printf("Enter a char:");
    ch = getchar();
    printf("Word:%s\n", str);
    printf("Char:%c", ch);
    return 0;
}
```

```bash
Enter a word:hello
Enter a char:Word:hello
Char:
```

How can it be resolved?

#### C: Using `getchar()` | `while ((getchar()) != '\n')`

```c
#include <stdio.h>
int main() {
    char str[80], ch;
    printf("Enter a word:");
    scanf("%s", str);
    // clearing input buffer; left over "\n" from previous input
    getchar(); // Discards '\n'
    printf("Enter a char:");
    ch = getchar();
    printf("Word:%s\n", str);
    printf("Char:%c", ch);
    return 0;
}
```

```c
Enter a word:hello
Enter a char:x
Word:hello
Char:x
```

single `getchar()` will read only one character from the keyboard that is the leftover '\n' from previous input. But if we input multiple words instead of a single word, then it cant  get rid of complete buffer left over from previous input.

```bash
Enter a word:hello world
Enter a char:Word:hello
Char:w
```

Here, `getchar()` only got rid of the leftover '\n' from previous input but 'world' is still in the buffer.

We can use `while ((getchar()) != '\n')` to clear  the input buffer completely.

```c
int main() {
    char str[80], ch;
    printf("Enter a word:");
    scanf("%s", str);
    // clearing input buffer; left over "\n" from previous input
    // getchar();
    while ((getchar()) != '\n'); // Discards '\n'
    printf("Enter a char:");
    ch = getchar();
    printf("Word:%s\n", str);
    printf("Char:%c", ch);
    return 0;
}
```

```bash
Enter a word:hello world
Enter a char:x
Word:hello
Char:x
```

#### CPP: Using ` cin.ignore(numeric_limits::max(),'\n'); `

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

### 🚀Array of String

[☝️ Top ☝️](#up)

#### Using 2D Char Array | Array of Pointers to Strings

- [https://www.scaler.com/topics/c/string-pointer-in-c/](https://www.scaler.com/topics/c/string-pointer-in-c/)
- [https://overiq.com/c-programming-101/array-of-pointers-to-strings-in-c/](https://overiq.com/c-programming-101/array-of-pointers-to-strings-in-c/)

We can use a two-dimensional array to store multiple strings, as shown below. Here, the compiler adds a null character at the end of every string if not mentioned explicitly. **The strings can have variable sizes, as shown, but the size of the largest string must be less than (or equal to inclusive of null character) the column size of the 2-D array.**

```cpp
char options[4][10] = {"MEDIUM", "HARD", "EASY", "TOUGH"};
// options[3] = "VERY HARD";   // invalid
//
char choose[10];
cin >> choose;
for (int i = 0; i < 4; i++) {
    if (strcmp(choose, options[i]) == 0) {
        cout << "You choose: " << options[i] << endl;
        break;
    }
}
```

This is how Array of Strings works internally:

```c
char options[][10] = {"MEDIUM", "HARD", "EASY"};
// ⏬

char options[][10] = {{'M', 'E', 'D', 'I', 'U', 'M','\0'},
                      {'H', 'A', 'R', 'D', '\0'},
                      {'E', 'A', 'S', 'Y', '\0'}};
```

Array of Strings:

<div align="center"><img src="img/arr_of_string.jpg" alt="Arr of string" ></div>


For 2-D arrays, both the dimensions of the array need to be defined at the time of variable declaration, and our strings don't have to be of the same length. From the figure, we can see each string in the array has addresses that are not utilized .

**To solve the problem of memory wastage, we can use pointers of size four that can be used to store strings of variable size. In this case, each string takes the memory equal to the string length (inclusive of null character), preventing memory wastage like in the case of a 2-D array. Here, str[i] represents the base address of the ith string.**

We can also use Array of Pointers to Strings:

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

In this case, we are using a pointer variable `options` of size four, because of which **we are only allocating space equal to the length of the individual string**, this can be visualized from the pictorial representation :

<div align="center"><img src="img/arr_of_pointers.jpg" alt="Arr of string" ></div>


#### String[] in Cpp

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

#### Input: 2D Char Array | C

[☝️ Top ☝️](#up)

```c
int main() {
    int n = 3;
    // scanf("%d", &n);
    printf("Enter 3 Country Name:\n");
    char OpIn[n][10];
    for (int i = 0; i < n; i++) {
        printf("Movie[%d]: ", i);
        scanf("%s", OpIn[i]);
    }
    for (int i = 0; i < 4; i++) {
        printf("%s\n", OpIn[i]);
    }
    return 0;
}
```

```bash
Enter 3 Country Name:
Movie[0]: BD
Movie[1]: UK
Movie[2]: US
BD
UK
US
```

Taking lines:

```c
int main() {
    int n = 3;
    // scanf("%d", &n);
    printf("Enter 3 Comments:\n");
    char OpIn[n][100];
    for (int i = 0; i < n; i++) {
        printf("comment[%d]: ", i);
        gets(OpIn[i]);
    }
    for (int i = 0; i < 4; i++) {
        printf("%s\n", OpIn[i]);
    }
    return 0;
}
```

```word
Enter 3 Comments:
comment[0]: this was a good movie
comment[1]: this was a bad movie
comment[2]: I haven't watched the movie
this was a good movie
this was a bad movie
I haven't watched the movie
```

#### Input: Array of Pointers to Strings | C

[☝️ Top ☝️](#up)

```cpp
    int n = 3;
    // scanf("%d", &n);
    printf("Enter 3 Country Name:\n");
    char *OpIn[n];
    for (int i = 0; i < n; i++) {
        printf("Movie[%d]: ", i);
        // memory allocation is needed
        OpIn[i] = (char *)malloc(10);
        scanf("%s", OpIn[i]);
    }
    for (int i = 0; i < 3; i++) {
        printf("%s\n", OpIn[i]);
    }
```

Array of Pointers to Strings(Line):

```c
int main() {
    char *options[] = {"MEDIUM", "HARD", "EASY", "TOUGH"};
    for (int i = 0; i < 4; i++) {
        printf("%s\n", options[i]);
    }
    int n = 3;
    // scanf("%d", &n);
    printf("Enter FullNames of Your 3 Friends:\n");
    char *OpIn[n];
    for (int i = 0; i < n; i++) {
        printf("F[%d]: ", i);
        // memory allocation is needed
        OpIn[i] = (char *)malloc(100);
        gets(OpIn[i]);
    }
    for (int i = 0; i < 3; i++) {
        printf("%s\n", OpIn[i]);
    }
    return 0;
}
```

```bash
Enter FullNames of Your 3 Friends:
F[0]: jhon snow
F[1]: jhon bestow
F[2]: jhon kurry
jhon snow
jhon bestow
jhon kurry
```

### 🖐️CString Example

[☝️ Top ☝️](#up)

#### lowercase to uppercase

```cpp
int main() {
    char s[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    printf("%s\n", s);

    for (int i = 0; i < 5; i++) {
        if (s[i] >= 97 && s[i] <= 122) {
            s[i] = 'A' + (s[i] - 'a'); // A+(c-a) => 65+ (99-97) => 67 => C
        }
    }
    printf("%s\n", s);
    printf("%d", 'A');
    return 0;
}
```

#### binary to decimal

`10110 = 1.2^4 + 0.2^3 + 1.2^2 + 1.2^1 + 0.2^0 = 16+0+4+2+0 =22`

```c
#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
    char binary[] = "10110";
    int decimal = 0, i, power, len;
    len = strlen(binary);
    power = len - 1;
    decimal = 0;

    for (i = 0; i < len; i++) {
        int b = binary[i] - '0';
        //'0'(48) - '0'(48) = 0
        // '1'(49) - '0'(48) = 1
        // decimal = decimal + (b * pow(2, power));
        decimal += b * pow(2, power);
        power--;
    }
    printf("%d", decimal);

    return 0;
}
```

#### String Len

```c
int string_len(char str[]) {
    int len;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
int main() {

    printf("%d\n", string_len("hello"));       // 5
    printf("%d\n", string_len("hello world")); // 11

    char str[10];
    printf("Enter More String:\n");
    while (1 == scanf("%s", str)) {
        printf("len: %d\n", string_len(str));
    }

    return 0;
}
```

- `scanf()` returns number of element taken as input;
  - i.e : `scanf("%d %d",&n1,&n2)` returns `2`
- `while (1 == scanf("%s", str))` takes one word at a time
- press ^Z,^D to stop

```word
Enter More String:
<< a
>> len: 1
<< a b a
>> len: 1
>> len: 1
>> len: 1
```

#### String Copy

```c
void str_cpy(char a[], char b[]) {
    int i;
    for (i = 0; b[i] != '\0'; i++) //  or  for(i=0;s1[i];i++)
    {
        a[i] = b[i];
    }
    a[i] = '\0';
}
int main() {
    char a[20] = "Hello";
    char b[20];
    str_cpy(a, "New");
    printf("%s\n", a); // New
    str_cpy(b, "New");
    printf("%s\n", b); // New
    return 0;
}

```

String Copy UseCase:`char s[]` vs `char *s` with `struct`

```c
typedef struct {
    int id;
    char name[20];
} Student;
// VS
typedef struct {
    int id;
    char *name;
} Student2;

int main() {
    char a[20] = "Hello";
    char b[20];
    str_cpy(a, "New");
    printf("%s\n", a); // New
    str_cpy(b, "New");
    printf("%s\n", b); // New

    // with char name[]
    Student s;
    s.id = 191;
    // s.name = "New"; // error: assignment to expression with array type
    str_cpy(s.name, "New");
    printf("%s\n", s.name); // new

    // with char *name
    Student2 s2;
    s2.id = 191;
    s2.name = "New";
    printf("%s\n", s2.name); // new
    return 0;
}
```

See Why in [`char s[]`(Mutable) vs `char *s`(Immutable)](#char-smutable-vs-char-simmutable)

#### String Concatenation

```c
int main() {
    char s1[] = "Bangla", s2[] = "desh", s[12];
    int i, j, len1 = 6, len2 = 4;
    // copy from a
    for (i = 0, j = 0; i < len1; i++, j++) {
        s[i] = s1[i];
    }
    // copy from b
    for (i = 0; i < len2; i++, j++) {
        s[j] = s2[i];
    }
    s[j] = '\0'; // append terminator at the end
    printf("%s\n", s);// output: Bangladesh
}

```

#### String Comparison

```c
#include <string.h>
int string_compare(char a[], char b[]) {
    for (int i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return -1;
    }

    //  aa == aa
    if (strlen(a) == strlen(b))
        return 0;
    if (strlen(a) > strlen(b))
        return 1;
    if (strlen(a) < strlen(b))
        return -1;
}

int main() {
    // How String Comparision Works!!!
    printf("%d\n", strcmp("aab", "aaa")); // 1 a>b
    printf("%d\n", strcmp("aaa", "aab")); //-1 a<b
    printf("%d\n", strcmp("ba", "ca"));   //-1
    printf("%d\n", strcmp("aa", "aa"));   // 0
    printf("%d\n", strcmp("aaa", "aa"));  // 1
    printf("\n");
    // using custom comparison:
    printf("%d\n", string_compare("aab", "aaa")); // 1
    printf("%d\n", string_compare("aaa", "aab")); //-1
    printf("%d\n", string_compare("ba", "ca"));   //-1
    printf("%d\n", string_compare("aa", "aa"));   // 0
    printf("%d\n", string_compare("aaa", "aa"));  // 1
    printf("%d\n", string_compare("aa", "aaa"));  // -1
}
```

#### Palindrome

```c
#include <stdio.h>
#include <string.h>
int main() {
    char word[80], reverse_word[80];
    int i, j, len;
    scanf("%s", word);
    len = strlen(word);

    for (i = 0, j = len - 1; i < len; i++, j--) {
        reverse_word[i] = word[j];
    }

    reverse_word[len] = '\0';
    printf("%s\n", reverse_word);

    if (0 == strcmp(word, reverse_word)) {
        printf("%s is a palindrome word", word);
        //madam is a palindrome word
    } else {
        printf("%s is a not palindrome word", word);
    }

    return 0;
}
```

#### Problem 1

```bash
Problem Statement:
Given a Line, print that line word by word punctuation removed and each word capitalized.

In: This is a test number 9.9

OUT:
This
Is
A
Test
Number
99

```

```c
#include <stdio.h>
#include <string.h>
int main() {

    char s[1000], ch;
    int i, len, is_word_started = 1;
    gets(s);
    len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            // first char of the word
            if (is_word_started) {
                is_word_started = 0; // so that next char is not mark as starting char
                ch = 'A' + (s[i] - 'a');
                printf("%c", ch);
            }
            // else print as it its
            else {
                printf("%c", s[i]);
            }

        } else if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            if (is_word_started) {
                is_word_started = 1; // so that next char is not mark as starting char
                                     // no need to do anything
            }
            printf("%c", s[i]);
        }
        // WhiteSpace is found
        else {
            if (!is_word_started) {
                // Mark current character as the starting point of new word
                is_word_started = 1;
                printf("\n");
            }
        }
    }

    return 0;
}
```

### 🌟CString Library Functions

[☝️ Top ☝️](#up)

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
