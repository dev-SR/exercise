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
    int *arr;
    int cs; //current size
    int maxSize;

public:
    Vector(int defaultSize = 4) {
        maxSize = defaultSize;
        cs = 0;
        arr = new int[maxSize];
    }
    void push_back(int data) {
        if (cs == maxSize) {
            //Doubling operation
            int *oldArr = arr;
            arr = new int[2 * maxSize];
            maxSize *= 2;

            //copy
            for (int i = 0; i < cs; i++) {
                arr[i] = oldArr[i];
            }
            //delete the oldArr
            delete[] oldArr;
        }
        arr[cs] = data;
        cs++;
    }
    bool empty() {
        return cs == 0;
    }

    void pop_back() {
        if (!empty())
            cs--;
    }
    void print() {
        cout << "array[] = [ ";
        for (int i = 0; i < cs; i++) {
            cout << arr[i];
            if (i != cs - 1) {
                cout << ", ";
            }
        }
        cout << " ]";
        cout << endl;
    }
    int at(int i) {
        return arr[i];
    }

    int getSize() {
        return cs;
    }
    int getMaxSize() {
        return maxSize;
    }
    int operator[](int i) {
        return arr[i];
    }
};

ostream &operator<<(ostream &os, Vector &v) {
    cout << endl
         << CYN << "In << operator:" << reset << endl;
    v.print();
    return os;
}
istream &operator>>(istream &is, Vector &c) {
    return is;
}
int main() {
    //defd  dfd ddc
    cout << GRN << setfill('*') << setw(60) << "*" << reset << endl;
    Vector v;
    for (int i = 0; i < 4; i++) {
        v.push_back(i * i);
    }
    cout << "Max size:" << v.getMaxSize() << endl;
    v.push_back(7);

    cout << "Max size:" << GRN << v.getMaxSize() << reset << endl;
    v.print();

    // predefined size
    cout << GRN << setfill('*') << setw(60) << "*" << reset << endl;
    Vector v1(100);
    for (int i = 0; i < 4; i++) {
        v1.push_back(i * i);
    }
    cout << "Max size:" << v.getMaxSize() << endl;
    v1.push_back(7);
    cout << "Max size:" << GRN << v.getMaxSize() << reset << endl;
    v1.print();

    //overloaded operator
    cout << GRN << setfill('*') << setw(60) << "*" << reset << endl;
    cout << CYN << "In [] operator:" << reset << endl;
    cout << v[3] << endl;
    for (int i = 0; i < v.getSize(); i++) {
        cout << v[i] << " ";
    }

    cout << v;

    return 0;
}