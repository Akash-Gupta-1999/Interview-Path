#include <bits/stdc++.h>
using namespace std;

/*
    🧠 Problem: Longest Increasing Subsequence (LIS)

    State representation:
        idx       → current index in array
        prev_idx  → index of previous element taken in subsequence (-1 means none)

    Transition:
        1️⃣ Skip current element → length = LIS(idx+1, prev_idx)
        2️⃣ Take current element (if valid) → 1 + LIS(idx+1, idx)
*/


// ------------------ TOP-DOWN (Memoization) ------------------

int topdown(int idx, int prev_idx, vector<int>& nums, int n, vector<vector<int>>& dp) {
    if (idx == n) return 0;

    if (dp[idx][prev_idx + 1] != -1)
        return dp[idx][prev_idx + 1];

    // Option 1: Skip current
    int length = topdown(idx + 1, prev_idx, nums, n, dp);

    // Option 2: Take current (if increasing)
    if (prev_idx == -1 || nums[idx] > nums[prev_idx])
        length = max(length, 1 + topdown(idx + 1, idx, nums, n, dp));

    return dp[idx][prev_idx + 1] = length;
}

int lengthOfLISMemo(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return topdown(0, -1, nums, n, dp);
}

/*
    ⏱️ Time:  O(N²)
    🧠 Space: O(N² + recursion)
*/


// ------------------ BOTTOM-UP (Tabulation) ------------------

int lengthOfLISTab(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int prev = idx - 1; prev >= -1; prev--) {
            int notTake = dp[idx + 1][prev + 1];
            int take = 0;
            if (prev == -1 || nums[idx] > nums[prev])
                take = 1 + dp[idx + 1][idx + 1];
            dp[idx][prev + 1] = max(take, notTake);
        }
    }
    return dp[0][0];
}

/*
    ⏱️ Time:  O(N²)
    🧠 Space: O(N²)
*/


// ------------------ SPACE-OPTIMIZED ------------------

int lengthOfLISSpaceOpt(vector<int>& nums) {
    int n = nums.size();
    vector<int> next(n + 1, 0), cur(n + 1, 0);

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int prev = idx - 1; prev >= -1; prev--) {
            int notTake = next[prev + 1];
            int take = 0;
            if (prev == -1 || nums[idx] > nums[prev])
                take = 1 + next[idx + 1];
            cur[prev + 1] = max(take, notTake);
        }
        next = cur;
    }
    return cur[0];
}

/*
    ⏱️ Time:  O(N²)
    🧠 Space: O(N)
*/


// ------------------ OPTIMAL (Binary Search Method) ------------------
// (Patience Sorting concept)

int lengthOfLISOptimal(vector<int>& nums) {
    vector<int> lis;
    for (int num : nums) {
        auto it = lower_bound(lis.begin(), lis.end(), num);
        if (it == lis.end()) lis.push_back(num);
        else *it = num;
    }
    return lis.size();
}

/*
    ⏱️ Time:  O(N log N)
    🧠 Space: O(N)
*/


// ------------------ MAIN DRIVER ------------------

int main() {
    vector<vector<int>> testCases = {
        {10,9,2,5,3,7,101,18},   // Expected: 4
        {0,1,0,3,2,3},           // Expected: 4
        {7,7,7,7,7,7},           // Expected: 1
        {1,2,4,3},               // Expected: 3
        {3,10,2,1,20}            // Expected: 3
    };

    for (auto nums : testCases) {
        cout << "Array: ";
        for (int x : nums) cout << x << " ";
        cout << "\n";

        cout << "Memoization:  " << lengthOfLISMemo(nums) << "\n";
        cout << "Tabulation:   " << lengthOfLISTab(nums) << "\n";
        cout << "Space Opt:    " << lengthOfLISSpaceOpt(nums) << "\n";
        cout << "BinarySearch: " << lengthOfLISOptimal(nums) << "\n";
        cout << "------------------------------------\n";
    }

    return 0;
}
