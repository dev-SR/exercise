#include "../include/Product.h"
#include "../include/Rectangle.h"
#include "../include/TextBox.h"
#include <iostream>
using namespace std;

int main() {
    Rectangle rec;
    rec.setWidth(10);
    rec.setHeight(5);
    cout << rec.getArea() << endl;
    // rec.setHeight(-1); //  throws exception
    TextBox text;
    text.setValue("Hello");
    cout << text.getValue() << endl;

    Product camera{1, "Nikon", 100, 200};
    //  Product camera(1, "Nikon", 100, 200);
    camera.setMrp(1000);
    camera.setSellingPrice(1200);
    cout << "Product{ " << camera.getName() << ", " << camera.getMrp() << ", " << camera.getSellingPrice() << " }" << endl;
    try {
        Product none{1, "", 100, 200};
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }
    return 0;
}