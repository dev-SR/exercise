#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"

class Car {
    //attributes
public:
    string name;
    string color{"Gray"};

private:
    int speed;
    bool isEngineOn;

public:
    //constructor ex1
    Car() {
        cout << "1. Constructing...." << endl;
        speed = 0;
        isEngineOn = false;
    }
    //constructor ex2
    Car(string c) {
        cout << "2. Constructing with ....[" << c << "]" << endl;
        color = c;
        speed = 0;
        isEngineOn = false;
    }
    //constructor ex3 declearation
    Car(string n, string c, int speed);
    //constructor ex4 Initialization List
    Car(string n, string c) : name(n), color(c) {}
    //method declearation + initialization;
    int getSpread() { //getter
        return speed;
    }
    //ex1: method declearation;
    void acceleration(int by); //setter
    void applyBreak();
    void startEngine();
    void stopEngine();
    string toString();
};
//constructor ex3 init
Car::Car(string n, string c, int speed) {
    cout << "3. Constructing with ....[" << n << ", " << c << ", " << speed << "]" << endl;
    name = n;
    color = c;
    this->speed = speed;
    isEngineOn = false;
}

//ex1: method initialization;
void Car::acceleration(int by) {
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

int main() {

    //Create objects statically
    Car c1;
    Car c2("RED");
    Car c3, c4("Audi", "BLACK", 10);
    c1.name = "BMW";
    c1.color = "RED";
    cout << c1.toString() << endl;
    c1.startEngine();
    c1.acceleration(10);
    c1.acceleration(30);
    cout << c1.toString() << endl;
    c1.applyBreak();
    cout << c1.toString() << endl;
    c1.stopEngine();
    cout << c1.toString() << endl;

    //Create objects dynamically
    Car *c5 = new Car;
    (*c5).name = "TATA";
    //or,
    c5->color = "BLUE";
    cout << c5->toString();
    delete c5;

    return 0;
}