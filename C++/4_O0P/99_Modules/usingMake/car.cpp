#include "car.h"
// "" to search header files in current directory
// <> for default include directory of compiler
//constructor ex3 init

Car::Car() {
    cout << "1. Constructing...." << endl;
    speed = 0;
    isEngineOn = false;
}

Car::Car(string c) {
    cout << "2. Constructing with ....[" << c << "]" << endl;
    color = c;
    speed = 0;
    isEngineOn = false;
}

int Car::getSpeed() { //getter
    return speed;
}

void Car::accelerate(int by) {
    speed += by;
}

void Car::applyBreak() {
    if (speed - 8 >= 0)
        speed -= 10;
    else
        speed = 0;
}
void Car::startEngine() {
    if (!isEngineOn) {
        isEngineOn = true;
    }
}

void Car::stopEngine() {
    if (isEngineOn) {
        isEngineOn = false;
        speed = 0;
    }
}

string Car::toString() {
    ostringstream oss;
    oss << "Car = { name: " << name << ", color: "
        << ", speed: " << speed << " }";
    if (isEngineOn)
        oss << ", Engine is on" << endl;
    else
        oss << ", Engine is off" << endl;
    return oss.str();
}