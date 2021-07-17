# String

- [String](#string)
  - [Introduction](#introduction)
    - [Declaring a String](#declaring-a-string)
    - [Initializing and Accessing a String](#initializing-and-accessing-a-string)
    - [Constant String](#constant-string)
      - [Character Arrays versus Character Pointers](#character-arrays-versus-character-pointers)
    - [Display String](#display-string)
    - [Array of Strings](#array-of-strings)
    - [Array of Pointers](#array-of-pointers)
    - [Reading a String](#reading-a-string)
  - [String manipulations](#string-manipulations)

## Introduction

### Declaring a String

```c
char str[10];
```

- A string is nothing more than an array of characters
- there are no built-in operators in C for processing string

### Initializing and Accessing a String

```cpp

     char str[10] = {'H','e','l','l','o'};
     char str[] = {'H','e','l','l','o','\0'};
     char str[] = "Hello"; 

     /**  
     index  0   1   2   3   4   5
          ┌───┐───┐───┐───┐───┐───┐
          │ H │ e │ l │ l │ o │\0 │
          └───┘───┘───┘───┘───┘───┘
     Hex   48  65  6C  6F  21  00
     */

     //accessing
     str[0] = 'Y';
     /**  
     index  0   1   2   3   4   5
          ┌───┐───┐───┐───┐───┐───┐
          │ X │ e │ l │ l │ o │\0 │
          └───┘───┘───┘───┘───┘───┘
     Hex   48  65  6C  6F  21  00
     */

     str= "Another String"; //not Allowed
```

### Constant String

```cpp

    const char sc[] = "Hello";
    // sc[0] = 'Y'; //compile time error

    char *s = "Hello!";
    s[0] = 'Y'; //Not Allowed runtime error
    printf("char *s = %s\n", s);//prints nothing as The contents of `s` should not be changed
    
    //though this is allowed
    s = "Another String"; //`s` is a pointer variable, that can be changed to point elsewhere.
    
    //compile time error safety
    const char *s2 = "Hello!";   
    s2[0] = 'Y'; //compile time error
    s2 = "Another String";//Allowed

    /**  IN C++   
            char *s = "Hello"; -> is not allowed
        ISO C++ forbids converting a string constant to 'char*'
        though,
            const char *s = "Hello"; -> is allowed
    */
```

#### Character Arrays versus Character Pointers

Character arrays and character pointers are often interchangeable, but there can be some very important differences. Consider the following two variables:

```cpp
char s1[ ] = "hello", *s = "hello";
```

- `s1` is a **fixed constant address**, determined by the compiler; `s` is a pointer variable, that can be changed to point elsewhere.
- The contents of `s1`, can be changed, e.g. `s1[ 0 ] = 'J'`; **The contents of `s` should not be changed.**
- `s1` allocates space for exactly 6 bytes; `s` allocates space for 10 ( typically ) - 6 for the characters plus another 4 for the pointer veriable.

### Display String

```cpp

     //printf() function:(Most Preferred):
     char str[] = "This course is boring";
     printf("%s\n",str);           //This course is boring
     printf("%s\n"&str[15]);       //boring
     printf("%.4s",str);           //This
     //puts() function:( Preferred):
     /* 
    1.    The most convenient function for printing a simple message on standard output is puts. 
          It is even simpler than printf, since you do not need to include 
          a newline character — puts does that for you.

     2.   The puts function is safe and simple, but not very flexible as it does
          not give us an option of formatting our string.
     */
```

### Array of Strings

<div align="center"><img src="img/arr_of_string.jpg" alt="Arr of string" ></div>

### Array of Pointers

<div align="center"><img src="img/arr_of_pointers.jpg" alt="Arr of string" ></div>

### Reading a String

```cpp
char input_str[10];
    printf("Please enter a word: ");
    scanf("%s", input_str);    //hello world
    printf("%s\n", input_str); //hello

    //WORKAROUND!!
    //fgets() (Should no longer be used)
    //gets() (Should no longer be used)
    //https://www.studymite.com/blog/strings-in-c

    //getline()  (Preferred Method)
    int bytes_read;
    int size = 10;
    char *string;
    printf("Please enter a string: ");
    /* These 2 lines are very important. */
    string = (char *)malloc(size);//#include <stdlib.h>
    bytes_read = getline(&string, &size, stdin);
    printf("%s", string);
    if (bytes_read == -1) {
        puts("ERROR!");
    } else {
        puts(string);
        printf("\nCurrent size for string block: %d", bytes_read);
    }
```

## String manipulations

| Function             | Description                                                                                            |
| -------------------- | ------------------------------------------------------------------------------------------------------ |
| `strlen(s)`          | returns the length of string name.                                                                     |
| `strcat(s1,s2)`      | concats or joins first string with second string. The result of the string is stored in first string.  |
| `strcpy(des,src,[n)` | copies the contents of source string to destination string.                                            |
| `strchr(s,ch)`       | Returns pointer to first occurrence of `ch` in `s`                                                     |
| `strrchr(s,ch)`      | Returns pointer to last occurrence of `ch` in `s`                                                      |
| `strstr(s1,s2)`      | Returns pointer to first occurrence of `s2` in `s1`                                                    |
| `strrstr(s1,s2)`     | Returns pointer to last occurrence of `s2` in `s1`                                                     |
| `strtok()`           | Tokenizing(split string into tokens) given string using delimiter                                      |
| `strcmp(s1,s2)`      | compares the first string with second string. If both strings are same, it returns `0` otherwise `-1`. |
| `strcmpi(s1,s2)`     | Same as strcmp() function. But, this function negotiates case.  `A` and `a` are treated as same.       |
| `strlwr(s)`          | returns string characters in lowercase.                                                                |
| `strupr(s)`          | returns string characters in uppercase.                                                                |
| `strrev(s)`          | returns reverse string.                                                                                |
| `strnset()`          | Sets all character in a string to given character                                                      |
| `strnset()`          | It sets the portion of characters in a string to given character                                       |
