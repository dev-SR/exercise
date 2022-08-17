#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"
class Vector {
    int *data;
    int cs;
    int cap; // total size

public:
    Vector() {
        data = new int[5];
        cs = 0;
        cap = 5;
    }

    Vector(Vector const &d) {
        //this -> data = d.data;		// Shallow copy

        // Deep copy
        this->data = new int[d.cap];
        for (int i = 0; i < d.cs; i++) {
            this->data[i] = d.data[i];
        }
        this->cs = d.cs;
        this->cap = d.cap;
    }

    void operator=(Vector const &d) {
        this->data = new int[d.cap];
        for (int i = 0; i < d.cs; i++) {
            this->data[i] = d.data[i];
        }
        this->cs = d.cs;
        this->cap = d.cap;
    }

    void add(int element) {
        if (cs == cap) {
            int *newData = new int[2 * cap];
            for (int i = 0; i < cap; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            cap *= 2;
        }
        data[cs] = element;
        cs++;
    }

    int get(int i) const {
        if (i < cs) {
            return data[i];
        } else {
            return -1;
        }
    }

    void add(int i, int element) {
        if (i < cs) {
            data[i] = element;
        } else if (i == cs) {
            add(element);
        } else {
            return;
        }
    }

    void print() const {
        for (int i = 0; i < cs; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Vector d1;

    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    d1.print();

    Vector d2(d1); // Copy constructor

    Vector d3;

    d3 = d1;

    d1.add(0, 100);

    d2.print();
    d3.print();
    return 0;
}