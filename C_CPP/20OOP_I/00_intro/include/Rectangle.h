#ifndef RECTANGLE_HEADER_H
#define RECTANGLE_HEADER_H

class Rectangle {
private:
    int width;
    int height;

public:
    void draw();
    int getArea();
    //  getters and setters
    int getWidth();
    void setWidth(int width);
    int getHeight();
    void setHeight(int height);
};

#endif