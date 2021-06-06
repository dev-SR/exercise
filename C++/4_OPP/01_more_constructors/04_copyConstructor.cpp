#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"
class WithOutCopyConstr {
public:
    char *name;
    WithOutCopyConstr(char *name) {
        //this->name=name;shallow copy
        //Deep Copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    void display() {
        cout << name << endl;
    }
};
class WithCopyConstr {
public:
    char *name;
    WithCopyConstr(char *name) {
        //Deep Copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    //Copy Constructor
    WithCopyConstr(WithCopyConstr const &s) {
        /**
         * const &s prevent any accidental modification of
         * 's' object.
        */
        //Deep Copy
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }
    void display() {
        cout << name << endl;
    }
};
int main() {
    cout << MAG << "Default Copy Constructor is always shallow copy:" << reset << endl;
    char n[] = "soikat";
    cout << "s1: " << GRN;
    WithOutCopyConstr s1(n);
    s1.display();
    cout << reset;

    //Defult Copy Constructor
    WithOutCopyConstr s2(s1);
    s2.name[0] = 'x';
    cout << "s1: ";
    s2.display();
    cout << "s1: " << RED;
    s1.display();
    cout << YEL << "!! modification of 's1' affected 's2'";
    cout << reset;

    cout << MAG << "User-defined Copy Constructor:" << reset << endl;
    char x[] = "soikat";
    cout << "p1: " << GRN;
    WithOutCopyConstr p1(x);
    p1.display();
    cout << reset;

    //Defult Copy Constructor
    WithOutCopyConstr p2(x);
    p2.name[0] = 'x';
    cout << "p1: ";
    p2.display();
    cout << "p1: " << GRN;
    p1.display();
    cout << YEL << "!! modification of 'p1' do not affect 'p2'";
    cout << reset;

    return 0;
}