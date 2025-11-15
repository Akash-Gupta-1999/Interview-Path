#include <bits/stdc++.h>
using namespace std;

/* =========================================================
   COUNT OF SUBSETS WITH SUM K — ALL IN ONE
   (Top-down, Bottom-up, Space-optimized)
   ========================================================= */

/* -------------------------------
   1️⃣ TOP-DOWN (RECURSION + MEMO)
   ------------------------------- */

int countSubsetsTD(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
    // Base case: when only one element (i == 0)
    // Three possible scenarios:
    // why target == 0 return 1 and i == 0 return 0 fails because of elements containing Zero's
    // Case 1: nums[0] == 0 and target == 0
    // → Two ways possible: pick or not pick the 0
    if (i == 0) {
        if (target == 0 && nums[0] == 0) return 2;

        // Case 2: target == 0 (don’t pick anything)
        // or nums[0] == target (pick the first element)
        if (target == 0 || nums[0] == target) return 1;

        // Case 3: target cannot be formed
        return 0;
    }

    if (dp[i][target] != -1) return dp[i][target];

    // Not take current element
    int notTake = countSubsetsTD(i - 1, target, nums, dp);

    // Take current element (if it doesn't exceed target)
    int take = (nums[i] <= target)
        ? countSubsetsTD(i - 1, target - nums[i], nums, dp)
        : 0;

    // Store result
    return dp[i][target] = take + notTake;
}

int countSubsetsWithSumK_topdown(vector<int>& nums, int K) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(K + 1, -1));
    return countSubsetsTD(n - 1, K, nums, dp);
}

/* -------------------------------
   2️⃣ BOTTOM-UP (TABULATION)
   ------------------------------- */

int countSubsetsWithSumK_tab(vector<int>& nums, int K) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(K + 1, 0));

    // Base initialization for i = 0
    // If nums[0] == 0 -> two ways to make sum 0: {} and {0}
    if (nums[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1; // empty subset always makes sum 0

    // If first element <= target, we can make that sum by including it
    if (nums[0] != 0 && nums[0] <= K)
        dp[0][nums[0]] = 1;

    // Fill the DP table
    for (int i = 1; i < n; i++) {
        for (int target = 0; target <= K; target++) {
            int notTake = dp[i - 1][target];
            int take = (nums[i] <= target) ? dp[i - 1][target - nums[i]] : 0;
            dp[i][target] = take + notTake;
        }
    }

    return dp[n - 1][K];
}

/* -------------------------------
   3️⃣ SPACE OPTIMIZED
   ------------------------------- */

int countSubsetsWithSumK_spaceOpt(vector<int>& nums, int K) {
    int n = nums.size();
    vector<int> prev(K + 1, 0);

    // Base case for i = 0
    // If nums[0] == 0, there are two ways to make sum 0: {} and {0}
    if (nums[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1; // only empty subset makes sum 0

    // If nums[0] can directly make a sum <= K
    if (nums[0] != 0 && nums[0] <= K)
        prev[nums[0]] = 1;

    // Iterate over rest of array
    for (int i = 1; i < n; i++) {
        vector<int> curr(K + 1, 0);
        for (int target = 0; target <= K; target++) {
            int notTake = prev[target];
            int take = (nums[i] <= target) ? prev[target - nums[i]] : 0;
            curr[target] = take + notTake;
        }
        prev = curr;
    }

    return prev[K];
}

/* =========================================================
   TEST CASES
   ========================================================= */
int main() {
    vector<int> nums = {1, 2, 3, 3};
    int K = 6;

    cout << "Top-down: " << countSubsetsWithSumK_topdown(nums, K) << endl;
    cout << "Tabulation: " << countSubsetsWithSumK_tab(nums, K) << endl;
    cout << "Space-opt: " << countSubsetsWithSumK_spaceOpt(nums, K) << endl;

    // More tests
    vector<vector<int>> tests = {
        {1, 1, 1, 1},    // K=2 -> 6
        {2, 3, 5, 6, 8, 10}, // K=10 -> 3
        {1, 2, 3},       // K=3 -> 2
        {3, 3, 3, 3},    // K=6 -> 6
        {0, 0, 1},       // K=1 -> 4 (zeros double count)
    };
    vector<int> Ks = {2, 10, 3, 6, 1};

    for (int t = 0; t < tests.size(); t++) {
        cout << "\nArray: ";
        for (int x : tests[t]) cout << x << " ";
        cout << "\nK = " << Ks[t] << "\n";
        cout << "Count: " << countSubsetsWithSumK_spaceOpt(tests[t], Ks[t]) << "\n";
    }

    return 0;
}
