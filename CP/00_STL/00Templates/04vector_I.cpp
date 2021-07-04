#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"

template <class T>
class Vectors {
    int sz;    // number of elements
    T *elem;   // address of first element
    int space; // number of elements plus free-space

public:
    Vectors() : sz(0), elem(0), space(0) {}
    Vectors(int s) : sz(s), elem(new T[s]), space(s) {
        for (int i = 0; i < sz; ++i)
            elem[i] = 0;
    }
    Vectors(const Vectors &);
    Vectors &operator=(const Vectors &v);

    ~Vectors() { delete[] elem; }

    T &at(int n);
    const T &at(int n) const;

    T &operator[](int n);
    const T &operator[](int n) const;

    int size() const { return sz; }
    int capacity() const { return space; }

    void reserve(int alloc_size);
    void resize(int resize_size);
    void push_back(const T &d);
};

template <class T>
void Vectors<T>::reserve(int alloc_size) {
    if (alloc_size <= space)
        return;
    T *p = new T[alloc_size];
    for (int i = 0; i < sz; ++i)
        p[i] = elem[i];
    delete[] elem;
    elem = p;
    space = alloc_size;
}

template <class T>
T &Vectors<T>::at(int n) {
    if (n < 0 || sz <= n)
        throw out_of_range();
    return elem[n];
}

template <class T>
const T &Vectors<T>::at(int n) const {
    if (n < 0 || sz <= n)
        throw out_of_range();
    return elem[n];
}

template <class T>
T &Vectors<T>::operator[](int n) {
    return elem[n];
}

template <class T>
const T &Vectors<T>::operator[](int n) const {
    return elem[n];
}

template <class T>
Vectors<T> &Vectors<T>::operator=(const Vectors<T> &v) {
    if (this == &v)
        return *this;

    if (v.sz <= space) {
        for (int i = 0; i < v.sz; ++i)
            elem[i] = v.elem[i];
        sz = v.sz;
        return *this;
    }

    T *p = new T[v.sz];
    for (int i = 0; i < v.sz; ++i)
        p[i] = v.elem[i];
    delete[] elem;
    space = sz = v.sz;
    elem = p;
    return *this;
}

template <class T>
void Vectors<T>::resize(int resize_size) {
    reserve(resize_size);
    for (int i = 0; i < resize_size; ++i)
        elem[i] = 0;
    sz = resize_size;
}

template <class T>
void Vectors<T>::push_back(const T &d) {
    if (space == 0)
        reserve(10);
    else if (sz == space)
        reserve(2 * space);
    elem[sz] = d;
    ++sz;
}

int main() {
    Vectors<double> dv(3);
    dv.resize(5);
    for (int i = 0; i < dv.size(); ++i) {
        cout << dv[i] << " "; //0 0 0 0 0
    }
    return 0;
}