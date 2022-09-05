#include <bits/stdc++.h>
using namespace std;
void fun(int a, int &b);
void printArray(int (&p)[5]);
void errorWithForRange(int x[], int n);
void okWithForRange(int (&x)[5]);

int main() {
    /**
     * When a variable is declared as a reference, it becomes an alternative name for an existing variable. 
    */
    int a = 1;
    int &b = a;
    cout << a << " " << b << endl; //1 1

    /**
     * Passing Array By Reference to a function:
     */

    int x[] = {1, 2, 3, 4, 5};
    printArray(x);
    // Proplem With Range Loop inside a fuction
    // errorWithForRange(x, 5);
    // Correct Way of Passing Array to allow Range for loop to work properly
    okWithForRange(x);

    //!Application:
    //?1/To Modify the passed parameters in a function
    int c = 1;
    fun(a, c);
    cout << "Application" << endl
         << "i__________"
         << endl;
    cout << a << " " << c << endl //1 2
         << endl
         << "ii__________" << endl;

    // c is modifed

    //?2 In For Each Loops to modify all objects
    vector<int> v{10, 20, 30, 40};
    for (int x : v)
        x = x + 5;
    for (int x : v)
        cout << x << " "; //10 20 30 40
    cout << endl;
    // We can modify elements if we use reference
    for (int &x : v)
        x = x + 5;
    for (int x : v)
        cout << x << " "; //15 25 35 45
    cout << endl
         << endl
         << "iii__________"
         << endl;

    //?3 For Each Loop to avoid the copy of objects:
    vector<string> vs{"practice more",
                      "write more",
                      "read more"};
    // We avoid copy of the whole string
    // object by using reference.
    for (const auto &x : vs)
        cout << x << endl;
}
//?4 Avoiding a copy of large structures:

// struct Student {
//     string name;
//     string address;
//     int rollNo;
// }
// If we remove & in below function, a new
// copy of the student object is created.
// We use const to avoid accidental updates
// in the function as the purpose of the function
// is to print s only.
// void print(const Student &s) {
//     cout << s.name << "  " << s.address << "  " << s.rollNo;
// }

void printArray(int (&p)[5]) { // size is Mandatory
    cout << "printArray:" << endl;
    for (int i = 0; i < 5; i++)
        cout << p[i];
    cout << endl;
}

// void errorWithForRange(int x[], int n) {
//     for (auto k : x) {
//Warning: this range-based 'for' statement requires a suitable "begin" function and
//error: 'begin' was not declared in this scope
// Because x is just pointing to first element hence iterator are not defined
//         cout << k;
//     }
// }

void okWithForRange(int (&x)[5]) {
    cout << "okWithForRange: " << endl;
    for (auto k : x) {
        cout << k << " " << x << endl;
    }
    cout << endl;
    // 1 0x61fd90
    // 2 0x61fd90
    // 3 0x61fd90
    // 4 0x61fd90
    // 5 0x61fd90
}

void fun(int a, int &c) {
    a++;
    c++;
}
