#include <bits/stdc++.h>
using namespace std;

// =====================================================
// Problem: House Robber (cannot rob adjacent houses)
// =====================================================

// -----------------------------------------------------
// Method 1: Top-Down (Recursion + Memoization)
// Time Complexity: O(n)
// Space Complexity: O(n) + O(n) recursion stack
// -----------------------------------------------------
int rec(vector<int>& nums, int pos, vector<int>& dp) {
    if (pos < 0) return 0;
    if (dp[pos] != -1) return dp[pos];
    return dp[pos] = max(nums[pos] + rec(nums, pos - 2, dp),
                         rec(nums, pos - 1, dp));
}

int robTopDown(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return rec(nums, n - 1, dp);
}

// -----------------------------------------------------
// Method 2: Bottom-Up (Tabulation)
// Time Complexity: O(n)
// Space Complexity: O(n)
// -----------------------------------------------------
int robBottomUp(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);

    return dp[n - 1];
}

// -----------------------------------------------------
// Method 3: Space Optimized DP
// Time Complexity: O(n)
// Space Complexity: O(1)
// -----------------------------------------------------
int robSpaceOptimized(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int prev2 = nums[0];
    int prev = max(nums[0], nums[1]);
    int curr;

    for (int i = 2; i < n; i++) {
        curr = max(nums[i] + prev2, prev);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

// -----------------------------------------------------
// Main with Multiple Test Cases
// -----------------------------------------------------
int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3, 1},
        {2, 7, 9, 3, 1},
        {2, 1, 1, 2},
        {5},
        {10, 1, 10, 1, 10}
    };

    cout << "=====================================================\n";
    cout << "                 HOUSE ROBBER PROBLEM                \n";
    cout << "=====================================================\n";

    for (int t = 0; t < testCases.size(); t++) {
        cout << "\nTest Case " << t + 1 << ": ";
        for (int x : testCases[t]) cout << x << " ";
        cout << "\n---------------------------------------------\n";
        cout << "Top-Down (Memoized):   " << robTopDown(testCases[t]) << "\n";
        cout << "Bottom-Up (Tabulated): " << robBottomUp(testCases[t]) << "\n";
        cout << "Space Optimized:       " << robSpaceOptimized(testCases[t]) << "\n";
    }

    cout << "\n=====================================================\n";
    cout << "Complexity Summary:\n";
    cout << "-----------------------------------------------------\n";
    cout << "Top-Down:     O(n) Time | O(n) Space (stack + dp)\n";
    cout << "Bottom-Up:    O(n) Time | O(n) Space\n";
    cout << "Optimized:    O(n) Time | O(1) Space\n";
    cout << "=====================================================\n";

    return 0;
}
