#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Top-Down (Memoization)
    int countPalindromicSubsequences_TopDown(const string &s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(const_cast<string&>(s), 0, n - 1, dp);
    }

    // Bottom-Up (Tabulation)
    int countPalindromicSubsequences_BottomUp(const string &s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Single characters
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        // Fill for increasing substring length
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                }
            }
        }

        return dp[0][n - 1];
    }

private:
    // Helper for Top-Down recursion
    int solve(string &s, int i, int j, vector<vector<int>> &dp) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j])
            dp[i][j] = solve(s, i + 1, j, dp) +
                       solve(s, i, j - 1, dp) + 1;
        else
            dp[i][j] = solve(s, i + 1, j, dp) +
                       solve(s, i, j - 1, dp) -
                       solve(s, i + 1, j - 1, dp);

        return dp[i][j];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vector<string> testcases = {
        "aab", "aaa", "abc", "aba", "abba", "baab", "abcdcba"
    };

    for (auto &s : testcases) {
        cout << "String: " << s << "\n";
        cout << "Top-Down Count:   " << sol.countPalindromicSubsequences_TopDown(s) << "\n";
        cout << "Bottom-Up Count:  " << sol.countPalindromicSubsequences_BottomUp(s) << "\n";
        cout << "---------------------------------------\n";
    }

    return 0;
}
