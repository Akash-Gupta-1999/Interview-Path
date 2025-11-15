#include <bits/stdc++.h>
using namespace std;

/* =========================================================
   MINIMUM DELETIONS + INSERTIONS TO MAKE STRINGS EQUAL
   =========================================================
   Formula:
     Let LCS = length of Longest Common Subsequence
     -> Deletions = n1 - LCS
     -> Insertions = n2 - LCS
     -> Total = Deletions + Insertions
   ========================================================= */


/* -----------------------------
   1️⃣ TOP-DOWN (Memoization)
   ----------------------------- */
int topdownHelper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j])
        dp[i][j] = 1 + topdownHelper(i - 1, j - 1, s1, s2, dp);
    else
        dp[i][j] = max(topdownHelper(i - 1, j, s1, s2, dp),
                       topdownHelper(i, j - 1, s1, s2, dp));

    return dp[i][j];
}

int minDistance_topdown(string word1, string word2) {
    int n1 = word1.size(), n2 = word2.size();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    int lcs = topdownHelper(n1 - 1, n2 - 1, word1, word2, dp);
    return (n1 - lcs) + (n2 - lcs);
}


/* -----------------------------
   2️⃣ TABULATION (Bottom-Up)
   ----------------------------- */
int minDistance_tab(string word1, string word2) {
    int n1 = word1.size(), n2 = word2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int lcs = dp[n1][n2];
    return (n1 - lcs) + (n2 - lcs);
}


/* -----------------------------
   3️⃣ SPACE OPTIMIZED
   ----------------------------- */
int minDistance_spaceOpt(string word1, string word2) {
    int n1 = word1.size(), n2 = word2.size();
    vector<int> prev(n2 + 1, 0), curr(n2 + 1, 0);

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (word1[i - 1] == word2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }

    int lcs = prev[n2];
    return (n1 - lcs) + (n2 - lcs);
}


/* -----------------------------
   MAIN — MULTIPLE TEST CASES
   ----------------------------- */
int main() {
    vector<pair<string, string>> tests = {
        {"sea", "eat"},      // -> 2
        {"leetcode", "etco"},// -> 4
        {"abc", "def"},      // -> 6
        {"abc", "abc"},      // -> 0
        {"", "abc"},         // -> 3
        {"a", ""},           // -> 1
    };

    for (auto &p : tests) {
        cout << "word1: " << p.first << ", word2: " << p.second << endl;
        cout << "Top-Down: " << minDistance_topdown(p.first, p.second) << endl;
        cout << "Tabulation: " << minDistance_tab(p.first, p.second) << endl;
        cout << "Space-Optimized: " << minDistance_spaceOpt(p.first, p.second) << endl;
        cout << "--------------------------------------------------\n";
    }

    return 0;
}
