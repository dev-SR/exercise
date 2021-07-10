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
    int arr[] = {20, 30, 40, 40, 40, 50, 100, 1100};
    int n = sizeof(arr) / sizeof(int);
    int key;
    cin >> key;

    bool present = binary_search(arr, arr + n, key);
    if (present) {
        cout << "Present";
    } else {
        cout << "Not Present";
    }

    /* 
Iterator lower_bound (Iterator first, Iterator last, const val) 
Iterator upper_bound (Iterator first, Iterator last, const val) 

upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’. 

upper_bound(arr, arr + n, 40)

                upper_bound
					▼
20, 30, 40, 40, 40, 50, 100, 1100


lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value `not` less than ‘val’. 

upper_bound(arr, arr + n, 40)

    lower_bound
		▼
20, 30, 40, 40, 40, 50, 100, 1100

WATCHOUT, upper_bound - lower__bound = frequency
 */
    //Get the index of the element
    //lower_bound(s,e,key) and upper_bound(s,e,key)
    auto lb = lower_bound(arr, arr + n, 40);
    cout << endl
         << "Lower bound of 40 is " << (lb - arr) << endl;

    auto ub = upper_bound(arr, arr + n, 40);
    cout << endl
         << "Upper bound of 40 is " << (ub - arr) << endl;

    cout << "Frequency of 40 is " << (ub - lb) << endl;
    return 0;
}