#include <bits/stdc++.h>
using namespace std;

/**
USECASE://* spliting a string in C/C++
//https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/

METHOD://? char * strtok(char str[], const char *delims); in C 
In C++
Note:  
       The main disadvantage of strtok() is that it only works for C style strings.
       Therefore we need to explicitly convert C++ string into a char array.
       Many programmers are unaware that C++ has two additional APIs which are more elegant
       and works with C++ string. 

METHOD://?  Using  stringstream API of C++ 
SEE: 0_StringStream.cpp for more deatails



**  The strtok() function in C++ returns the next token in a null terminated byte string.

*!  char* strtok( char* str, const char* delim );

The strtok() function takes two arguments: str and delim. 
This function finds the token in the string pointed to by strtok. 
The pointer delim points to the separator characters.

*? This function can be called multiple times to obtain tokens from the same string. There are two cases:

*?If str is not NULL:---------
A call to strtok() is considered first call for that string. 
The function searches for the first character that is not contained in delim. 
If no such character is found, the string does not contain any token. So a null pointer is returned. 
If such character is found, from there on the function searches for a character that is present in delim. 
If no separator is found, str has only one token. 
If a separator is found, it is replaced by '\0' and 
the pointer to the following character is stored in a static location for subsequent invocations. 
Finally, the function returns the pointer to the beginning of the token.

*?If str is NULL:------------
The call is considered as subsequent calls to strtok and the function continues from where it
 left in previous invocation.
It is defined in <cstring> header file.

*?strtok() Parameters
**str: Pointer to the null terminated byte string to tokenize.
**delim: Pointer to the null terminated byte string that contains the separators.

*?strtok() Return value
**The strtok() function returns the pointer to the next token if there is any,
**or it returns NULL if no more tokens are found.

*/

int main() {

    /**
 * So, strtok returns a token on each subsequent call
 * on the first call function should be passed with string argument for 's'
 * on subsequent calls we should pass the string argument as null
*/
    char c[100] = "Today, is a rainy, day";

    //Working With String
    //>>>string ss = "Today, is a rainy, day";
    //Converting String to Array of char.
    //>>>char *s = (char *)ss.c_str();
    //1. CASTING to solve: "const char *" cannot be used to initialize an entity of type "char *"
    //2. The c_str() function is used to return a pointer to an array that contains a null
    //   terminated sequence of character representing the current value of the string.
    //>>>char *ptr = strtok(s, " ");

    // *? If str is not NULL:---------
    // A call to strtok() is considered first call for that string.
    char *ptr = strtok(c, " "); //
    cout << ptr << endl;
    while (ptr != NULL) {
        //  *? If str is NULL : ------------
        //The call is considered as subsequent calls to strtok and
        //the function continues from where it left in previous invocation.
        ptr = strtok(NULL, " ");
        cout << ptr << endl;
    }
}

//