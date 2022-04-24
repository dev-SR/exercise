#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"

int *getArray(int n);
void display(int &p, int n) {
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    // allocate memory
    // int *p = new int[n];
    // or,
    int *p{new int[n]};

    for (int i = 0; i < n; i++) {
        cout << "el[" << i << "] :";
        cin >> p[i];
    }
    display(p, n);

    // deallocate memory
    delete[] p;

    // Example: DMA and returing pointer from functions:
    cout << BLU << "Random:" << reset << endl;
    int *ptr = getArray(10);
    display(ptr, 10);
    delete[] ptr;
    return 0;
}

int *getArray(int n) {
    int *p = new int[n];

    // Use current time as seed for random generator
    srand(time(0)); // or time(NULL);
    /**
        Note: Without first calling srand(), program will create the same sequence of numbers each time it runs.
    */
    for (int i = 0; i < n; i++) {
        p[i] = rand() % 100;
    }
    return p;
}