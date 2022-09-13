#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ofstream file;
    file.open("test.csv");

    if (file.is_open()) {
        file << "id,name,age\n"
             << "1,John,30\n"
             << "2,Jack,25\n";
    }
    file.close();
}