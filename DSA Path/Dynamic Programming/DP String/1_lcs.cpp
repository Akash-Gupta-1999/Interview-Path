#include <bits/stdc++.h>
using namespace std;

/* =========================================================
   LONGEST COMMON SUBSEQUENCE — ALL IN ONE
   =========================================================
   Given two strings, find the length of the longest
   common subsequence between them.
   ========================================================= */

/* ---------------------------------------------------------
   1️⃣ Top-down recursion + memoization
   --------------------------------------------------------- */
int topdown(int n1, int n2, string &s1, string &s2, vector<vector<int>>& dp) {
    // Base case: if any string becomes empty
    if (n1 < 0 || n2 < 0)
        return 0;

    if (dp[n1][n2] != -1)
        return dp[n1][n2];

    // If last characters match, include + move both pointers
    if (s1[n1] == s2[n2])
        return dp[n1][n2] = 1 + topdown(n1 - 1, n2 - 1, s1, s2, dp);

    // Else, try excluding from either string
    int left = topdown(n1 - 1, n2, s1, s2, dp);
    int right = topdown(n1, n2 - 1, s1, s2, dp);

    return dp[n1][n2] = max(left, right);
}

int longestCommonSubsequence_topdown(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return topdown(n1 - 1, n2 - 1, s1, s2, dp);
}

/* ---------------------------------------------------------
   2️⃣ Bottom-up Tabulation
   --------------------------------------------------------- */
int longestCommonSubsequence_tab(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n1][n2];
}

/* ---------------------------------------------------------
   3️⃣ Space Optimization (2 Rows)
   --------------------------------------------------------- */
int longestCommonSubsequence_spaceOpt(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    vector<int> prev(n2 + 1, 0), curr(n2 + 1, 0);

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }

    return prev[n2];
}

/* =========================================================
   TEST CASES
   ========================================================= */
int main() {
    vector<pair<string, string>> tests = {
        {"abcde", "ace"},       // Expected: 3
        {"abc", "abc"},         // Expected: 3
        {"abc", "def"},         // Expected: 0
        {"bl", "yby"},          // Expected: 1
        {"aggtab", "gxtxayb"}   // Expected: 4
    };

    for (auto &tc : tests) {
        string s1 = tc.first, s2 = tc.second;
        cout << "s1 = " << s1 << ", s2 = " << s2 << endl;
        cout << "Top-down: " << longestCommonSubsequence_topdown(s1, s2) << endl;
        cout << "Tabulation: " << longestCommonSubsequence_tab(s1, s2) << endl;
        cout << "Space Opt: " << longestCommonSubsequence_spaceOpt(s1, s2) << endl;
        cout << "--------------------------------------\n";
    }

    return 0;
}
