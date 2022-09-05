#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a[100], left = 0, right = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int maxSum = 0;
    int currentSum = 0;

    //Generating All Subarray
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            //!current sum of subarray(i,j)
            currentSum = 0;
            for (int k = i; k <= j; k++) {
                currentSum += a[k];
            }
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
