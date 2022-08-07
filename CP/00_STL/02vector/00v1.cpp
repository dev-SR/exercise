#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
void print(vector<int> &v) {
    for (int i : v)
        cout << i << " ";
    cout << endl;
}

int main() {
    // empty container constructor
    vector<int> v1;
    // fill constructor (4 int with value 10)
    vector<int> v2(4, 10);

    // range constructor
    int n[] = {1, 2, 3, 4};
    vector<int> v3(n, n + 4);

    // copy constructor
    vector<int> v4(v3);

    // assignment operator
    vector<int> v5;
    v5 = v3;

    // initializer list constructor
    vector<int> v6{1, 2, 3, 4};
    print(v6);

    // Another way
    vector<int> v7 = {1, 2, 3, 4};
    print(v7);

    return 0;
}