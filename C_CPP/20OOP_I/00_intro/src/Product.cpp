#include "../include/Product.h"

#include <cstring>
#include <iostream>
using namespace std;

Product::Product(int id, char *name, int mrp, int selling_price) {
    cout << "Constructor called" << endl;
    this->id = id;
    setName(name);
    setMrp(mrp);
    setSellingPrice(selling_price);
}
char *Product::getName() {
    return name;
}

void Product::setName(char *name) {
    if (strlen(name) <= 0) {
        throw invalid_argument("Name cannot be empty");
    } else if (strlen(name) > 100) {
        throw invalid_argument("Name cannot be more than 100 characters");
    } else {
        strcpy(this->name, name);
        /*
        1.`this->name = name` not possible because name is a char array.
        2. Recommend String class instead of char array:
                Product(int id, const string &name, int mrp, int selling_price)
        3. char array is avoidable:
                >> src/main.cpp:17:18: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]

        */
    }
}
void Product::setMrp(int mrp) {
    if (mrp > 0)
        this->mrp = mrp;
}
void Product::setSellingPrice(int price) {
    if (price > mrp)
        this->selling_price = mrp;
    else
        this->selling_price = price;
}
int Product::getMrp() {
    return mrp;
}
int Product::getSellingPrice() {
    return selling_price;
}
