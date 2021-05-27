// O(n) solution for finding maximum sum of
// a subarray of size k
#include <iostream>
using namespace std;

// Returns maximum sum in a subarray of size k.
void maxSum(int arr[], int n, int k) {
    // k must be greater
    if (n < k) {
        cout << "Invalid";
        return;
    }

    // Compute sum of first window of size k
    int win_sum = 0;
    for (int i = 0; i < k; i++)
        win_sum += arr[i];

    // Compute sums of remaining windows by
    // removing first element of previous
    // window and adding last element of
    // current window.

    //    [i-k] - [k] + [i]
    int curr_sum = win_sum;
    int c = 0;
    for (int i = k; i < n; i++) {
        curr_sum = curr_sum + arr[i] - arr[i - k];
        // win_sum = max(win_sum, curr_sum);
        if (curr_sum > win_sum) {
            win_sum = curr_sum;
            c = i;
        }
    }
    // cout << c - k << " " << c << endl;
    for (int i = c - k; i <= c; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Max: " << win_sum;
}

// Driver code
int main() {
    int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    maxSum(arr, n, k);
    return 0;
}