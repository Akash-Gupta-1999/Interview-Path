#include <bits/stdc++.h>
using namespace std;

/* =========================================================
   LONGEST COMMON SUBSEQUENCE — LENGTH + STRING (Single Version)
   ========================================================= */

string longestCommonSubsequence(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Reconstruct LCS from dp table
    string lcs = "";
    int i = n1, j = n2;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs += s1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

/* =========================================================
   TEST CASES
   ========================================================= */
int main() {
    vector<pair<string, string>> tests = {
        {"abcde", "ace"},
        {"abc", "abc"},
        {"abc", "def"},
        {"aggtab", "gxtxayb"},
        {"bl", "yby"}
    };

    for (auto &tc : tests) {
        string s1 = tc.first, s2 = tc.second;
        string lcs = longestCommonSubsequence(s1, s2);
        cout << "s1 = " << s1 << ", s2 = " << s2 << endl;
        cout << "LCS length = " << lcs.size() << endl;
        cout << "LCS string = \"" << lcs << "\"" << endl;
        cout << "--------------------------------------\n";
    }

    return 0;
}
