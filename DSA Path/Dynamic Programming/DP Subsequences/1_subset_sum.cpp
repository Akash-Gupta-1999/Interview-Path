#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Problem: Subset Sum Equals to Target
// ============================================================
// Given an array of integers `arr` and a target integer `k`,
// determine if there exists a subset of `arr` that sums up to `k`.
//
// Return true if such a subset exists, otherwise false.
//
// Example:
// Input: arr = [1, 2, 3, 4], k = 5
// Output: true (because subset [2, 3] sums to 5)
// ============================================================


// ===================== TOP-DOWN (Memoization) =====================
bool subsetSum_TopDown_Helper(int n, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (n == 0) return arr[0] == target;

    if (dp[n][target] != -1) return dp[n][target];

    bool notTake = subsetSum_TopDown_Helper(n - 1, target, arr, dp);
    bool take = false;
    if (arr[n] <= target)
        take = subsetSum_TopDown_Helper(n - 1, target - arr[n], arr, dp);

    return dp[n][target] = take || notTake;
}

bool subsetSum_TopDown(int n, int k, vector<int>& arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return subsetSum_TopDown_Helper(n - 1, k, arr, dp);
}


// ===================== BOTTOM-UP (Tabulation) =====================
bool subsetSum_Tabulation(int n, int k, vector<int>& arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base case: sum = 0 is always possible
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    // Base case for first element
    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    // Build table
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (arr[i] <= j)
                take = dp[i - 1][j - arr[i]];
            dp[i][j] = take || notTake;
        }
    }

    return dp[n - 1][k];
}


// ===================== SPACE OPTIMIZED =====================
bool subsetSum_SpaceOptimized(int n, int k, vector<int>& arr) {
    vector<bool> prev(k + 1, false), curr(k + 1, false);

    prev[0] = curr[0] = true;
    if (arr[0] <= k) prev[arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            bool notTake = prev[j];
            bool take = false;
            if (arr[i] <= j)
                take = prev[j - arr[i]];
            curr[j] = take || notTake;
        }
        prev = curr;
    }

    return prev[k];
}


// ============================================================
// Main Function with Multiple Test Cases
// ============================================================
int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 3, 4}, 5},
        {{2, 3, 7, 8, 10}, 11},
        {{1, 1, 1, 1}, 3},
        {{5, 2, 1}, 4},
        {{3, 34, 4, 12, 5, 2}, 9}
    };

    cout << "============================================================\n";
    cout << "             SUBSET SUM EQUALS TO TARGET TESTS              \n";
    cout << "============================================================\n";

    for (int t = 0; t < testCases.size(); t++) {
        vector<int> arr = testCases[t].first;
        int k = testCases[t].second;
        int n = arr.size();

        cout << "\nTest Case " << t + 1 << ":\n";
        cout << "Array: ";
        for (int x : arr) cout << x << " ";
        cout << "\nTarget: " << k << "\n";

        cout << "--------------------------------------------\n";
        cout << "Top-Down (Memoization):      " << (subsetSum_TopDown(n, k, arr) ? "true" : "false") << "\n";
        cout << "Bottom-Up (Tabulation):      " << (subsetSum_Tabulation(n, k, arr) ? "true" : "false") << "\n";
        cout << "Space Optimized DP:          " << (subsetSum_SpaceOptimized(n, k, arr) ? "true" : "false") << "\n";
    }

    cout << "\n============================================================\n";
    cout << "Complexity:\n";
    cout << "  Top-Down  : O(N * K)\n";
    cout << "  Bottom-Up : O(N * K)\n";
    cout << "  Space Opt : O(K)\n";
    cout << "============================================================\n";

    return 0;
}
