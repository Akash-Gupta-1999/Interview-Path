#include <bits/stdc++.h>
using namespace std;

// =====================================================
// Problem: Climbing Stairs
// You can climb either 1 or 2 steps at a time.
// Find the number of distinct ways to reach the top.
// =====================================================

// -----------------------------------------------------
// Method 1: Top-Down (Recursion + Memoization)
// Time Complexity: O(n)
// Space Complexity: O(n) (recursion stack + dp array)
// -----------------------------------------------------
int climbStairsTopDownHelper(int n, vector<int>& dp) {
    if (n <= 2) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = climbStairsTopDownHelper(n - 1, dp) + climbStairsTopDownHelper(n - 2, dp);
}

int climbStairsTopDown(int n) {
    vector<int> dp(n + 1, -1);
    return climbStairsTopDownHelper(n, dp);
}

// -----------------------------------------------------
// Method 2: Bottom-Up (DP Array)
// Time Complexity: O(n)
// Space Complexity: O(n)
// -----------------------------------------------------
int climbStairsBottomUp(int n) {
    if (n <= 2) return n;
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// -----------------------------------------------------
// Method 3: Bottom-Up (Space Optimized)  ✅ (Your version)
// Time Complexity: O(n)
// Space Complexity: O(1)
// -----------------------------------------------------
int climbStairsSpaceOptimized(int n) {
    if (n < 3) return n;
    int prev2 = 1, prev = 2, curr = 0;
    for (int i = 3; i <= n; i++) {
        curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }
    return curr;
}

// -----------------------------------------------------
// Main Function with Multiple Test Cases
// -----------------------------------------------------
int main() {
    vector<int> testCases = {1, 2, 3, 4, 5, 10, 20};

    cout << "=============================================\n";
    cout << "         CLIMBING STAIRS - COMPARISON        \n";
    cout << "=============================================\n";

    for (int n : testCases) {
        cout << "\nNumber of steps: " << n << "\n";
        cout << "---------------------------------------------\n";

        cout << "Top-Down (Memoized Recursion): " << climbStairsTopDown(n) << "\n";
        cout << "Bottom-Up (DP Array):          " << climbStairsBottomUp(n) << "\n";
        cout << "Space Optimized (2 vars):      " << climbStairsSpaceOptimized(n) << "\n";
    }

    cout << "\n=============================================\n";
    cout << "Complexities Summary:\n";
    cout << "---------------------------------------------\n";
    cout << "Top-Down:     O(n) Time | O(n) Space\n";
    cout << "Bottom-Up:    O(n) Time | O(n) Space\n";
    cout << "Optimized:    O(n) Time | O(1) Space\n";
    cout << "=============================================\n";

    return 0;
}
