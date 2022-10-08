#include "../include/TextBox.h"

string TextBox::getValue() {
    return value;
}

void TextBox::setValue(const string &value) {
    this->value = value;
}