#include "../include/Product.h"

#include <cstring>
#include <iostream>
using namespace std;

// Product::Product(int id, char *name, int mrp, int selling_price) {
//     cout << "Constructor called" << endl;
//     this->id = id;
//     setName(name);
//     setMrp(mrp);
//     setSellingPrice(selling_price);
// }
Product::Product(int id, char *name, int mrp, int selling_price) {
    this->id = id;
    this->mrp = mrp;
    this->selling_price = selling_price;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
Product::Product(const Product &source) {
    id = source.id;
    mrp = source.mrp;
    selling_price = source.selling_price;
    name = source.name; // shallow copy

    // deep copy
    name = new char[strlen(source.name) + 1];
    strcpy(name, source.name);
}

Product::~Product() {
    cout << "Destructor called" << endl;
    delete[] name;
}

char *Product::getName() {
    return name;
}

void Product::showDetails() {
    cout << "Product{id = " << id << ", name = " << name << ", mrp = " << mrp << ", selling_price = " << selling_price << "}" << endl;
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
