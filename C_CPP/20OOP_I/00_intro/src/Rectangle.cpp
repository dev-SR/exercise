#include "../include/Rectangle.h"

#include <iostream>

using namespace std;

int Rectangle::getWidth() {
    return width;
}

void Rectangle::setWidth(int width) {
    if (width < 0) {
        throw invalid_argument("Width cannot be negative");
    }

    // (*this).width = width;
    //  or
    this->width = width;
    //  or
    // Rectangle::width = width;
}

int Rectangle::getHeight() {
    return height;
}

void Rectangle::setHeight(int height) {
    if (height < 0) {
        throw invalid_argument("Height cannot be negative");
    }
    this->height = height;
}

void Rectangle::draw() {
    cout << "Drawing a rectangle" << endl;
    cout << "Dimensions:" << width << ", " << height << endl;
}

int Rectangle::getArea() {
    return width * height;
}
