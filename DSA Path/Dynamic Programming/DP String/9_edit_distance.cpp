#include <bits/stdc++.h>
using namespace std;

// ---------------------- TOP-DOWN (Recursion + Memoization) ----------------------
// Function to compute edit distance recursively with memoization
int solveTopDown(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {
    // Base cases:
    if (i == 0) return j; // If word1 is empty, we need j insertions
    if (j == 0) return i; // If word2 is empty, we need i deletions

    if (dp[i][j] != -1) return dp[i][j];

    if (word1[i - 1] == word2[j - 1])
        // Characters match → no extra operation needed
        return dp[i][j] = solveTopDown(i - 1, j - 1, word1, word2, dp);
    else {
        // 3 possibilities: insert, delete, replace
        int insertOp = solveTopDown(i, j - 1, word1, word2, dp);
        int deleteOp = solveTopDown(i - 1, j, word1, word2, dp);
        int replaceOp = solveTopDown(i - 1, j - 1, word1, word2, dp);

        return dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
    }
}

int minDistance_TopDown(string word1, string word2) {
    int n1 = word1.size(), n2 = word2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
    return solveTopDown(n1, n2, word1, word2, dp);
}

// ---------------------- BOTTOM-UP (Tabulation) ----------------------
int minDistance_BottomUp(string word1, string word2) {
    int n1 = word1.size(), n2 = word2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    // Base initialization
    for (int i = 0; i <= n1; i++) dp[i][0] = i; // Need i deletions
    for (int j = 0; j <= n2; j++) dp[0][j] = j; // Need j insertions

    // Fill the DP table
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1]; // No operation needed
            else
                dp[i][j] = 1 + min({dp[i - 1][j],     // Delete
                                    dp[i][j - 1],     // Insert
                                    dp[i - 1][j - 1]  // Replace
                                   });
        }
    }

    return dp[n1][n2];
}

// ---------------------- SPACE-OPTIMIZED DP ----------------------
int minDistance_SpaceOpt(string word1, string word2) {
    int n1 = word1.size(), n2 = word2.size();
    vector<int> prev(n2 + 1), curr(n2 + 1);

    // Initialize base row (word1 is empty)
    for (int j = 0; j <= n2; j++)
        prev[j] = j;

    for (int i = 1; i <= n1; i++) {
        curr[0] = i; // Need i deletions to make word1[0..i-1] → ""
        for (int j = 1; j <= n2; j++) {
            if (word1[i - 1] == word2[j - 1])
                curr[j] = prev[j - 1];
            else
                curr[j] = 1 + min({prev[j],     // Delete
                                   curr[j - 1], // Insert
                                   prev[j - 1]  // Replace
                                  });
        }
        prev = curr;
    }
    return prev[n2];
}

// ---------------------- MAIN WITH MULTIPLE TEST CASES ----------------------
int main() {
    vector<pair<string, string>> testCases = {
        {"horse", "ros"},      // Expected: 3
        {"intention", "execution"}, // Expected: 5
        {"abc", "yabd"},       // Expected: 2
        {"", "abc"},           // Expected: 3
        {"abc", ""},           // Expected: 3
        {"kitten", "sitting"}  // Expected: 3
    };

    for (auto &tc : testCases) {
        string w1 = tc.first, w2 = tc.second;
        cout << "word1 = \"" << w1 << "\", word2 = \"" << w2 << "\"\n";
        cout << "Top-Down Result: " << minDistance_TopDown(w1, w2) << "\n";
        cout << "Bottom-Up Result: " << minDistance_BottomUp(w1, w2) << "\n";
        cout << "Space Optimized Result: " << minDistance_SpaceOpt(w1, w2) << "\n";
        cout << "-----------------------------------------\n";
    }

    return 0;
}
