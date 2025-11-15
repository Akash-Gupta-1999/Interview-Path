#include <bits/stdc++.h>
using namespace std;

// =====================================================
// Problem: Frog Jump
// =====================================================
// You can jump either 1 or 2 stones ahead.
// The cost to jump from i to j is |heights[i] - heights[j]|
// Goal: Find minimum total energy to reach stone n-1
// =====================================================

// -----------------------------------------------------
// Method 1: Top-Down (Recursion + Memoization)
// Time Complexity: O(n)
// Space Complexity: O(n) + O(n) recursion stack
// -----------------------------------------------------
int frogJumpTopDownHelper(int idx, vector<int>& heights, vector<int>& dp) {
    if (idx == 0) return 0;
    if (dp[idx] != -1) return dp[idx];

    int oneStep = frogJumpTopDownHelper(idx - 1, heights, dp) + abs(heights[idx] - heights[idx - 1]);
    int twoStep = INT_MAX;
    if (idx > 1)
        twoStep = frogJumpTopDownHelper(idx - 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);

    return dp[idx] = min(oneStep, twoStep);
}

int frogJumpTopDown(vector<int>& heights) {
    int n = heights.size();
    vector<int> dp(n, -1);
    return frogJumpTopDownHelper(n - 1, heights, dp);
}

// -----------------------------------------------------
// Method 2: Bottom-Up (DP Array)
// Time Complexity: O(n)
// Space Complexity: O(n)
// -----------------------------------------------------
int frogJumpBottomUp(vector<int>& heights) {
    int n = heights.size();
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        int oneStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int twoStep = INT_MAX;
        if (i > 1)
            twoStep = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(oneStep, twoStep);
    }
    return dp[n - 1];
}

// -----------------------------------------------------
// Method 3: Bottom-Up (Space Optimized)
// Time Complexity: O(n)
// Space Complexity: O(1)
// -----------------------------------------------------
int frogJumpSpaceOptimized(vector<int>& heights) {
    int n = heights.size();
    if (n == 1) return 0;

    int prev2 = 0, prev = abs(heights[1] - heights[0]);

    for (int i = 2; i < n; i++) {
        int oneStep = prev + abs(heights[i] - heights[i - 1]);
        int twoStep = prev2 + abs(heights[i] - heights[i - 2]);
        int curr = min(oneStep, twoStep);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}

// -----------------------------------------------------
// Main Function with Multiple Test Cases
// -----------------------------------------------------
int main() {
    vector<vector<int>> testCases = {
        {10, 20, 30, 10},         // Example 1
        {10, 50, 10},             // Example 2
        {30, 10, 60, 10, 60, 50}, // Example 3
        {10},                     // Single stone
        {10, 20}                  // Two stones
    };

    cout << "=============================================\n";
    cout << "            FROG JUMP COMPARISON             \n";
    cout << "=============================================\n";

    for (int t = 0; t < testCases.size(); t++) {
        cout << "\nTest Case " << t + 1 << ":\n";
        cout << "Heights: ";
        for (int h : testCases[t]) cout << h << " ";
        cout << "\n---------------------------------------------\n";

        cout << "Top-Down (Memoized Recursion): " << frogJumpTopDown(testCases[t]) << "\n";
        cout << "Bottom-Up (DP Array):          " << frogJumpBottomUp(testCases[t]) << "\n";
        cout << "Space Optimized (2 vars):      " << frogJumpSpaceOptimized(testCases[t]) << "\n";
    }

    cout << "\n=============================================\n";
    cout << "Complexities Summary:\n";
    cout << "---------------------------------------------\n";
    cout << "Top-Down:     O(n) Time | O(n) Space (stack + dp)\n";
    cout << "Bottom-Up:    O(n) Time | O(n) Space\n";
    cout << "Optimized:    O(n) Time | O(1) Space\n";
    cout << "=============================================\n";

    return 0;
}
