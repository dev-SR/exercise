#include <fstream>
#include <iostream>
using namespace std;

int main() {
    fstream file;
    file.open("test.txt", ios::in | ios::out | ios::app);

    if (file.is_open()) {
        file.close();
    }
}