#include <bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string str1, string str2) {
    int n1 = str1.size(), n2 = str2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    // Build LCS DP table
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Reconstruct the shortest supersequence
    int i = n1, j = n2;
    string ans = "";

    while (i > 0 && j > 0) {
        if (str1[i-1] == str2[j-1]) {
            ans += str1[i-1];
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            ans += str1[i-1];
            i--;
        } else {
            ans += str2[j-1];
            j--;
        }
    }

    // Add remaining characters
    while (i > 0) {
        ans += str1[i-1];
        i--;
    }
    while (j > 0) {
        ans += str2[j-1];
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<pair<string, string>> testCases = {
        {"abac", "cab"},       // Expected: "cabac"
        {"geek", "eke"},       // Expected: "geeke"
        {"AGGTAB", "GXTXAYB"}, // Expected: "AGXGTXAYB"
        {"aaaa", "aa"},        // Expected: "aaaa"
        {"abc", "def"}         // Expected: "abcdef"
    };

    for (auto &tc : testCases) {
        string str1 = tc.first;
        string str2 = tc.second;
        cout << "str1 = \"" << str1 << "\", str2 = \"" << str2 << "\"\n";
        cout << "Shortest Common Supersequence: " 
             << shortestCommonSupersequence(str1, str2) << "\n";
        cout << "-----------------------------------\n";
    }

    return 0;
}
