# Operator Overloading

- [Operator Overloading](#operator-overloading)
	- [Equality Operator : `==`, `!=`](#equality-operator---)
	- [Copy Assignment Operator : `=`](#copy-assignment-operator--)
	- [Stream Insertion Operator `<<`](#stream-insertion-operator-)
	- [Stream Extraction Operator:`>>`](#stream-extraction-operator)

## Equality Operator : `==`, `!=`

`include/Point.h`

```cpp
#ifndef MACRO_POINT_H
#define MACRO_POINT_H
class Point {
public:
    Point(int x, int y);
    bool operator==(const Point &other) const;
    bool operator!=(const Point &other) const;

private:
    int x;
    int y;
};
#endif // MACRO_POINT_H
```

`include/Point.cpp`

```cpp
#include "../include/Point.h"
#include <iostream>

using namespace std;

Point::Point(int x, int y) : x(x), y(y) {}

bool Point::operator==(const Point &other) const {
    return (x == other.x) && (y == other.y);
}
bool Point::operator!=(const Point &other) const {
    return (x != other.x) || (y != other.y);
}

//...
```

`include/main.cpp`

```cpp
#include "../include/Point.h"

#include <iostream>
using namespace std;

int main() {
    Point p1{10, 20};
    Point p2{10, 20};
    if (p1 == p2) {
        cout << "Both are same" << endl;
    }
    return 0;
}
```


## Copy Assignment Operator : `=`

Assignment operator is called when an **already initialized object is assigned a new value from another existing object**.

```cpp
class Product {
private:
    int id;
    char *name;
    int mrp; // maximum retail price
    int selling_price;
public:

    Product(int id, char *name, int mrp, int selling_price) {
        this->id = id;
        this->mrp = mrp;
        this->selling_price = selling_price;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    void operator=(const Product &source) {
        id = source.id;
        mrp = source.mrp;
        selling_price = source.selling_price;
        // deep copy
        name = new char[strlen(source.name) + 1];
        strcpy(name, source.name);
    }
//..
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
```

## Stream Insertion Operator `<<`

`<<` is a binary operator that takes two operands: a stream and a value. The stream is the left operand and the value is the right operand. The stream is modified by inserting the value into the stream.

- stream insertion operator must be declared outside the class as a global function

`include/Point.h`

```cpp
#ifndef MACRO_POINT_H
#define MACRO_POINT_H
#include <iostream>
using namespace std;

class Point {
public:
    Point(int x, int y);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    //..
private:
    int x;
    int y;
};

// outside the class
ostream &operator<<(ostream &stream, const Point &point);

#endif // MACRO_POINT_H
```

`include/Point.cpp`

```cpp
#include "../include/Point.h"
#include <iostream>

using namespace std;

ostream &operator<<(ostream &stream, const Point &point) {
    stream << "Point(" << point.getX() << ", " << point.getY() << ")";
    return stream;
    /* must return the stream object to allow chaining with cout:
     * cout << px<<px<<pz..<<endl;
     */
}
//...
```

`src/main.cpp`

```cpp
#include "../include/Point.h"
#include <iostream>
using namespace std;

int main() {
    Point p1{10, 20};
    Point p2{11, 22};
    cout << p1 << p2 << endl;//Point(10, 20)Point(11, 22)
    return 0;
}
```

## Stream Extraction Operator:`>>`

`>>` is a binary operator that takes two operands: a stream and a value. The stream is the left operand and the value is the right operand. The stream is modified by extracting the value from the stream.

- stream extraction operator must be declared outside the class as a global function.

`include/Point.h`

```cpp
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
```

`include/Point.cpp`

```cpp
#include "../include/Point.h"
#include <iostream>
istream &operator>>(istream &stream, Point &p) {
    int x, y;
    stream >> x >> y;
    p.setX(x);
    p.setY(y);
    return stream;
}
//...
```

`src/main.cpp`

```cpp
#include "../include/Point.h"

#include <iostream>
using namespace std;

int main() {
    Point p;
    cout << "Enter a point (x y): ";
    cin >> p;
    cout << p << endl;

    return 0;
}
```
