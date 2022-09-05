#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"
class Car {
private:
    int price;

public:
    int model_no;
    char *name;
    const int tyres;
    //Constructor
    Car() : name(NULL), tyres(4) {
    }
    // Constructor with parameters - Parametrized Constructor
    Car(int p, int mn, char *n, int t = 4) : price(p), model_no(mn), tyres(t) {
        int l = strlen(n);
        name = new char[l + 1];
        strcpy(name, n);
    }
    //Deep Copy Constructor
    Car(Car &X) : tyres(X.tyres) {
        // cout<<"Making a Copy of Car";
        price = X.price;
        model_no = X.model_no;
        int l = strlen(X.name);
        name = new char[l + 1];
        strcpy(name, X.name);
    }
    void operator=(const Car &X) {
        cout << "In Copy Assignment Operator" << endl;
        price = X.price;
        model_no = X.model_no;
        int l = strlen(X.name);
        name = new char[l + 1];
        strcpy(name, X.name);
    }
    void setName(const char *n) {
        if (name == NULL) {
            name = new char[strlen(n) + 1];
            strcpy(name, n);
        } else {
            //Later...
            //Delete the oldname array and allocate a new one
        }
    }
    void start() const {
        cout << "starting the car... " << name << endl;
    }
    void setPrice(const int p) {
        if (p > 1000) {
            price = p;
        } else {
            price = 1000;
        }
    }
    int getPrice() const {
        return price;
    }
    void print() const {
        cout << GRN << name << reset << endl;
        cout << model_no << endl;
        cout << price << endl;
        cout << endl;
    }
    ~Car() {
        cout << "Destroying the Car " << name << endl;
        //Write code to delete all dynamic data member
        if (name != NULL) {
            delete[] name;
        }
    }
};
int main() {
    Car C;
    //Initialisation
    //C.price =-500;
    char n[] = "Nano";
    C.setPrice(1500);
    C.setName(n);
    C.model_no = 1001;
    C.print();
    char c1[] = "BMW";
    char c2[] = "Audi";

    Car D(100, 200, c1);
    Car E(200, 400, c2); //Default Copy Constructor
    // E.name[0] ='G';
    D = E; //Copy Assignment Operator ->Shallow Copy
    D.name[0] = 'O';
    D.print();
    E.print();
    //Suppose we create a dynamic object
    char c3[] = "Dynamic Tesla Car";
    Car *DC = new Car(100, 200, c3);
    DC->print();
    delete DC;
    return 0;
}

/**
Nano
1001
1500

In Copy Assignment Operator
Oudi
400
200

Audi
400
200

Dynamic Tesla Car
200
100

Destroying the Car Dynamic Tesla Car
Destroying the Car Audi
Destroying the Car Oudi
Destroying the Car Nano
*/