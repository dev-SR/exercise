#include <bits/stdc++.h>
using namespace std;
//!Receiving variable's address in functions
void print(int *p) {
    cout << *p << endl; //10
}
void incrementPointer(int *p) {
    p = p + 1;
    //address's been incremented; P now point to a garbage value
    cout << *p << " " << p << " <-- p inside incrementPointer" << endl;
    //6422036 0x61fe18 <-- p inside incrementPointer
}
void increment(int *p) {
    (*p)++;
}

// Note that a[] for fun is just a pointer even if square
// brackets are used
int sum(int a[], int size) {
    cout << "SIZE:[sum]: " << sizeof(a) << endl;
    //SIZE:[sum]: 8 <- 'a' is effectively a pointer
    cout << a[0];     //1
    cout << *(a + 1); //2
    return 0;
}
int fun(int *a, int size) {
    cout << "SIZE:[sum]: " << sizeof(a) << endl;
    cout << a[0];     //1: So, use can use [] as well
    cout << *(a + 1); //2
    return 0;
}
int partialSum(int *a, int size) {
    int ans = 0;
    cout << a[0] << " " << size << endl; //4 2
    for (int i = 0; i < size; i++) {
        ans += a[i];
    }
    return ans;
}
int main() {
    int i = 10;
    int *p = &i;
    print(p);

    cout << i << " " << p << endl; //10 0x61fe14
    incrementPointer(p);
    cout << i << " " << p << endl; //10 0x61fe14
    increment(p);
    cout << i << " " << p << endl; //11 0x61fe14

    int a[5] = {1, 2, 3, 4, 5};
    cout << "SIZE:[main]: " << sizeof(a) << endl;
    //SIZE:[main]: 40
    sum(a, sizeof(a) / sizeof(a[0]));
    fun(a, sizeof(a) / sizeof(a[0]));
    int len = sizeof(a) / sizeof(a[0]);

    //!Only, the Partial parts of an array can be passed
    cout << partialSum(a + 3, len - 3); // 9 [4+5]
}