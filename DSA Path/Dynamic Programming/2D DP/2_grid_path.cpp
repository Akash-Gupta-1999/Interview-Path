#include <bits/stdc++.h>
using namespace std;

// ===============================================
// Problem: Unique Paths in Grid (m x n)
// ===============================================
// You are located at the top-left corner of a grid (0,0)
// and want to reach the bottom-right corner (m-1, n-1).
// You can only move either down or right at any point.
// ===============================================


// ------------------------------------------------
// 1️⃣ Top-Down (Recursion + Memoization)
// ------------------------------------------------
int topdownHelper(int i, int j, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int up = topdownHelper(i - 1, j, dp);
    int left = topdownHelper(i, j - 1, dp);
    return dp[i][j] = up + left;
}

int uniquePaths_topdown(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return topdownHelper(m - 1, n - 1, dp);
}


// ------------------------------------------------
// 2️⃣ Bottom-Up (Tabulation)
// ------------------------------------------------
int uniquePaths_bottomup(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            int up = (i > 0) ? dp[i - 1][j] : 0;
            int left = (j > 0) ? dp[i][j - 1] : 0;
            dp[i][j] = up + left;
        }
    }
    return dp[m - 1][n - 1];
}


// ------------------------------------------------
// 3️⃣ Space Optimized (1D Array)
// ------------------------------------------------
int uniquePaths_spaceOptimized(int m, int n) {
    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++) {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) curr[j] = 1;
            else {
                int up = (i > 0) ? prev[j] : 0;
                int left = (j > 0) ? curr[j - 1] : 0;
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}


// ===============================================
// Main Function with Multiple Test Cases
// ===============================================
int main() {
    vector<pair<int, int>> testCases = {
        {3, 7},
        {3, 2},
        {7, 3},
        {3, 3},
        {1, 5}
    };

    cout << "==============================================\n";
    cout << "             UNIQUE PATHS TESTS                \n";
    cout << "==============================================\n";

    for (int t = 0; t < testCases.size(); t++) {
        int m = testCases[t].first;
        int n = testCases[t].second;

        cout << "\nTest Case " << t + 1 << ": Grid (" << m << "x" << n << ")\n";
        cout << "----------------------------------------------\n";

        cout << "Top-Down (Memo): " << uniquePaths_topdown(m, n) << "\n";
        cout << "Bottom-Up (Tab): " << uniquePaths_bottomup(m, n) << "\n";
        cout << "Space Optimized: " << uniquePaths_spaceOptimized(m, n) << "\n";
    }

    cout << "\n==============================================\n";
    cout << "Complexities:\n";
    cout << "Top-Down:     O(m*n) Time | O(m*n) Space (Rec + DP)\n";
    cout << "Bottom-Up:    O(m*n) Time | O(m*n) Space\n";
    cout << "Space-Opt:    O(m*n) Time | O(n) Space\n";
    cout << "==============================================\n";

    return 0;
}
