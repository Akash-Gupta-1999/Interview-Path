#include <bits/stdc++.h>
using namespace std;

/* =========================================================
   LONGEST PALINDROMIC SUBSEQUENCE
   =========================================================
   Idea:
   - LPS(s) = LCS(s, reverse(s))
   - Because a palindrome reads the same forwards and backwards
   ========================================================= */


/* -----------------------------
   1️⃣ TOP-DOWN (Memoization)
   ----------------------------- */
int topdownHelper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if (i < 0 || j < 0) return 0; // base case
    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j])
        dp[i][j] = 1 + topdownHelper(i - 1, j - 1, s1, s2, dp);
    else
        dp[i][j] = max(topdownHelper(i - 1, j, s1, s2, dp),
                       topdownHelper(i, j - 1, s1, s2, dp));

    return dp[i][j];
}

int longestPalindromeSubseq_topdown(string s) {
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return topdownHelper(n - 1, n - 1, s, s2, dp);
}


/* -----------------------------
   2️⃣ BOTTOM-UP (Tabulation) + Reconstruction
   ----------------------------- */
pair<int, string> longestPalindromeSubseq_tab(string s) {
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

    // Reconstruction of the subsequence
    int i = n, j = n;
    string lps = "";
    while (i > 0 && j > 0) {
        if (s[i - 1] == s2[j - 1]) {
            lps += s[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(lps.begin(), lps.end());
    return {dp[n][n], lps};
}


/* -----------------------------
   3️⃣ SPACE OPTIMIZED VERSION
   ----------------------------- */
int longestPalindromeSubseq_spaceOpt(string s) {
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

    return prev[n];
}


/* -----------------------------
   MAIN — TEST CASES
   ----------------------------- */
int main() {
    vector<string> tests = {
        "bbbab",
        "cbbd",
        "agbcba",
        "a",
        "abcde",
        "aaa"
    };

    for (string s : tests) {
        cout << "String: " << s << endl;
        cout << "Top-Down Length: " << longestPalindromeSubseq_topdown(s) << endl;

        auto [len, seq] = longestPalindromeSubseq_tab(s);
        cout << "Tabulation Length: " << len << ", LPS = \"" << seq << "\"" << endl;

        cout << "Space-Optimized Length: " << longestPalindromeSubseq_spaceOpt(s) << endl;
        cout << "--------------------------------------------------\n";
    }

    return 0;
}
