#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"
/**
The term input is used from the viewpoint of a program. In other words, `information going from the container to the program` is considered input. So, an input iterator is one that a program can use to read values from a container. Dereferencing an input iterator allows us to read a value from a container, but it does not allow us to alter the value. So algorithms that require an input iterator are algorithms that don't modify values of the container elements.

Dereferencing: 
 An input iterator can be dereferenced, using the operator * and -> as an rvalue to obtain the value stored at the position being pointed to by the iterator.

*A       // Dereferencing using *
A -> m   // Accessing a member element m

Limitations: 
Only accessing, no assigning.
A--    // Not allowed with input iterators
If A and B are input iterators, then
A == B  // Checking for equality
A != B  // Checking for inequality
A <= B     // Not Allowed
A + 1     // Not allowed
B - 2     // Not allowed

*/
int main() {
    ifstream myInt("data");
    istream_iterator<int> iter(myInt);
    istream_iterator<int> eos; // end of stream iterator

    cout << "Sum of the data is "
         //accumulate(input_iter, input_iter, value)
         << accumulate(iter, eos, 0) //#include <numeric>  // for accumulate()
         << endl;

    cout << RED << "ex2:" << reset << endl;
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int>::iterator i1;
    for (i1 = v1.begin(); i1 != v1.end(); ++i1) {
        cout << (*i1) << " ";
    }
    return 0;
}
