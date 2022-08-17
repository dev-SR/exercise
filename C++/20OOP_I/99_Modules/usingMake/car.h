/**
 * TO: avoid multiple inclusion of this header file:
 * we use #ifndef(if not defined). 
*/

// #ifndef CAR_H // if not defined already
// #define CAR_H

#include <bits/stdc++.h>
using namespace std;
class Car {
public:
    string name;
    string color{"Gray"};

private:
    int speed;
    bool isEngineOn;

public:
    Car();
    Car(string c);

    void accelerate(int by);
    void applyBreak();
    int getSpeed();
    void startEngine();
    void stopEngine();
    string toString();
};

// #endif