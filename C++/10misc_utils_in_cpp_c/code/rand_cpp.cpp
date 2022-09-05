#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    srand(time(NULL)); // srand(time(0));
    const short int MAX = 100;
    const short int MIN = 20;
    int n = (rand() % (MAX - MIN + 1)) + MIN;
    cout << n << endl;

    return 0;
}