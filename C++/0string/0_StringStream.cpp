#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m" //Red
#define GRN "\e[0;92m" //Green
#define YEL "\e[0;93m" //Yellow
#define BLU "\e[0;94m" //Blue
#define MAG "\e[0;95m" //Purple
#define CYN "\e[0;96m" //Cyan
#define reset "\e[0m"

//https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/
int main() {

    cout << GRN << "Printing first item form the stream:"
         << reset << endl;
    /**
     The std::istringstream is a string class object which is used to stream the string into different variables and similarly files can be stream into strings. Objects of this class use a string buffer that contains a sequence of characters. This sequence of characters can be accessed as a string object.
     Header File: 
     #include <sstream>
    */
    //*1. Streaming integer from a string with std::istringstream
    //! Input string separated by space
    string source = "10 20 30 40 50";
    // Object class of istringstream
    istringstream iss(source);

    /**
                                    ------------------
    'iss' stream buffer pipeline ➜ | 10 20 30 40 50  |
                                    ------------------
    */

    /**
    * Once a std::istringstream object has been created, then the string can be streamed and stored using the extraction operator(>>). The extraction operator will read until whitespace is reached or until the stream fails.
   */

    // Stream a number till white space is encountered
    int k;
    iss >> k;
    cout << k << endl;
    //same as taking input from iostream
    cout << GRN << "Printing leftover from the stream : (delim: ' ') "
         << reset << endl;
    /**
     The std::istringstream object can also be used as a boolean to determine if the last extraction operation failed. This happens if there wasn’t any more of the string to the stream, For Example, If the stream still has more characters then we are able to stream the string again.

    The extraction operator >> writes the stream to the variable on the right of the operator and returns the std::istringstream object, so the entire expression my_stream >> n is a std::istringstream object which returns a boolean i.e., true if stream is possible else return false.
    */

    //print entire leftovers:
    while (iss >> k) {
        cout << k << endl;
    }
    cout << GRN << "Printing all from the stream:(delim: '')"
         << reset << endl;

    //*2. Strings with Mixed Types
    //!Input String separated by Delemiter
    source = "10,20,30,40,50";
    istringstream iss2(source);
    while (iss2 >> k) {
        cout << k << endl;
        if (iss2.peek() == ',') {
            iss2.ignore();
        }
    }
    //! ISSUE
    cout << RED
         << "Issue!!: not tokenizing, prints whole string at once"
         << reset << endl; //37

    source = "Jhon,20,Tina,30,Bob,40";
    istringstream iss3(source);

    string s;
    while (iss3 >> s) {
        cout << s << endl;
        if (iss3.peek() == ',') {
            iss3.ignore();
        }
        // ? Beacause 's' is string, iss3>>s will extract full string
        // ? until \0
    }
    //! SOLVE: Execrating individual token
    cout << YEL
         << "Resolve: tokenizing with help of getline():"
         << reset << endl; //37

    istringstream iss4(source);
    while (getline(iss4, s, ',')) {
        cout << s << endl;
    }

    cout << YEL
         << "EX2:"
         << reset << endl; //37
    source = "Jhon:20,Tina:30,Bob:40";
    istringstream iss5(source);
    while (getline(iss5, s, ',')) {
        cout << s << endl;
    }

    cout << GRN << "Tokenizing Even Farther:" << reset << endl;
    istringstream iss6(source);
    while (getline(iss6, s, ',')) {

        istringstream iss7(s);
        string s1;
        while (getline(iss7, s1, ':')) {
            cout << CYN << s1 << endl;
        }
        cout << reset << endl;
    }
}