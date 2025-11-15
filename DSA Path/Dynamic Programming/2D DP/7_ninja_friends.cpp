#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Problem: Ninja and His Friends
// ============================================================
// Two ninjas start from the top row:
//   - Ninja 1 starts at (0, 0)
//   - Ninja 2 starts at (0, m-1)
// Both move to the next row simultaneously. 
// From (i, j), each can move to (i+1, j-1), (i+1, j), or (i+1, j+1).
// If both land on the same cell, chocolates are counted once.
//
// Return the maximum chocolates both ninjas can collect.
// ============================================================


// ===================== TOP-DOWN (Memoization) =====================
int topdown(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
    if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) return -1e9;
    if (i == n - 1) {
        if (j1 == j2) return grid[i][j1];
        return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int maxi = 0;
    for (int dj1 = -1; dj1 <= 1; dj1++) {
        for (int dj2 = -1; dj2 <= 1; dj2++) {
            int val = 0;
            if (j1 == j2)
                val = grid[i][j1];
            else
                val = grid[i][j1] + grid[i][j2];
            val += topdown(i + 1, j1 + dj1, j2 + dj2, n, m, grid, dp);
            maxi = max(maxi, val);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates_TopDown(int n, int m, vector<vector<int>>& grid) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return topdown(0, 0, m - 1, n, m, grid, dp);
}


// ===================== BOTTOM-UP (Tabulation) =====================
int maximumChocolates_Tabulation(int n, int m, vector<vector<int>>& grid) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    // Base case (last row)
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    // Build from bottom to top
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = 0;
                for (int dj1 = -1; dj1 <= 1; dj1++) {
                    for (int dj2 = -1; dj2 <= 1; dj2++) {
                        int val = 0;
                        if (j1 == j2)
                            val = grid[i][j1];
                        else
                            val = grid[i][j1] + grid[i][j2];
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            val += dp[i + 1][j1 + dj1][j2 + dj2];
                        else
                            val += -1e9;
                        maxi = max(maxi, val);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][m - 1];
}


// ===================== SPACE OPTIMIZED =====================
int maximumChocolates_SpaceOptimized(int n, int m, vector<vector<int>>& grid) {
    vector<vector<int>> front(m, vector<int>(m, 0)), cur(m, vector<int>(m, 0));

    // Base case
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                front[j1][j2] = grid[n - 1][j1];
            else
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    // Fill bottom-up
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = 0;
                for (int dj1 = -1; dj1 <= 1; dj1++) {
                    for (int dj2 = -1; dj2 <= 1; dj2++) {
                        int val = 0;
                        if (j1 == j2)
                            val = grid[i][j1];
                        else
                            val = grid[i][j1] + grid[i][j2];
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            val += front[j1 + dj1][j2 + dj2];
                        else
                            val += -1e9;
                        maxi = max(maxi, val);
                    }
                }
                cur[j1][j2] = maxi;
            }
        }
        front = cur;
    }

    return front[0][m - 1];
}


// ============================================================
// Main Function with Multiple Test Cases
// ============================================================
int main() {
    vector<tuple<int, int, vector<vector<int>>>> testCases;

    // ---------- Test Case 1 ----------
    testCases.push_back({
        3, 4,
        {
            {2, 3, 1, 2},
            {3, 4, 2, 2},
            {5, 6, 3, 5}
        }
    });

    // ---------- Test Case 2 ----------
    testCases.push_back({
        3, 3,
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        }
    });

    // ---------- Test Case 3 ----------
    testCases.push_back({
        4, 4,
        {
            {3, 1, 1, 2},
            {2, 5, 10, 1},
            {1, 5, 1, 1},
            {2, 1, 1, 1}
        }
    });

    cout << "============================================================\n";
    cout << "              NINJA AND HIS FRIENDS TESTS                   \n";
    cout << "============================================================\n";

    for (int t = 0; t < testCases.size(); t++) {
        int n, m;
        vector<vector<int>> grid;
        tie(n, m, grid) = testCases[t];

        cout << "\nTest Case " << t + 1 << ":\n";
        cout << "Grid (" << n << "x" << m << "):\n";
        for (auto &row : grid) {
            for (int val : row) cout << val << " ";
            cout << "\n";
        }

        cout << "--------------------------------------------\n";
        cout << "Top-Down (Memoization):      " << maximumChocolates_TopDown(n, m, grid) << "\n";
        cout << "Bottom-Up (Tabulation):      " << maximumChocolates_Tabulation(n, m, grid) << "\n";
        cout << "Space Optimized DP:          " << maximumChocolates_SpaceOptimized(n, m, grid) << "\n";
    }

    cout << "\n============================================================\n";
    cout << "Complexity:\n";
    cout << "  Top-Down  : O(N * M * M * 9)\n";
    cout << "  Bottom-Up : O(N * M * M * 9)\n";
    cout << "  Space Opt : O(M * M * 9)\n";
    cout << "============================================================\n";

    return 0;
}
