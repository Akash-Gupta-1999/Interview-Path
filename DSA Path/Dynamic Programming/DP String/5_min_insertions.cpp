#include <bits/stdc++.h>
using namespace std;

/* =========================================================
   MINIMUM INSERTIONS TO MAKE STRING PALINDROME
   =========================================================
   Concept:
   - Minimum insertions = n - Longest Palindromic Subsequence
   - LPS(s) = LCS(s, reverse(s))
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

int minInsertions_topdown(string s) {
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int lps = topdownHelper(n - 1, n - 1, s, s2, dp);
    return n - lps;
}


/* -----------------------------
   2️⃣ BOTTOM-UP (Tabulation)
   ----------------------------- */
int minInsertions_tab(string s) {
    int n = s.size();
    string s2 = s;
    reverse(s2.begin(), s2.end());

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int lps = dp[n][n];
    return n - lps;
}


/* -----------------------------
   3️⃣ SPACE OPTIMIZED VERSION
   ----------------------------- */
int minInsertions_spaceOpt(string s) {
    int n = s.size();
    string s2 = s;
    reverse(s2.begin(), s2.end());

    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == s2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }

    int lps = prev[n];
    return n - lps;
}


/* -----------------------------
   MAIN — TEST CASES
   ----------------------------- */
int main() {
    vector<string> tests = {
        "mbadm",     // -> 2 ("mbabm")
        "leetcode",  // -> 5
        "a",         // -> 0
        "abcda",     // -> 2 ("adcda" or "abcdcba")
        "aa",        // -> 0
        "abcd"       // -> 3
    };

    for (string s : tests) {
        cout << "String: " << s << endl;
        cout << "Top-Down: " << minInsertions_topdown(s) << endl;
        cout << "Tabulation: " << minInsertions_tab(s) << endl;
        cout << "Space-Optimized: " << minInsertions_spaceOpt(s) << endl;
        cout << "--------------------------------------------------\n";
    }

    return 0;
}
