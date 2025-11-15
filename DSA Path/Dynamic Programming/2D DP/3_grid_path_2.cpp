#include <bits/stdc++.h>
using namespace std;

// ===============================================
// Problem: Unique Paths II (Grid with Obstacles)
// ===============================================
// Given an m x n grid where some cells are blocked (1 = obstacle),
// count how many unique paths exist from top-left (0,0)
// to bottom-right (m-1, n-1), moving only right or down.
// ===============================================


// ------------------------------------------------
// 1️⃣ Top-Down (Recursion + Memoization)
// ------------------------------------------------
int topdownHelper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if (i < 0 || j < 0 || grid[i][j] == 1) return 0;  // out of bounds or obstacle
    if (i == 0 && j == 0) return 1;                   // start point
    if (dp[i][j] != -1) return dp[i][j];

    int up = topdownHelper(i - 1, j, grid, dp);
    int left = topdownHelper(i, j - 1, grid, dp);
    return dp[i][j] = up + left;
}

int uniquePathsWithObstacles_topdown(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return topdownHelper(m - 1, n - 1, obstacleGrid, dp);
}


// ------------------------------------------------
// 2️⃣ Bottom-Up (Tabulation)
// ------------------------------------------------
int uniquePathsWithObstacles_bottomup(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    if (grid[0][0] == 1) return 0;  // start blocked
    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                dp[i][j] = 0; // obstacle
                continue;
            }
            if (i == 0 && j == 0) continue;
            int up = (i > 0) ? dp[i - 1][j] : 0;
            int left = (j > 0) ? dp[i][j - 1] : 0;
            dp[i][j] = up + left;
        }
    }
    return dp[m - 1][n - 1];
}


// ------------------------------------------------
// 3️⃣ Space Optimized (1D DP)
// ------------------------------------------------
int uniquePathsWithObstacles_spaceOptimized(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++) {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                curr[j] = 0; // obstacle
                continue;
            }

            if (i == 0 && j == 0) {
                curr[j] = 1; // start
            } else {
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
    vector<vector<vector<int>>> testCases = {
        {{0,0,0},{0,1,0},{0,0,0}},        // Expected: 2
        {{0,1},{0,0}},                    // Expected: 1
        {{1,0}},                          // Expected: 0
        {{0,0,0,0}},                      // Expected: 1
        {{0,1,0},{0,1,0},{0,0,0}}         // Expected: 1
    };

    cout << "==============================================\n";
    cout << "         UNIQUE PATHS II (WITH OBSTACLES)      \n";
    cout << "==============================================\n";

    for (int t = 0; t < testCases.size(); t++) {
        auto grid = testCases[t];
        cout << "\nTest Case " << t + 1 << ":\n";
        for (auto& row : grid) {
            for (int val : row) cout << val << " ";
            cout << "\n";
        }

        cout << "----------------------------------------------\n";
        cout << "Top-Down (Memo): " << uniquePathsWithObstacles_topdown(grid) << "\n";
        cout << "Bottom-Up (Tab): " << uniquePathsWithObstacles_bottomup(grid) << "\n";
        cout << "Space Optimized: " << uniquePathsWithObstacles_spaceOptimized(grid) << "\n";
    }

    cout << "\n==============================================\n";
    cout << "Complexities:\n";
    cout << "Top-Down:     O(m*n) Time | O(m*n) Space (Rec + DP)\n";
    cout << "Bottom-Up:    O(m*n) Time | O(m*n) Space\n";
    cout << "Space-Opt:    O(m*n) Time | O(n) Space\n";
    cout << "==============================================\n";

    return 0;
}
