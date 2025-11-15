#include <bits/stdc++.h>
using namespace std;

/*
Problem: Count Square Submatrices with All Ones
------------------------------------------------
Given a binary matrix, count all square submatrices that have all 1s.
Each dp[i][j] represents the side length of the largest square ending at (i,j).
*/

int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize first row and column
    for (int i = 0; i < m; i++)
        dp[i][0] = matrix[i][0];
    for (int j = 0; j < n; j++)
        dp[0][j] = matrix[0][j];

    // Fill DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 1)
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }

    // Sum all dp[i][j] for total count
    int ans = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            ans += dp[i][j];

    return ans;
}

/* -------------------------------------------------------------------------- */
/*                                   MAIN                                    */
/* -------------------------------------------------------------------------- */

int main() {
    vector<vector<vector<int>>> testCases = {
        {{0,1,1,1},{1,1,1,1},{0,1,1,1}},   // expected = 15
        {{1,0,1},{1,1,0},{1,1,0}},         // expected = 7
        {{1,1,1},{1,1,1},{1,1,1}},         // expected = 14
        {{0,0,0}},                         // expected = 0
    };

    for (auto& mat : testCases) {
        cout << countSquares(mat) << "\n";
    }

    return 0;
}
