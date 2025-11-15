#include <bits/stdc++.h>
using namespace std;

// =====================================================
// Problem: Frog Jump with K Distance
// =====================================================
// You can jump from index i to i+1, i+2, ..., i+k
// Cost = |heights[i] - heights[j]|
// Goal: Minimum total cost to reach the last stone
// =====================================================

// -----------------------------------------------------
// Method 1: Top-Down (Recursion + Memoization)
// Time Complexity: O(n * k)
// Space Complexity: O(n) + O(n) recursion stack
// -----------------------------------------------------
int frogJumpKTopDownHelper(int idx, vector<int>& heights, int k, vector<int>& dp) {
    if (idx == 0) return 0;
    if (dp[idx] != -1) return dp[idx];

    int minCost = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (idx - j >= 0) {
            int jump = frogJumpKTopDownHelper(idx - j, heights, k, dp) + abs(heights[idx] - heights[idx - j]);
            minCost = min(minCost, jump);
        }
    }
    return dp[idx] = minCost;
}

int frogJumpKTopDown(vector<int>& heights, int k) {
    int n = heights.size();
    vector<int> dp(n, -1);
    return frogJumpKTopDownHelper(n - 1, heights, k, dp);
}

// -----------------------------------------------------
// Method 2: Bottom-Up (DP Array)
// Time Complexity: O(n * k)
// Space Complexity: O(n)
// -----------------------------------------------------
int frogJumpKBottomUp(vector<int>& heights, int k) {
    int n = heights.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0)
                dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
        }
    }
    return dp[n - 1];
}

// -----------------------------------------------------
// Main Function with Multiple Test Cases
// -----------------------------------------------------
int main() {
    struct TestCase {
        vector<int> heights;
        int k;
    };

    vector<TestCase> testCases = {
        {{10, 30, 40, 20}, 2},
        {{10, 30, 40, 50, 20}, 3},
        {{10, 20, 10}, 1},
        {{10, 100, 30, 10}, 2},
        {{10, 20, 30, 10, 40, 20}, 4}
    };

    cout << "=====================================================\n";
    cout << "              FROG JUMP WITH K DISTANCE              \n";
    cout << "=====================================================\n";

    for (int t = 0; t < testCases.size(); t++) {
        cout << "\nTest Case " << t + 1 << ":\n";
        cout << "Heights: ";
        for (int h : testCases[t].heights) cout << h << " ";
        cout << "\nK = " << testCases[t].k << "\n---------------------------------------------\n";

        cout << "Top-Down (Memoized Recursion): " 
             << frogJumpKTopDown(testCases[t].heights, testCases[t].k) << "\n";
        cout << "Bottom-Up (DP Array):          " 
             << frogJumpKBottomUp(testCases[t].heights, testCases[t].k) << "\n";
    }

    cout << "\n=====================================================\n";
    cout << "Complexities Summary:\n";
    cout << "-----------------------------------------------------\n";
    cout << "Top-Down:     O(n*k) Time | O(n) Space (stack + dp)\n";
    cout << "Bottom-Up:    O(n*k) Time | O(n) Space\n";
    cout << "=====================================================\n";

    return 0;
}
