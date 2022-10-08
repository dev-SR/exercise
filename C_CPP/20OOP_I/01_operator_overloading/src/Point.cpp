#include "../include/Point.h"
#include <iostream>

using namespace std;

Point::Point(int x, int y) : x(x), y(y) {}
ostream &operator<<(ostream &stream, const Point &point) {
    stream << "Point(" << point.getX() << ", " << point.getY() << ")";
    return stream;
    /* must return the stream object to allow chaining with cout:
     * cout << px<<px<<pz..<<endl;
     */
}

istream &operator>>(istream &stream, Point &p) {
    int x, y;
    stream >> x >> y;
    p.setX(x);
    p.setY(y);
    return stream;
}

bool Point::operator==(const Point &other) const {
    return (x == other.x) && (y == other.y);
}
bool Point::operator!=(const Point &other) const {
    return (x != other.x) || (y != other.y);
}

int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}