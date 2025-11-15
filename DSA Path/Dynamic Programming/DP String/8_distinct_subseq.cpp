#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

// ---------- TOP-DOWN (RECURSION + MEMOIZATION) ----------
int solveTopDown(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
    // Base cases
    if (j < 0) return 1;  // t completely matched
    if (i < 0) return 0;  // s exhausted but t not matched

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == t[j]) {
        // Choose to match or skip s[i]
        long long include = solveTopDown(i - 1, j - 1, s, t, dp);
        long long exclude = solveTopDown(i - 1, j, s, t, dp);
        return dp[i][j] = (include + exclude) % MOD;
    } else {
        return dp[i][j] = solveTopDown(i - 1, j, s, t, dp) % MOD;
    }
}

int numDistinct_TopDown(string s, string t) {
    int n1 = s.size(), n2 = t.size();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return solveTopDown(n1 - 1, n2 - 1, s, t, dp);
}

// ---------- BOTTOM-UP (TABULATION) ----------
int numDistinct_BottomUp(string s, string t) {
    int n1 = s.size(), n2 = t.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 0; i <= n1; i++)
        dp[i][0] = 1;  // Empty t can be formed in 1 way

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n1][n2];
}

// ---------- SPACE OPTIMIZED (1D DP) ----------
int numDistinct_SpaceOpt(string s, string t) {
    int n1 = s.size(), n2 = t.size();
    vector<long long> prev(n2 + 1, 0), cur(n2 + 1, 0);
    prev[0] = cur[0] = 1;

    for (int i = 1; i <= n1; i++) {
        for (int j = n2; j >= 1; j--) {
            if (s[i - 1] == t[j - 1])
                prev[j] = (prev[j - 1] + prev[j]) % MOD;
            // else case implicitly covered since we always use prev
        }
    }

    return prev[n2];
}

// ---------- MAIN FUNCTION ----------
int main() {
    vector<pair<string, string>> testCases = {
        {"rabbbit", "rabbit"},    // Expected: 3
        {"babgbag", "bag"},       // Expected: 5
        {"abc", "abc"},           // Expected: 1
        {"abc", "def"},           // Expected: 0
        {"aaaaa", "aa"}           // Expected: 10
    };

    for (auto &tc : testCases) {
        string s = tc.first;
        string t = tc.second;
        cout << "s = \"" << s << "\", t = \"" << t << "\"\n";
        cout << "Top-Down Result: " << numDistinct_TopDown(s, t) << "\n";
        cout << "Bottom-Up Result: " << numDistinct_BottomUp(s, t) << "\n";
        cout << "Space Optimized Result: " << numDistinct_SpaceOpt(s, t) << "\n";
        cout << "-------------------------------------------\n";
    }

    return 0;
}
