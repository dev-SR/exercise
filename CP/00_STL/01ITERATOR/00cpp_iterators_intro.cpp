#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"

int main() {
    vector<int> v = {1, 2, 3};
    vector<int>::iterator i;
    int j;
    // Inserting element using iterators
    for (i = v.begin(); i != v.end(); ++i) {
        if (i == v.begin()) {
            i = v.insert(i, 5);
            // inserting 5 at the beginning of v
        }
    }

    // v contains 5 1 2 3
    // Deleting a element using iterators
    for (i = v.begin(); i != v.end(); ++i) {
        if (i == v.begin() + 1) {
            i = v.erase(i);
            // i now points to the element after the
            // deleted element
        }
    }

    // v contains 5 2 3
    // Accessing the elements using iterators
    cout << endl;
    for (i = v.begin(); i != v.end(); ++i) {
        cout << *i << " ";
    }

    return 0;
}