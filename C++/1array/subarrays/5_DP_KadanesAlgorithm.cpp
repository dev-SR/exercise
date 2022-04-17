#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[] = {-4, 1, 3, -2, 6, 2, -8, -9, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    // int max_so_far = 0, max_ending_here = 0;

    // for (int i = 0; i < n; i++) {
    //     max_ending_here = max_ending_here + arr[i];

    //     if (max_so_far < max_ending_here)
    //         max_so_far = max_ending_here;

    //     if (max_ending_here < 0)
    //         max_ending_here = 0;

    //     cout << "For i = " << i << endl;
    //     cout << "Max_ending_here = " << max_ending_here << endl;
    //     cout << "Max_so_far = " << max_so_far << endl
    //          << endl;
    // }
    int ms = 0, cs = 0;

    int x = 0;
    for (int i = 0; i < n; i++) {
        cs = cs + arr[i];
        if (cs < 0)
            cs = 0;
        ms = max(cs, ms);

        // if (ms < cs) {
        //     ms = cs;
        // }

        cout << "For i = " << i << endl;
        cout << "cs = " << cs << endl;
        cout << "ms = " << ms << endl
             << endl;
    }


    cout << ms;
}