#include <bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/c-string-class-and-its-applications/
//https://www.geeksforgeeks.org/c-string-class-applications-set-2/

// !Capacity:
// size             Return length of string
// length           Return length of string
// max_size         Return maximum size of string
// resize           Resize string
// capacity         Return size of allocated storage
// reserve          Request a change in capacity
// clear            Clear string
// empty            Test if string is empty
// shrink_to_fit    Shrink to fit

// !Element access:
// operator[]       Get character of string
// at               Get character in string
// back             Access last character
// front            Access first character

// !Modifiers:
// operator+=       Append to string
// append           Append to string
// push_back        Append character to string
// assign           Assign content to string
// insert           Insert into string
// erase            Erase characters from string
// replace          Replace portion of string
// swap             Swap string values
// pop_back         Delete last character

// !String operations:
// c_str                Get C string equivalent
// data                 Get string data
// get_allocator        Get allocator
// copy                 Copy sequence of characters from string
// find                 Find content in string
// rfind                Find last occurrence of content in string
// find_first_of        Find character in string
// find_last_of         Find character in string from the end
// find_first_not_of    Find absence of character in string
// find_last_not_of     Find non-matching character in string from the end
// substr               Generate substring
// compare              Compare strings

int main() {

    //!String Init-----------------------------------------------
    string s0;
    string s1("hello");

    string s2 = "Hello World";
    // initialization by another string
    string s3(s2);

    string s4 = s3;

    char a[] = {'a', 'b', 'c', '\0'};
    string s5(a);

    // initialization by character with number of occurrence
    string s6(5, '#');
    // initialization by part of another string
    // @params [Str,start_index,no_of_chars_from_Str]
    string s7(s2, 6, 6); // from 6th index (second parameter)
                         // 6 characters of s2 (third parameter)

    // initialization by part of another string : iterator version
    string s8(s2.begin(), s2.begin() + 5);
    //Reverse Using  reverse iterators
    string rev = string(s2.rbegin(), s2.rend());

    //assign a new value to the string, replacing its current contents.
    //assign(str, pos, len);
    string r;
    string base = "c-string";
    r.assign(base);
    // r.assign(base,0,4);

    cout << setfill('*') << setw(20) << "*";
    cout << "initialization";
    cout << setfill('*') << setw(20) << "*" << endl;
    cout << s0 << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;
    cout << s7 << endl;
    cout << s8 << endl;
    cout << rev << endl;
    cout << r << '\n';

    cout << "check is string is empty" << endl;
    if (s0.empty()) {
        cout << "s0 is empty" << endl;
    }
    cout << endl;

    //!Find SubString-----------------------------------------------
    cout << setfill('*') << setw(20) << "*";
    cout << "Find Substring";
    cout << setfill('*') << setw(20) << "*" << endl;
    //size_t find (const string& str, size_t pos = 0);
    //size_t find(const char *s, size_t pos = 0);
    string s = "I want to have apple juice";
    int idx = s.find("apple");
    cout << idx << endl;
    //pos : default =0  or ,
    //The initial position from where the string search is to begin.
    int beginFrom16 = s.find("apple", 16);
    cout << beginFrom16 << endl;

    //  If not found it returns predefined
    //  constant 'npos' whose value is -1
    if (s.find("mango") != string::npos)
        cout << "mango found in s at " << s.find("mango")
             << " pos" << endl;
    else
        cout << "mango not found in s" << endl;

    //?finding All occurrence:
    s = "You must know, first may not no longer be the first if second comes first";
    cout << "all occurrence:" << endl;

    string::size_type index = s.find("first");
    while (index != string::npos) {
        cout << "found at: " << index << endl;
        index = s.find("first", index + 1);
    }

    // rfind() returns position to last
    // occurrence of substring "geeks"
    string str = "geeksforgeeks";
    cout << "Last occurrence of \"geeks\" starts from : ";
    cout << str.rfind("geeks") << endl;

    string sr("Hello World");
    // find first occurrence of  'any' character from "aeiou"
    cout << "First occurrence vowel at : ";
    cout << sr.find_first_of("aeiou") << endl;

    // find last occurrence of 'any' character from "aeiou"
    cout << "Last occurrence vowel at : ";
    cout << sr.find_last_of("aeiou") << endl;
    cout << "Example: occurrene of any '+. !,' :" << endl;
    sr = "Hello World! Welcome, to my c++ program";
    string target = "+. !,";
    string::size_type pos = sr.find_first_of(target);
    while (pos != string::npos) {
        cout << "Found '" << sr[pos] << "' at: " << pos << endl;
        pos = sr.find_first_of(target, pos + 1);
    }
    cout << endl;

    //!Append-----------------------------------------------
    cout << setfill('*') << setw(20) << "*";
    cout << "Appending";
    cout << setfill('*') << setw(20) << "*" << endl;
    //@params [str]
    s0.append("I love C++");
    cout << s0 << endl;
    //[s,pos,no_of_char_from_that_s]
    s0.append(s1, 0, 6);
    cout << s0 << endl;
    s0 = s0 + "and Python";
    cout << s0 << endl;
    // Append character to string
    s0.push_back('x');
    cout << s0 << endl;
    cout << endl;

    //!pop_back and clear---------------------------------------------------------
    cout << setfill('*') << setw(20) << "*";
    cout << "pop_back and clear";
    cout << setfill('*') << setw(20) << "*" << endl;
    // Using pop_back() to delete a character
    // from end
    s0.pop_back();
    cout << s0 << endl;
    cout << s0.length() << endl;
    //clear all
    s0.clear();
    cout << s0.length() << endl;
    cout << endl;

    //!Remove substring-------------------------------------------------
    cout << setfill('*') << setw(20) << "*";
    cout << "Removing a word from String";
    cout << setfill('*') << setw(20) << "*" << endl;
    string word = "apple";
    int len = word.length();
    s = "I want to have apple juice";
    cout << s << endl;
    s.erase(idx, len + 1); //[pos,no of char to be removed]
    cout << s << endl;
    //  iterator version of erase
    s.erase(s.begin() + 6, s.end() - 5);
    cout << s << endl
         << endl;
    ;

    //!Replace and Insert new substring-----------------------------------
    cout << setfill('*') << setw(20) << "*";
    cout << "Replace and Insert new";
    cout << setfill('*') << setw(20) << "*" << endl;
    // replace(x, n, new_string)
    // replaces n No. of characters from index x with a new str

    s.replace(6, 0, " - ");
    cout << s << endl;

    cout << "Replacing all occurrence:" << endl;
    string st = "first is the first word we like first";
    cout << st << endl; //37
    string f("first");
    string repWith("second");
    int at = st.find(f);
    while (at != string::npos) {
        st.replace(at, f.size(), repWith);
        at = st.find(f, at + repWith.size());
    }
    cout << st << endl;

    // insert(x, new_string) :
    cout << endl;
    cout << "Inserting::...." << endl;
    s.insert(6, " +");
    cout << s << endl;
    cout << endl;

    //!Extract Substring-----------------------------------------------
    cout << setfill('*') << setw(20) << "*";
    cout << "Extract Substring";
    cout << setfill('*') << setw(20) << "*" << endl;
    //  substr(x, b) returns a substring of b length
    //  starting from index x

    cout << s.substr(7, 4) << endl;
    cout << s.substr(7) << endl;
    cout << endl;

    //!Access Individual Charecters-----------------------------------------------
    cout << setfill('*') << setw(20) << "*";
    cout << "Access Charaters of a String";
    cout << setfill('*') << setw(20) << "*" << endl;
    cout << "s1:" << s1 << endl;
    cout << "s1[0] : " << s1[0] << endl;
    cout << "s1.at(1): " << s1.at(1) << endl;
    cout << "front(): " << s1.front() << endl;
    cout << "back(): " << s1.back() << endl;
    cout << endl;

    //!Iterate over all the character in the string;-------------------------------
    cout << setfill('*') << setw(20) << "*";
    cout << "Iterators";
    cout << setfill('*') << setw(20) << "*" << endl;
    cout << "Iteration 1" << endl;
    for (int i = 0; i < s1.length(); i++) {
        cout << s1[i] << " ";
    }
    cout << endl;
    //using iterators
    cout << "Iteration 2" << endl;
    for (auto it = s1.begin(); it != s1.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;
    //using  For Each
    cout << "Iteration 3" << endl;
    cout << "1. Range For Loop:  for(char c:s) " << endl;
    for (char c : s1) {
        cout << c << " ";
    }
    cout << endl
         << endl;
    cout << setw(25) << "-> Modifing Without reference: for(char c:s)  " << endl;
    for (char c : s1) {
        if (c >= 'a') {
            c -= 32;
        }
        cout << c;
    }
    cout << endl;
    cout << "After Modification:" << endl;
    for (char c : s1) {
        cout << c << " ";
    }
    cout << endl

         << "string is not modified" << endl;
    cout << endl;
    cout << "-> Modifing With Reference: for(char &c:s)" << endl;
    for (char &c : s1) {
        if (c >= 'a') {
            c -= 32;
        }
        cout << c;
    }
    cout << endl;
    cout << "After Modification:" << endl;
    for (char c : s1) {
        cout << c;
    }
    /**
     * See reference in c++: https://www.geeksforgeeks.org/references-in-c/ , how its used In For Each Loops to modify all objects
    */

    cout << endl
         << endl;

    //!Compare two string;---------------------------------------------
    cout << setfill('*') << setw(20) << "*";
    cout << "Comparing string";
    cout << setfill('*') << setw(20) << "*" << endl;
    s0 = "Apple";
    s1 = "Mango";
    cout << s1.compare(s0) << endl;
    cout << s0.compare(s1) << endl;
    //Comparing using Overloaded operators;
    if (s1 > s0) {
        cout << "Mango is lexically greater then Apple" << endl;
    }
    cout << endl;

    //!Array Of String + Sorting :---------------------------------------------------------------
    cout << setfill('*') << setw(20) << "*";
    cout << "Array Of String + Sorting";
    cout << setfill('*') << setw(20) << "*" << endl;
    string ar[] = {"Apple", "Mango", "Banana", "Guava"};
    sort(ar, ar + 4);
    for (int i = 0; i < 4; i++) {
        cout << ar[i] << " ";
    }
    cout << endl
         << endl;

    //!Applications :---------------------------------------------------------------
    cout << setfill('*') << setw(20) << "*";
    cout << "Applications";
    cout << setfill('*') << setw(20) << "*" << endl;
    // ?get floating point part of a number-string
    string fnum = "23.342";
    cout << "Floating part is : ";
    pos = 0;
    pos = fnum.find(".");
    if (pos == string::npos)
        cout << "" << endl;
    else
        cout << fnum.substr(pos + 1) << endl;

    // ?checks whether a string contains all digit or not
    string num = "3452";
    int l = num.length();
    int i;
    for (i = 0; i < l; i++) {
        if (num.at(i) < '0' || num.at(i) > '9')
            cout << "not a number";
    }
    //  if we reach here all character are digits
    if (i == l)
        cout << "contains digits only" << endl;

    // ?this function replaces all single space by %20
    string urlex = "google com in";
    string replaceby = "%20";
    int n = 0;
    // loop till all space are replaced
    while ((n = urlex.find(" ", n)) != string::npos) {
        urlex.replace(n, 1, replaceby);
        n += replaceby.length(); //go to next space
    }
    cout << urlex << endl;
    cout << endl;
}