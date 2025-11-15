#include <bits/stdc++.h>
using namespace std;

/*
Problem: Max Sum After Partitioning
-----------------------------------
Given an integer array 'arr' and an integer 'k', partition the array into contiguous
subarrays of at most length 'k'. After partitioning, each subarray’s elements are 
replaced with its maximum value. The goal is to maximize the sum of the entire array.

Example:
---------
Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: 
Partition: [1,15,7], [9,2,5], [10]
→ [15,15,15,9,9,9,10] = 84
*/


// ------------------- Top-Down (Memoization) -------------------
int topdown(int i, vector<int>& arr, int k, vector<int>& dp) {
    int n = arr.size();
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];

    int maxi = INT_MIN;
    int currMax = arr[i];

    for (int idx = 0; idx < k && i + idx < n; idx++) {
        currMax = max(currMax, arr[i + idx]);
        int cost = currMax * (idx + 1) + topdown(i + idx + 1, arr, k, dp);
        maxi = max(maxi, cost);
    }

    return dp[i] = maxi;
}

int maxSumAfterPartitioning_topdown(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n, -1);
    return topdown(0, arr, k, dp);
}


// ------------------- Bottom-Up (Tabulation) -------------------
int maxSumAfterPartitioning_bottomup(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0); // dp[i] = max sum from i...end

    // Fill dp from end to start
    for (int i = n - 1; i >= 0; i--) {
        int maxi = INT_MIN;
        int currMax = arr[i];
        for (int idx = 0; idx < k && i + idx < n; idx++) {
            currMax = max(currMax, arr[i + idx]);
            int cost = currMax * (idx + 1) + dp[i + idx + 1];
            maxi = max(maxi, cost);
        }
        dp[i] = maxi;
    }

    return dp[0];
}


// ------------------- Main Function -------------------
int main() {
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    cout << "Top-Down Result: " << maxSumAfterPartitioning_topdown(arr, k) << endl;
    cout << "Bottom-Up Result: " << maxSumAfterPartitioning_bottomup(arr, k) << endl;

    return 0;
}
