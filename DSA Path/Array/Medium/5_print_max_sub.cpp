#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN;
    int sum = 0;

    int start_idx = 0, end_idx = 0;
    int tempStart = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
            start_idx = tempStart;
            end_idx = i;
        }

        if (sum < 0) {
            sum = 0;
            tempStart = i + 1;
        }
    }

    // Print subarray
    cout << "Subarray: ";
    for (int i = start_idx; i <= end_idx; i++)
        cout << arr[i] << " ";
    cout << endl;

    return maxi;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}
