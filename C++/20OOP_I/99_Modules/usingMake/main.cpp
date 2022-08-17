#include "car.h"
int main() {
    Car c1;
    c1.name = "BMW";
    c1.color = "RED";
    cout << c1.toString() << endl;
    c1.startEngine();
    c1.accelerate(10);
    c1.accelerate(30);
    cout << c1.toString() << endl;
    c1.applyBreak();
    cout << c1.toString() << endl;
    c1.stopEngine();
    cout << c1.toString() << endl;
    return 0;
}