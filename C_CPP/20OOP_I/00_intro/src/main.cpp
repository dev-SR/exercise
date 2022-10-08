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
    return 0;
}