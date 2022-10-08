#include "../include/Length.h"
#include <iostream>

using namespace std;

Length::Length(int value) : value(value){};
int Length::getValue() const {
    return value;
};
void Length::setValue(int value) {
    this->value = value;
};

// `==` compare operator
bool Length::operator==(const Length &other) const {
    return value == other.value;
}
