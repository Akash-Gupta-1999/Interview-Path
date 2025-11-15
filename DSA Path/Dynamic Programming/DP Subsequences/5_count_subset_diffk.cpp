#include <bits/stdc++.h>
using namespace std;

/* =========================================================
   COUNT OF SUBSETS WITH GIVEN DIFFERENCE (Striver-style)
   =========================================================
   Formula:
   sum(S1) - sum(S2) = diff
   => sum(S1) = (totalSum + diff) / 2
   Then count subsets with sum = target
   ========================================================= */

/* ---------------------------------------------------------
   1️⃣ Top-down recursion + memoization (2 functions)
   --------------------------------------------------------- */

// Recursive helper
int countSubsetsHelper(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
    // Base case
    if (i == 0) {
        if (target == 0 && nums[0] == 0)
            return 2; // two possibilities: take or not take zero
        if (target == 0 || nums[0] == target)
            return 1; // either empty set or single element equal to target
        return 0; // no subset found
    }

    // Memoization check
    if (dp[i][target] != -1)
        return dp[i][target];

    // Not take
    int notTake = countSubsetsHelper(i - 1, target, nums, dp);

    // Take
    int take = 0;
    if (nums[i] <= target)
        take = countSubsetsHelper(i - 1, target - nums[i], nums, dp);

    dp[i][target] = take + notTake;
    return dp[i][target];
}

// Main top-down function
int countSubsetsWithGivenDiff_topdown(vector<int>& nums, int diff) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    if ((totalSum + diff) % 2 != 0 || totalSum < diff)
        return 0; // invalid case

    int target = (totalSum + diff) / 2;
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return countSubsetsHelper(n - 1, target, nums, dp);
}

/* ---------------------------------------------------------
   2️⃣ Bottom-up tabulation
   --------------------------------------------------------- */
int countSubsetsWithGivenDiff_tab(vector<int>& nums, int diff) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if ((totalSum + diff) % 2 != 0 || totalSum < diff)
        return 0;

    int target = (totalSum + diff) / 2;
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // Base case for i == 0
    if (nums[0] == 0)
        dp[0][0] = 2; // {} and {0}
    else
        dp[0][0] = 1; // only {}

    if (nums[0] != 0 && nums[0] <= target)
        dp[0][nums[0]] = 1;

    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= target; t++) {
            int notTake = dp[i - 1][t];
            int take = 0;
            if (nums[i] <= t)
                take = dp[i - 1][t - nums[i]];
            dp[i][t] = take + notTake;
        }
    }

    return dp[n - 1][target];
}

/* ---------------------------------------------------------
   3️⃣ Space optimized version
   --------------------------------------------------------- */
int countSubsetsWithGivenDiff_spaceOpt(vector<int>& nums, int diff) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if ((totalSum + diff) % 2 != 0 || totalSum < diff)
        return 0;

    int target = (totalSum + diff) / 2;
    int n = nums.size();

    vector<int> prev(target + 1, 0);

    if (nums[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;

    if (nums[0] != 0 && nums[0] <= target)
        prev[nums[0]] = 1;

    for (int i = 1; i < n; i++) {
        vector<int> curr(target + 1, 0);
        for (int t = 0; t <= target; t++) {
            int notTake = prev[t];
            int take = 0;
            if (nums[i] <= t)
                take = prev[t - nums[i]];
            curr[t] = take + notTake;
        }
        prev = curr;
    }

    return prev[target];
}

/* =========================================================
   TEST CASES
   ========================================================= */
int main() {
    vector<int> nums = {1, 1, 2, 3};
    int diff = 1;
    // Expected: 3

    cout << "Top-down: " << countSubsetsWithGivenDiff_topdown(nums, diff) << endl;
    cout << "Tabulation: " << countSubsetsWithGivenDiff_tab(nums, diff) << endl;
    cout << "Space-opt: " << countSubsetsWithGivenDiff_spaceOpt(nums, diff) << endl;

    // Extra tests
    vector<vector<int>> tests = {
        {1, 2, 3, 1, 2},
        {0, 0, 1},
        {5, 2, 6, 4},
        {1, 1, 1, 1}
    };
    vector<int> diffs = {1, 1, 3, 0};

    for (int t = 0; t < tests.size(); t++) {
        cout << "\nArray: ";
        for (int x : tests[t]) cout << x << " ";
        cout << "\nDiff = " << diffs[t] << "\n";
        cout << "Count: " << countSubsetsWithGivenDiff_spaceOpt(tests[t], diffs[t]) << "\n";
    }

    return 0;
}
