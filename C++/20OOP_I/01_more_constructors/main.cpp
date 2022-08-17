#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
class Product {
private:
    int id;
    char *name;
    int mrp; // maximum retail price
    int selling_price;

public:
    // Constructor Overloading...
    Product() {
    }
    Product(int id, char *name, int mrp, int selling_price) {
        this->id = id;
        this->mrp = mrp;
        this->selling_price = selling_price;
        // dynamically allocate memory for name
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    Product(const Product &X) {
        id = X.id;

        strcpy(name, X.name);
        mrp = X.mrp;
        selling_price = X.selling_price;
        // shallow copy
        //  name = p.name;
        // deep copy
        name = new char[strlen(X.name) + 1];
    }
    void operator=(const Product &X) {
        id = X.id;
        mrp = X.mrp;
        selling_price = X.selling_price;
        // deep copy
        name = new char[strlen(X.name) + 1];
        strcpy(name, X.name);
    }
    void setName(char *name) {
        strcpy(this->name, name);
    }

    void setMrp(int mrp) {
        if (mrp > 0)
            this->mrp = mrp;
    }
    void setSellingPrice(int price) {
        if (price > mrp)
            this->selling_price = mrp;
        else
            this->selling_price = price;
    }
    int getMrp() {
        return mrp;
    }
    int getSellingPrice() {
        return selling_price;
    }
    void showDetails() {
        cout << "Product{id = " << id << ", name = " << name << ", mrp = " << mrp << ", selling_price = " << selling_price << "}" << endl;
    }

    // Destructor to delete dynamically allocated memory
    ~Product() {
        cout << "Deleting " << name << endl;
        if (name != NULL)
            delete[] name;
        name = NULL;
    }
};

int main() {
    Product iPhone(1, "iPhone", 100, 200);
    Product android;
    android = iPhone;
    iPhone.showDetails();
    android.showDetails();
    android.setName("Android");
    iPhone.showDetails();
    android.showDetails();
    return 0;
}
