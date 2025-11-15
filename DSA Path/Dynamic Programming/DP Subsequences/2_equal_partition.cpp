#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Problem: Partition Equal Subset Sum
// ============================================================
// Given an integer array nums, return true if you can partition
// the array into two subsets such that the sum of the elements
// in both subsets is equal.
// ============================================================


// ===================== TOP-DOWN (Memoization) =====================
bool topdownHelper(vector<int>& nums, int n, int target, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (n == 0) return nums[0] == target;
    if (dp[n][target] != -1) return dp[n][target];

    bool notTake = topdownHelper(nums, n - 1, target, dp);
    bool take = false;
    if (nums[n] <= target)
        take = topdownHelper(nums, n - 1, target - nums[n], dp);

    return dp[n][target] = take || notTake;
}

bool canPartition_TopDown(vector<int>& nums) {
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2 != 0) return false;

    int target = total / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return topdownHelper(nums, n - 1, target, dp);
}


// ===================== BOTTOM-UP (Tabulation) =====================
bool canPartition_Tabulation(vector<int>& nums) {
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2 != 0) return false;

    int target = total / 2;
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // Base case: sum 0 is always possible
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    // Base case for first element
    if (nums[0] <= target)
        dp[0][nums[0]] = true;

    // Build DP table
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= target; j++) {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (nums[i] <= j)
                take = dp[i - 1][j - nums[i]];
            dp[i][j] = take || notTake;
        }
    }

    return dp[n - 1][target];
}


// ===================== SPACE OPTIMIZED =====================
bool canPartition_SpaceOptimized(vector<int>& nums) {
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2 != 0) return false;

    int target = total / 2;
    vector<bool> prev(target + 1, false), curr(target + 1, false);

    prev[0] = curr[0] = true;
    if (nums[0] <= target) prev[nums[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= target; j++) {
            bool notTake = prev[j];
            bool take = false;
            if (nums[i] <= j)
                take = prev[j - nums[i]];
            curr[j] = take || notTake;
        }
        prev = curr;
    }

    return prev[target];
}


// ============================================================
// Main Function with Multiple Test Cases
// ============================================================
int main() {
    vector<vector<int>> testCases = {
        {1, 5, 11, 5},
        {1, 2, 3, 5},
        {2, 2, 3, 5},
        {3, 3, 3, 4, 5},
        {1, 1, 1, 1, 1, 1}
    };

    cout << "============================================================\n";
    cout << "              PARTITION EQUAL SUBSET SUM TESTS              \n";
    cout << "============================================================\n";

    for (int t = 0; t < testCases.size(); t++) {
        vector<int> nums = testCases[t];

        cout << "\nTest Case " << t + 1 << ":\n";
        cout << "Array: ";
        for (int x : nums) cout << x << " ";
        cout << "\n--------------------------------------------\n";
        cout << "Top-Down (Memoization):      " << (canPartition_TopDown(nums) ? "true" : "false") << "\n";
        cout << "Bottom-Up (Tabulation):      " << (canPartition_Tabulation(nums) ? "true" : "false") << "\n";
        cout << "Space Optimized DP:          " << (canPartition_SpaceOptimized(nums) ? "true" : "false") << "\n";
    }

    cout << "\n============================================================\n";
    cout << "Complexity:\n";
    cout << "  Top-Down  : O(N * K)\n";
    cout << "  Bottom-Up : O(N * K)\n";
    cout << "  Space Opt : O(K)\n";
    cout << "============================================================\n";

    return 0;
}
