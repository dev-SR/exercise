#include <iostream>
#include <limits>

using namespace std;

int getNumber(const string &prompt) {
    int number;
    while (true) {
        cout << prompt;
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    return number;
}

int main() {
    int first = getNumber("Enter first number:");
    int second = getNumber("Enter second number:");
    cout << endl
         << first << " " << second << endl;

    return 0;
}