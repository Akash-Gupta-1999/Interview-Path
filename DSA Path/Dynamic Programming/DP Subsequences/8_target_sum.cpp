#include <bits/stdc++.h>
using namespace std;

/*
    LEETCODE 494 — TARGET SUM
    -------------------------------------
    We must assign '+' or '-' before each number so that the final sum = target.

    Key idea:
    Let total = sum(nums)
    Let S1 = sum of positives, S2 = sum of negatives

    S1 - S2 = target
    S1 + S2 = total
    => 2*S1 = total + target
    => S1 = (total + target) / 2

    So, problem reduces to:
    → Count subsets with sum = (total - target) / 2   (or (total + target)/2 if you prefer)
    But we need to ensure total >= target and (total - target) is even.
*/

/* ============================================================
   1️⃣ TOP-DOWN RECURSION + MEMOIZATION
   ============================================================ */
int topdownHelper(int idx, int sum, vector<int>& nums, vector<vector<int>>& dp) {
    // Base case (only one element left)
    if (idx == 0) {
        // If first element is zero and sum == 0 → two possibilities: take or not take
        if (sum == 0 && nums[0] == 0) return 2;

        // If we can make sum using nums[0] OR by skipping it
        if (sum == 0 || sum == nums[0]) return 1;

        // Otherwise no valid subset
        return 0;
    }

    if (dp[idx][sum] != -1) return dp[idx][sum];

    int notTake = topdownHelper(idx - 1, sum, nums, dp);

    int take = 0;
    if (nums[idx] <= sum)
        take = topdownHelper(idx - 1, sum - nums[idx], nums, dp);

    return dp[idx][sum] = take + notTake;
}

int findTargetSumWays_topdown(vector<int>& nums, int target) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();

    if (abs(target) > total || (total - target) % 2 != 0)
        return 0;

    int sum = (total - target) / 2;
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    return topdownHelper(n - 1, sum, nums, dp);
}

/* ============================================================
   2️⃣ BOTTOM-UP TABULATION
   ============================================================ */
int findTargetSumWays_tab(vector<int>& nums, int target) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();

    if (abs(target) > total || (total - target) % 2 != 0)
        return 0;

    int sum = (total - target) / 2;
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    // Base case initialization
    if (nums[0] == 0)
        dp[0][0] = 2; // can either take or not take 0
    else
        dp[0][0] = 1; // only not take

    if (nums[0] != 0 && nums[0] <= sum)
        dp[0][nums[0]] = 1; // one way to take first element

    // Build DP table
    for (int i = 1; i < n; i++) {
        for (int targetSum = 0; targetSum <= sum; targetSum++) {
            int notTake = dp[i - 1][targetSum];
            int take = 0;
            if (nums[i] <= targetSum)
                take = dp[i - 1][targetSum - nums[i]];
            dp[i][targetSum] = take + notTake;
        }
    }

    return dp[n - 1][sum];
}

/* ============================================================
   3️⃣ SPACE OPTIMIZED DP
   ============================================================ */
int findTargetSumWays_spaceOpt(vector<int>& nums, int target) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();

    if (abs(target) > total || (total - target) % 2 != 0)
        return 0;

    int sum = (total - target) / 2;

    vector<int> prev(sum + 1, 0);

    // Base initialization
    if (nums[0] == 0)
        prev[0] = 2; // +0 or -0
    else
        prev[0] = 1;

    if (nums[0] != 0 && nums[0] <= sum)
        prev[nums[0]] = 1;

    // DP iteration
    for (int i = 1; i < n; i++) {
        vector<int> curr(sum + 1, 0);
        for (int targetSum = 0; targetSum <= sum; targetSum++) {
            int notTake = prev[targetSum];
            int take = 0;
            if (nums[i] <= targetSum)
                take = prev[targetSum - nums[i]];
            curr[targetSum] = take + notTake;
        }
        prev = curr;
    }

    return prev[sum];
}

/* ============================================================
   MAIN + TESTS
   ============================================================ */
int main() {
    vector<vector<int>> tests = {
        {1,1,1,1,1},     // expected 5
        {1},             // expected 1
        {0,0,0,0,0,0,0,0,1}, // expected 256
        {100},           // expected 0 if target = -200
    };
    vector<int> targets = {3, 1, 1, -200};

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test " << i + 1 << ": target = " << targets[i] << "\n";
        cout << "Top-down: " << findTargetSumWays_topdown(tests[i], targets[i]) << "\n";
        cout << "Tabulation: " << findTargetSumWays_tab(tests[i], targets[i]) << "\n";
        cout << "Space optimized: " << findTargetSumWays_spaceOpt(tests[i], targets[i]) << "\n\n";
    }
    return 0;
}
