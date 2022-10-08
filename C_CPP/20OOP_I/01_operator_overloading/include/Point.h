#ifndef MACRO_POINT_H
#define MACRO_POINT_H

#include <iostream>

using namespace std;

class Point {
public:
    Point() = default;
    Point(int x, int y);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    bool operator==(const Point &other) const;
    bool operator!=(const Point &other) const;

    //  void operator=(const Point &source);
private:
    int x;
    int y;
};

ostream &operator<<(ostream &stream, const Point &point);
istream &operator>>(istream &stream, Point &point);

#endif // MACRO_POINT_H
