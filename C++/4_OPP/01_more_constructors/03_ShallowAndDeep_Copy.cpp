#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"

class StudentShallow {
    char *name;

public:
    StudentShallow(char *name) {
        this->name = name; // SHALLOW COPY
    }
    void display() {
        cout << name << endl;
    }
};
int main() {

    //* SHALLOW COPY
    char name[] = "soikat";
    StudentShallow s(name);
    cout << "s: " << setw(7);
    s.display();

    //
    name[2] = 'o';
    StudentShallow s1(name);
    cout << "s1: " << setw(6);
    s1.display();
    cout << "s: " << setw(8);
    cout << RED;
    s.display();
    cout << reset << endl;

    // We can see that modifing 's1' modifies 's' object
    // Beacause of shallow coping of 'name' variable when
    // creating objects 's' and 's1'
    /**
    ┏━━━━━┓     ┏━━━━━━┓     ┏━━━━━┓
    ┃ s1  ┃<----┃ name ┃---->┃ s1  ┃
    ┗━━━━━┛     ┗━━━━━━┛     ┗━━━━━┛
*/
    return 0;
}