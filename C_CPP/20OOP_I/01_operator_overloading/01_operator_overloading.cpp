// Operators that operate on two operands are known as binary operators.
// Operators that operate on one operand are known as unary operators.
#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"

class Complex {
    int real;
    int img;

public:
    Complex() {
        real = 0;
        img = 0;
    }
    Complex(int r, int i) {
        real = r;
        img = i;
    }
    void setReal(const int r) {
        real = r;
    }
    void setImg(const int i) {
        img = i;
    }
    int getReal() const {
        return real;
    }
    int getImg() const {
        return img;
    }
    void print() {
        if (img > 0) {
            cout << GRN << real << " + " << img << "i" << reset << endl;
        } else {
            cout << RED << real << " - " << -img << "i" << reset << endl;
        }
    }
    void add(const Complex &x) {
        real += x.real;
        img += x.img;
    }
    void operator+(const Complex &x) {
        real += x.real;
        img += x.img;
    }
    void operator!() {
        img *= -1;
    }
    int operator[](string s) {
        if (s == "real")
            return real;
        else
            return img;
    }
};
/*
void operator>>(istream& is,Complex &c){
int r1,i1;
is>>r1>>i1;
c.setReal(r1);
c.setImg(i1);
}
void operator<<(ostream& is,Complex &c){
c.print();
}
*/
istream &operator>>(istream &is, Complex &c) {
    int r1, i1;
    is >> r1 >> i1;
    c.setReal(r1);
    c.setImg(i1);
    return is;
}
ostream &operator<<(ostream &os, Complex &c) {
    c.print();
    return os;
}
int main() {
    Complex c1(5, 3);
    Complex c2;
    c2.setReal(1);
    c2.setImg(4);
    c1.print();
    c2.print();
    //c1.add(c2);
    c1 + c2; // c1 + c2 ==  c1.+(c2)
    cout << MAG << "c1+c2:" << reset << endl;
    c1.print();
    cout << MAG << "!c1:" << reset << endl;
    !c1;
    c1.print();
    cout << MAG << "img(c1):" << reset << endl;
    cout << c1["img"] << endl;

    //Overloading >> ,<<
    cout << "Enter real and img part:";
    Complex d;
    cin >> d;
    cout << d;
    return 0;
}