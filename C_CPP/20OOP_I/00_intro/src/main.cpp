#include "../include/Product.h"
#include "../include/Rectangle.h"
#include "../include/TextBox.h"
#include <iostream>
#include <memory>
using namespace std;

int main() {
    // smart pointer
    unique_ptr<Rectangle> rectangle(new Rectangle(10, 20));
    cout << "Area: " << rectangle->getArea() << endl;
    // or
    unique_ptr<Rectangle> rectangle2 = make_unique<Rectangle>(10, 20);
    cout << "Area: " << rectangle2->getArea() << endl;
    // or
    auto rectangle3 = make_unique<Rectangle>(10, 20);
    cout << "Area: " << rectangle3->getArea() << endl;

    Rectangle recArr[] = {
        Rectangle(10, 20),
        Rectangle(20, 30),
        Rectangle(30, 40),
    };
    // or using brace initialization
    Rectangle recArr2[] = {
        {10, 20},
        {20, 30},
        {30, 40},
    };

    for (auto &rec : recArr) {
        cout << "Area: " << rec.getArea() << endl;
    }
    for(auto &rec : recArr2) {
        cout << "Area: " << rec.getArea() << endl;
    }

    // rec.setHeight(-1); //  throws exception
    TextBox text;
    text.setValue("Hello");
    cout << text.getValue() << endl;

    Product iPhone(1, "iPhone", 100, 200);
    Product android(iPhone);
    iPhone.showDetails();
    android.showDetails();
    android.setName("Android");
    iPhone.showDetails();
    android.showDetails();
    try {
        Product none{1, "", 100, 200};
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }
    return 0;
}
