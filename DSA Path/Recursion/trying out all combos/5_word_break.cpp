#include <bits/stdc++.h>
using namespace std;

/*----------------------------------------------
1️⃣ Naive DFS (No Memoization)
----------------------------------------------*/
// Time Complexity: O(2^n) worst case (try every break)
// Space Complexity: O(n) recursion stack
bool dfs_naive(int idx, string &s, unordered_set<string> &dict) {
    if (idx == s.size()) return true; // reached end
    string word = "";
    for (int i = idx; i < s.size(); i++) {
        word += s[i];
        if (dict.count(word) && dfs_naive(i + 1, s, dict))
            return true;
    }
    return false;
}

bool wordBreakNaive(string s, vector<string> &wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    return dfs_naive(0, s, dict);
}

/*----------------------------------------------
2️⃣ Top-Down with Memoization
----------------------------------------------*/
// Time Complexity: O(n^2) — each index computed once, substring check O(n)
// Space Complexity: O(n) memo + recursion stack
bool dfs_memo(int idx, string &s, unordered_set<string> &dict, vector<int> &dp) {
    if (idx == s.size()) return true;
    if (dp[idx] != -1) return dp[idx]; // already computed

    string word = "";
    for (int i = idx; i < s.size(); i++) {
        word += s[i];
        if (dict.count(word) && dfs_memo(i + 1, s, dict, dp))
            return dp[idx] = true;
    }
    return dp[idx] = false;
}

bool wordBreakMemo(string s, vector<string> &wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<int> dp(s.size(), -1);
    return dfs_memo(0, s, dict, dp);
}

/*----------------------------------------------
3️⃣ Bottom-Up (Reverse DP)
----------------------------------------------*/
// Time Complexity: O(n^2) worst case
// Space Complexity: O(n) dp array
 bool wordBreakBottomUp(string s, vector<string>& wordDict) {
    int n = s.length();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(n + 1, false);
    dp[0] = true;  // Empty string is always "segmented"
    int maxLen = 0;

    // Find the maximum length of the words in the dictionary
    for (const string& word : wordDict) {
        maxLen = max(maxLen, (int)word.size());
    }

    // DP to check if the string can be segmented
    for (int i = 1; i <= n; ++i) {
        for (int j = max(0, i - maxLen); j < i; ++j) {
            if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                dp[i] = true;
                break;  // Early termination when we find a valid word
            }
        }
    }

    return dp[n];  // Return if the entire string can be segmented
    }

/*----------------------------------------------
🔹 Comparison Table
----------------------------------------------
Approach            | Time Complexity | Space Complexity | Pros                       | Cons
----------------------------------------------------------------------------------------------
Naive DFS           | O(2^n)          | O(n)             | Simple to write            | Very slow for large inputs
Top-Down Memo       | O(n^2)          | O(n)             | Intuitive recursion + fast | Recursion overhead
Bottom-Up Reverse   | O(n^2)          | O(n)             | No recursion, clean logic  | Slightly harder to intuit
----------------------------------------------*/

/*----------------------------------------------
Main & Test Cases
----------------------------------------------*/
int main() {
    vector<pair<string, vector<string>>> tests = {
        {"leetcode", {"leet", "code"}},
        {"applepenapple", {"apple", "pen"}},
        {"catsandog", {"cats", "dog", "sand", "and", "cat"}},
        {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
         {"a", "aa", "aaa", "aaaa", "aaaaa"}}
    };

    for (int t = 0; t < tests.size(); t++) {
        string s = tests[t].first;
        vector<string> dict = tests[t].second;
        cout << "Testcase " << t + 1 << ":\n";
        cout << "  Naive DFS:         " << (wordBreakNaive(s, dict) ? "true" : "false") << "\n";
        cout << "  Top-Down Memo:     " << (wordBreakMemo(s, dict) ? "true" : "false") << "\n";
        cout << "  Bottom-Up Reverse: " << (wordBreakBottomUp(s, dict) ? "true" : "false") << "\n";
        cout << "--------------------------------------\n";
    }

    return 0;
}
