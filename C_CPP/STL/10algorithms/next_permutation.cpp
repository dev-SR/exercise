#include <algorithm> //  next_permutation
#include <iostream>
using namespace std;
int main() {
    string s = "abc";
    auto first = s.begin();
    auto last = s.end();
    sort(first, last); // sort should be applied if we want all permutations
    do {
        cout << s << endl;
    } while (next_permutation(first, last));
}
/*
abc
acb
bac
bca
cab
cba
 */