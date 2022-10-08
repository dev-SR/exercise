#ifndef MACRO_PRODUCT_H
#define MACRO_PRODUCT_H

class Product {
public:
    // Parameterized Constructor
    Product(int id, char *name, int mrp, int selling_price);
    //  Getters and Setters
    void setMrp(int mrp);
    int getMrp();
    void setSellingPrice(int price);
    int getSellingPrice();
    void setName(char *name);
    char *getName();

private:
    int id;
    char name[100];
    int mrp; // maximum retail price
    int selling_price;
};
#endif
