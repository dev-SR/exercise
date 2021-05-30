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
void display(int *p, int n) {
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    //allocate memory
    // int *p = new int[n];
    // or,
    int *p{new int[n]};

    for (int i = 0; i < n; i++) {
        cout << "el:";
        cin >> p[i];
    }
    display(p, n);

    //deallocate memory
    delete[] p;

    //Example: DMA and returing pointer from functions:
    cout << BLU << "EX:" << reset << endl;
    int *ptr = getArray(10);
    display(ptr, 10);
    delete[] ptr;
    return 0;
}

int *getArray(int n) {
    int *p = new int[n];

    srand(time(NULL)); //time_t t = time(NULL);
    /**
    X://? void srand(unsigned seed) : 
     * Seeds the pseudo - random number generator used by 
     * rand() with the value seed.

    The srand(x) function sets the seed of the random number generator algorithm used by the function rand( ).  A seed value of 1 is the default setting yielding the same sequence of values as if srand(x) were not used.  Any other value for the seed produces a different sequence.
    
    X://? srand(time(NULL));
    makes use of the computer's internal clock to control the choice of the seed.  Since time is continually changing, the seed is forever changing.  
     * https://mathbits.com/MathBits/CompSci/LibraryFunc/rand.htm
    */
    for (int i = 0; i < n; i++) {
        p[i] = rand() % 100;
    }
    return p;
}