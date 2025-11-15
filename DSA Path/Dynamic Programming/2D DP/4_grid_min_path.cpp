#include <bits/stdc++.h>
using namespace std;

// ===============================================
// Problem: Minimum Path Sum
// ===============================================
// Given an m x n grid filled with non-negative numbers,
// find a path from top-left (0,0) to bottom-right (m-1,n-1)
// which minimizes the sum of all numbers along its path.
// You can only move either down or right at any point.
// ===============================================


// ------------------------------------------------
// 1️⃣ Top-Down (Recursion + Memoization)
// ------------------------------------------------
int topdownHelper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if (i < 0 || j < 0) return INT_MAX;          // out of bounds
    if (i == 0 && j == 0) return grid[i][j];     // base cell
    if (dp[i][j] != -1) return dp[i][j];
    int up = topdownHelper(i - 1, j, grid, dp);
    int left = topdownHelper(i, j - 1, grid, dp);
    return dp[i][j] = grid[i][j] + min(up, left);
}

int minPathSum_topdown(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return topdownHelper(m - 1, n - 1, grid, dp);
}


// ------------------------------------------------
// 2️⃣ Bottom-Up (Tabulation)
// ------------------------------------------------
int minPathSum_bottomup(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            int up = (i > 0) ? dp[i - 1][j] : INT_MAX;
            int left = (j > 0) ? dp[i][j - 1] : INT_MAX;
            dp[i][j] = grid[i][j] + min(up, left);
        }
    }
    return dp[m - 1][n - 1];
}


// ------------------------------------------------
// 3️⃣ Space Optimized (1D DP)
// ------------------------------------------------
int minPathSum_spaceOptimized(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++) {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                curr[j] = grid[0][0];
                continue;
            }
            int up = (i > 0) ? prev[j] : INT_MAX;
            int left = (j > 0) ? curr[j - 1] : INT_MAX;
            curr[j] = grid[i][j] + min(up, left);
        }
        prev = curr;
    }
    return prev[n - 1];
}


// ===============================================
// Main Function with Multiple Test Cases
// ===============================================
int main() {
    vector<vector<vector<int>>> testCases = {
        {{1,3,1},{1,5,1},{4,2,1}},       // Expected: 7
        {{1,2,3},{4,5,6}},               // Expected: 12
        {{5,9,6},{11,5,2}},              // Expected: 21
        {{1,2},{1,1}},                   // Expected: 3
        {{10}}                           // Expected: 10
    };

    cout << "==============================================\n";
    cout << "              MINIMUM PATH SUM                 \n";
    cout << "==============================================\n";

    for (int t = 0; t < testCases.size(); t++) {
        auto grid = testCases[t];
        cout << "\nTest Case " << t + 1 << ":\n";
        for (auto& row : grid) {
            for (int val : row) cout << val << " ";
            cout << "\n";
        }

        cout << "----------------------------------------------\n";
        cout << "Top-Down (Memo): " << minPathSum_topdown(grid) << "\n";
        cout << "Bottom-Up (Tab): " << minPathSum_bottomup(grid) << "\n";
        cout << "Space Optimized: " << minPathSum_spaceOptimized(grid) << "\n";
    }

    cout << "\n==============================================\n";
    cout << "Complexities:\n";
    cout << "Top-Down:     O(m*n) Time | O(m*n) Space (Rec + DP)\n";
    cout << "Bottom-Up:    O(m*n) Time | O(m*n) Space\n";
    cout << "Space-Opt:    O(m*n) Time | O(n) Space\n";
    cout << "==============================================\n";

    return 0;
}
