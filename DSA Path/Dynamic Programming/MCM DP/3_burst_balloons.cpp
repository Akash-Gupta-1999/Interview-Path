#include <bits/stdc++.h>
using namespace std;

/*
Problem: Burst Balloons
-----------------------
You are given n balloons, each balloon has a number on it represented by nums[i].
You can burst a balloon i, gaining coins equal to:
    nums[i - 1] * nums[i] * nums[i + 1]
After bursting balloon i, it disappears, and the adjacent balloons become neighbors.

Return the maximum coins you can collect by bursting the balloons wisely.

Example:
--------
Input: nums = [3,1,5,8]
Output: 167
Explanation:
    nums = [3,1,5,8]
    Burst 1 -> 3*1*5 = 15, remaining [3,5,8]
    Burst 5 -> 3*5*8 = 120, remaining [3,8]
    Burst 3 -> 1*3*8 = 24, remaining [8]
    Burst 8 -> 1*8*1 = 8
    Total = 167

Intuition:
----------
This is a Matrix Chain Multiplication style DP problem.
We choose which balloon to burst last in a range (i...j), and recursively
compute the best for left and right subarrays.
The transition:
    dp[i][j] = max over k in [i...j] of:
                nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j]
*/

// ------------------- Recursive + Memoization (Top-Down) -------------------
int topdown(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int maxi = INT_MIN;
    for (int k = i; k <= j; k++) {
        int coins = nums[i - 1] * nums[k] * nums[j + 1]
                    + topdown(i, k - 1, nums, dp)
                    + topdown(k + 1, j, nums, dp);
        maxi = max(maxi, coins);
    }
    return dp[i][j] = maxi;
}

// ------------------- Tabulation (Bottom-Up) -------------------
int bottomup(vector<int> nums) {
    int n = nums.size() - 2; // exclude the added 1s
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // Fill for increasing lengths of subarrays
    for (int i = n; i >= 1; i--) {
        for (int j = i; j <= n; j++) {
            int maxi = INT_MIN;
            for (int k = i; k <= j; k++) {
                int coins = nums[i - 1] * nums[k] * nums[j + 1]
                            + dp[i][k - 1] + dp[k + 1][j];
                maxi = max(maxi, coins);
            }
            dp[i][j] = (maxi == INT_MIN ? 0 : maxi);
        }
    }

    return dp[1][n];
}

// ------------------- Wrapper Function -------------------
int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    int topDownAns = topdown(1, n, nums, dp);
    int bottomUpAns = bottomup(nums);

    cout << "Top-Down (Memoization): " << topDownAns << endl;
    cout << "Bottom-Up (Tabulation): " << bottomUpAns << endl;

    return bottomUpAns;
}

// ------------------- Main Function -------------------
int main() {
    vector<vector<int>> testCases = {
        {3, 1, 5, 8},       // Expected: 167
        {1, 5},             // Expected: 10
        {1, 2, 3},          // Expected: 12
        {7, 9, 8, 0, 7, 1, 3, 5, 5, 2, 3}, // Random stress case
        {9, 76, 64, 21}     // Example large numbers
    };

    for (auto nums : testCases) {
        cout << "Balloons: ";
        for (int x : nums) cout << x << " ";
        cout << "\n";
        maxCoins(nums);
        cout << "------------------------------------\n";
    }

    return 0;
}
