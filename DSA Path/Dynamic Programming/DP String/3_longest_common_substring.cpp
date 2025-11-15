#include <bits/stdc++.h>
using namespace std;

/* =========================================================
   LONGEST COMMON SUBSTRING — CLEAN VERSION
   =========================================================
   Given two strings s1 and s2, find:
   1. The length of the longest common substring
   2. The substring itself
   ========================================================= */

/* ---------------------------------------------------------
   TOP-DOWN (Memoization)
   dp[i][j] = length of longest common suffix of
   s1[0..i], s2[0..j]
   --------------------------------------------------------- */
int topdown(int i, int j, string &s1, string &s2, vector<vector<int>> &dp, int &maxLen) {
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j]) {
        dp[i][j] = 1 + topdown(i - 1, j - 1, s1, s2, dp, maxLen);
        maxLen = max(maxLen, dp[i][j]);
    } else
        dp[i][j] = 0;

    // Explore remaining cells to ensure full traversal
    topdown(i - 1, j, s1, s2, dp, maxLen);
    topdown(i, j - 1, s1, s2, dp, maxLen);

    return dp[i][j];
}

/* ---------------------------------------------------------
   BOTTOM-UP (Tabulation)
   --------------------------------------------------------- */
pair<int, string> bottomup(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    int maxLen = 0, endIdx = 0;

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIdx = i - 1;
                }
            } else
                dp[i][j] = 0;
        }
    }

    string ans = "";
    if (maxLen > 0)
        ans = s1.substr(endIdx - maxLen + 1, maxLen);

    return {maxLen, ans};
}

/* ---------------------------------------------------------
   SPACE OPTIMIZED (2 rows only)
   --------------------------------------------------------- */
pair<int, string> spaceOpt(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    vector<int> prev(n2 + 1, 0), cur(n2 + 1, 0);

    int maxLen = 0, endIdx = 0;

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                cur[j] = 1 + prev[j - 1];
                if (cur[j] > maxLen) {
                    maxLen = cur[j];
                    endIdx = i - 1;
                }
            } else
                cur[j] = 0;
        }
        prev = cur;
    }

    string ans = "";
    if (maxLen > 0)
        ans = s1.substr(endIdx - maxLen + 1, maxLen);

    return {maxLen, ans};
}

/* ---------------------------------------------------------
   MAIN FUNCTION — Multiple test cases
   --------------------------------------------------------- */
int main() {
    vector<pair<string, string>> tests = {
        {"abcde", "abfce"},
        {"abcdxyz", "xyzabcd"},
        {"zxabcdezy", "yzabcdezx"},
        {"abcdef", "ghijkl"},
        {"ababc", "babca"}
    };

    for (auto &tc : tests) {
        string s1 = tc.first, s2 = tc.second;
        cout << "s1 = " << s1 << ", s2 = " << s2 << endl;

        // TOP-DOWN
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        int maxLen = 0;
        topdown(s1.size() - 1, s2.size() - 1, s1, s2, dp, maxLen);
        cout << "Top-Down (Length only): " << maxLen << endl;

        // TABULATION
        auto [len1, sub1] = bottomup(s1, s2);
        cout << "Bottom-Up: Length = " << len1 << ", Substring = \"" << sub1 << "\"" << endl;

        // SPACE OPTIMIZED
        auto [len2, sub2] = spaceOpt(s1, s2);
        cout << "Space Optimized: Length = " << len2 << ", Substring = \"" << sub2 << "\"" << endl;

        cout << "------------------------------------------------------\n";
    }

    return 0;
}
