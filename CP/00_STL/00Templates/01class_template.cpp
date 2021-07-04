#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"
//Generic Class using Template:

// template <typename T> or,
template <class T>
class Complex {
private:
    T real, imag;

public:
    Complex(T &, T &);
    T &getReal();
    T &getImag();
};

template <class T>
Complex<T>::Complex(T &a, T &b) {
    real = a;
    imag = b;
}

template <class T>
T &Complex<T>::getReal() {
    return real;
}

template <class T>
T &Complex<T>::getImag() {
    return imag;
}

//Working with multi-type Generics:
template <class T, class U>
class A {
    T x;
    U y;

public:
    A() {
        cout << "Constructor Called" << endl;
    }
};
int main() {
    double i = 3, j = 5;
    Complex<double> myComplex(i, j);

    std::cout << "z = " << myComplex.getReal() << " + "
              << myComplex.getImag() << "i" << std::endl;
    //more than one arguments to templates
    A<char, char> a;
    A<int, double> b;
    return 0;
}