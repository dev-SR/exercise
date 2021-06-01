#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"

class Student {
    string name;

public:
    Student() {
        cout << MAG << "Constructing..." << reset << endl;
    }
    ~Student() {
        cout << RED << "Destructor called!! " << reset << endl;
    }
};

int main() {

    //static
    Student s1;

    //Dynamic
    Student *s = new Student;
    /**
     * 
     * Destructor for static is getting called once!!!
     * *But for Dynamic, twice 
     * !Because compiler is deleting allocated memory and the pointer itself
       ┏━━━┓      ┏━━━━━━━━━━━━━━━┓
       ┃ p ┃----> ┃ new Student   ┃      
       ┗━━━┛      ┗━━━━━━━━━━━━━━━┛
       ❌           ❌
    */
    return 0;
}