#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <string>
using namespace std;

class TextBox {
private:
    string value;

public:
    string getValue();
    void setValue(const string &value);
};

#endif