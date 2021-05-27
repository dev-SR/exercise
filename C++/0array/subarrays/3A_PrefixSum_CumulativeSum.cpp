#include <bits/stdc++.h>
using namespace std;
//https://www.hackerrank.com/topics/prefix-sum
// Prefix sum is the cumulative sum of a sequence of numbers a0, a1, ....
// It is itself a sequence of numbers b0, b1, ... such that
// PreSum0 = a0
// PreSum1 = a0 + a1 = PreSum0 + a1
// PreSum2 = a0 + a1 + a2 = PreSum1 + a2
// .........
// PreSum[n] = PreSum[n-1] + a[n]

//examples:
// A[] = {1, 3, 4, 5, 2, 7, 8, 11}
// The prefix sums corresponding to A will be
// PreSum[] = {1, 4, 8, 13, 15, 22, 30, 41}

// elements : 1 2 3
// PreSum[1] = PreSum[0] : (1) + a[1] : (2) = 3
// PreSum[2] = PreSum[1] : (3) + a[2] : (3) = 6

int main() {
    int a[100], n, PreSum[100];
    cout << "el size: ";
    cin >> n;
    cout << "enter elements: ";

    // A is a sequence containing n elements

    // PreSum[0]=A[0]

    // for i=1 to n-1
    //     PreSum[i]=PreSum[i-1]+A[i]

    cin >> a[0];
    PreSum[0] = a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        PreSum[i] = PreSum[i - 1] + a[i];
    }

    for (int i = 1; i < n; i++) {
        cout << "PreSum[" << i << "] = "
             << " PreSum[" << (i - 1) << "]:(" << PreSum[i - 1] << ") + "
             << " a[" << i << "]:(" << a[i] << ") = " << PreSum[i] << endl;
    }

    // sum of values between[L..R]
    // Sum[L..R] = PreSum[R] - PreSum[L - 1]{If L != 0}
    // Sum[L..R] = PreSum[R] { If L = 0 }

    int l, r;
    cout << "sum from ";
    cin >> l;
    cout << " to ";
    cin >> r;
    cout << "[" << l << ":" << r << "] = " << (PreSum[r] - PreSum[l - 1]);
}

/**
 * 
el size: 5
enter elements: 1 2 3 4 5
PreSum[1] =  PreSum[0]:(1) +  a[1]:(2) = 3
PreSum[2] =  PreSum[1]:(3) +  a[2]:(3) = 6
PreSum[3] =  PreSum[2]:(6) +  a[3]:(4) = 10
PreSum[4] =  PreSum[3]:(10) +  a[4]:(5) = 15
sum from 2 3
 to [2:3] = 7    (3+4)
*/