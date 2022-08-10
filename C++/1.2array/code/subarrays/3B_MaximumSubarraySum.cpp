#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a[100], left = 0, right = 0, l, r;
    cin >> n;
    int PreSum[100];

    // A is a sequence containing n elements
    // PreSum[0]=A[0]
    // for i=1 to n-1
    //     PreSum[i]=PreSum[i-1]+A[i]
    //* O(n) -------------------------
    cin >> a[0];
    PreSum[0] = a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        PreSum[i] = PreSum[i - 1] + a[i];
    }
    //*  ----------------------------

    int maxSum = 0;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            //!current sum of subarray(l,r)
            currentSum = 0;
            l = i;
            r = j;
            // for (int k = i; k <= j; k++) {
            //     currentSum += a[k];
            // }
            //*
            currentSum = PreSum[r] - PreSum[l - 1];
            //*
            //?Update maxSum if cs > ms
            if (currentSum > maxSum) {
                maxSum = currentSum;
                //remember indices
                left = i;
                right = j;
            }
        }
    }
    cout << "MAX is: " << maxSum << endl;

    for (int i = left; i <= right; i++)
        cout << a[i] << " ";
}
