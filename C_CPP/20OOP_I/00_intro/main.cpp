#include "Rectangle.h"
#include <iostream>
using namespace std;

int main() {
    Rectangle rec;
    rec.setWidth(10);
    rec.setHeight(5);
    cout << rec.getArea() << endl;
    // rec.setHeight(-1); //  throws exception

    return 0;
    cout << "Hello World" << endl;

    return 0;
}