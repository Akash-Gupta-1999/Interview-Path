#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------
// 🧠 Intuition:
// '?' matches exactly one character
// '*' matches any sequence (including empty)
// Use DP to decide if s[0..i] matches p[0..j]
// --------------------------------------------------

// Utility: check if pattern up to pos (1-based) is all '*'
bool isAllStars(string &p, int pos) {
    for (int i = 0; i < pos; i++)
        if (p[i] != '*') return false;
    return true;
}

// ---------- TOP-DOWN (RECURSION + MEMOIZATION) ----------
bool solveTopDown(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
    // Base cases
    if (i < 0 && j < 0) return true;       // both exhausted
    if (j < 0 && i >= 0) return false;     // pattern finished, string left
    if (i < 0 && j >= 0) return isAllStars(p, j + 1); // string empty, pattern must be all '*'

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == p[j] || p[j] == '?')
        return dp[i][j] = solveTopDown(i - 1, j - 1, s, p, dp);
    else if (p[j] == '*')
        // '*' can match empty (move pattern) OR match current char (move string)
        return dp[i][j] = solveTopDown(i - 1, j, s, p, dp) || solveTopDown(i, j - 1, s, p, dp);
    else
        return dp[i][j] = false;
}

bool isMatch_TopDown(string s, string p) {
    int n1 = s.size(), n2 = p.size();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return solveTopDown(n1 - 1, n2 - 1, s, p, dp);
}

// ---------- BOTTOM-UP DP ----------
bool isMatch_BottomUp(string s, string p) {
    int n1 = s.size(), n2 = p.size();
    vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));

    dp[0][0] = true; // empty string and empty pattern match
    for (int j = 1; j <= n2; j++)
        dp[0][j] = isAllStars(p, j); // empty string: only works if all stars

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else
                dp[i][j] = false;
        }
    }
    return dp[n1][n2];
}

// ---------- SPACE-OPTIMIZED DP ----------
bool isMatch_SpaceOpt(string s, string p) {
    int n1 = s.size(), n2 = p.size();
    vector<bool> prev(n2 + 1, false), cur(n2 + 1, false);

    prev[0] = true;
    for (int j = 1; j <= n2; j++)
        prev[j] = isAllStars(p, j);

    for (int i = 1; i <= n1; i++) {
        cur[0] = false; // non-empty string can’t match empty pattern
        for (int j = 1; j <= n2; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                cur[j] = prev[j - 1];
            else if (p[j - 1] == '*')
                cur[j] = prev[j] || cur[j - 1];
            else
                cur[j] = false;
        }
        prev = cur;
    }

    return prev[n2];
}

// ---------- MAIN WITH MULTIPLE TEST CASES ----------
int main() {
    vector<pair<string, string>> testCases = {
        {"aa", "a"},            // false
        {"aa", "*"},            // true
        {"cb", "?a"},           // false
        {"adceb", "*a*b"},      // true
        {"acdcb", "a*c?b"},     // false
        {"", "*"},              // true
        {"", "?"},              // false
        {"abc", "abc*"},        // true
        {"abc", "a*"},          // true
        {"mississippi", "m??*ss*?i*pi"} // true
    };

    for (auto &tc : testCases) {
        cout << "s = \"" << tc.first << "\", p = \"" << tc.second << "\"\n";
        cout << "Top-Down: " << (isMatch_TopDown(tc.first, tc.second) ? "true" : "false") << "\n";
        cout << "Bottom-Up: " << (isMatch_BottomUp(tc.first, tc.second) ? "true" : "false") << "\n";
        cout << "Space-Opt: " << (isMatch_SpaceOpt(tc.first, tc.second) ? "true" : "false") << "\n";
        cout << "--------------------------------------\n";
    }

    return 0;
}
