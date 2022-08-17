#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"
//Retruning Local Array
int *fun() {
    //static Stack memory:
    int a[] = {10, 20, 30};
    cout << GRN << "fun()-> " << a << " : address" << reset << endl;
    cout << GRN << "fun()-> " << a[0] << " : value" << reset << endl;
    //! We should never return a local variable
    //! Local variable get destroyed after function call
    return a;
    // warning: address of local variable 'a' returned
}

//Retruning Dynamic Array
int *fun2() {
    //static Stack memory:
    int *a = new int[5];
    a[0] = 10;
    a[1] = 20;
    cout << GRN << "fun2()-> " << a << " : address" << reset << endl;
    cout << GRN << "fun2()-> " << a[0] << " : value" << reset << endl;
    //! We should never return a local variable
    //! Local variable get destroyed after function call
    return a;
    // warning: address of local variable 'a' returned
}

int main() {
    // int *b = fun();
    // cout << YEL << "main()-> " << b << " : address" << reset << endl;
    // cout << RED << "main()-> " << b[0] << " : value" << reset << endl;

    //VS

    int *c = fun2();
    cout << YEL << "main()-> " << c << " : address" << reset << endl;
    cout << RED << "main()-> " << c[0] << " : value" << reset << endl;
    delete[] c;
    return 0;
}
