#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

// Operator overloading - redefining operators for objects.
class Circle {
private:
    int radius;

public:
    Circle() {
        radius = 0;
    }
    Circle(int radius) {
        this->radius = radius;
    }
    Circle(const Circle &rho) {
        cout << "Copy constructor..." << endl;
        this->radius = rho.radius;
    }

    double getArea() const {
        return 3.14159 * radius * radius;
    }
    void display() {
        cout << "Radius: " << radius
             << ", Area: " << getArea() << endl;
    }
    Circle operator+(const Circle &rho) {
        Circle result;
        result.radius = this->radius + rho.radius;
        return result;
    }
    Circle operator-(const Circle &rho) {
        Circle result;
        result.radius = abs(this->radius - rho.radius);
        return result;
    }
    Circle operator++() {
        // prefix
        //cout << "I am prefix version" << endl;
        this->radius++;
        Circle result;
        result.radius = this->radius;
        return result;
    }
    Circle operator++(int) {
        // postfix
        //cout << "I am postfix version" << endl;
        Circle result;
        result.radius = this->radius;
        this->radius += 1;
        return result;
    }
    Circle operator--() {
        // left as task
    }
    Circle operator--(int) {
        // left as task
    }
    int getRadius() const {
        return radius;
    }

    bool operator>(const Circle &rho) {
        return this->radius > rho.radius;
    }
    bool operator<(const Circle &rho) {
        return this->radius < rho.radius;
    }

    bool operator==(const Circle &rho) {
        return this->radius == rho.radius;
    }
    bool operator!=(const Circle &rho) {
        return this->radius != rho.radius;
    }
    bool operator>=(const Circle &rho) {
        return this->radius >= rho.radius;
    }
    bool operator<=(const Circle &rho) {
        return this->radius <= rho.radius;
    }
    Circle &operator=(const Circle &rho);
    friend ostream &operator<<(ostream &, const Circle &);
    friend istream &operator>>(istream &, Circle &);
};

Circle &Circle::operator=(const Circle &rho) {
    cout << "Assignment operator..." << endl;
    this->radius = rho.radius;
    return *this;
}

ostream &operator<<(ostream &sout, const Circle &c) {
    sout << "Radius: " << c.radius << ", Area: " << c.getArea() << endl;
    return sout;
}

istream &operator>>(istream &sin, Circle &c) {
    //cout << "I am here in operator >> " << endl;
    sin >> c.radius;
    return sin;
}

int main() {
    Circle c1(15);
    Circle c2 = c1;
    cout << c2 << endl;

    Circle c3, c4;
    //ifstream is special sub type of istream; used for taking input from file
    ifstream fin("circle_data.txt");
    if (!fin) {
        cout << "Invalid file name" << endl;
        return 0;
    }
    fin >> c3 >> c4;
    cout << c3 << c4;
    //ofstream is special sub type of ostream; used for file output
    ofstream fout("out_data.txt");
    fout << c3 << c4;
    return 0;
}
