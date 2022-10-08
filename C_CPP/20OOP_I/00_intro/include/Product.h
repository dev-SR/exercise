#ifndef MACRO_PRODUCT_H
#define MACRO_PRODUCT_H

#include <cstring>

class Product {
private:
    int id;
    char *name;
    int mrp; // maximum retail price
    int selling_price;

public:
    // Parameterized Constructor
    Product(int id, char *name, int mrp, int selling_price);
    // Copy Constructor
    Product(const Product &source);
    // Destructor
    ~Product();
    //  Getters and Setters
    void setMrp(int mrp);
    int getMrp();
    void setSellingPrice(int price);
    int getSellingPrice();
    void setName(char *name);
    char *getName();
    void showDetails();
};
#endif
