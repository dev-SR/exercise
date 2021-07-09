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
    int arr[] = {1, 10, 11, 9, 100};
    int n = sizeof(arr) / sizeof(int);
    int key;
    cin >> key;

    auto address_of_key = find(arr, arr + n, key);
    /**
	 ┌───┐───┐───┐───┐───────┐
     │arr│ ..│ ..│   │ arr+n │  so, last_address - base_address=(arr+n)-arr=`n`
     └───┘───┘───┘───┘───────┘
	  */
    int index = address_of_key - arr;

    if (index == n) {
        cout << key << " not present";
    } else {
        cout << "Present at index: " << index;
    }
    return 0;
}