#include <bits/stdc++.h>
using namespace std;

/*
Problem: Palindrome Partitioning II (Minimum Cuts)
--------------------------------------------------
Return the minimum number of cuts needed to partition a string 
such that every substring is a palindrome.

Example:
Input:  "aab"
Output: 1
Explanation: "aa" | "b"

--------------------------------------------------
Approaches:
1️⃣ Top-Down (Recursion + 1D Memoization)
2️⃣ Bottom-Up (Iterative DP)
--------------------------------------------------
Time Complexity: O(N³) [due to palindrome checks inside nested loops]
Space Complexity: O(N)
--------------------------------------------------
*/

// ---------- Utility: Check if substring is palindrome ----------
bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// ---------- Top-Down (Recursion + Memoization) ----------
int topdown(int i, string &s, vector<int> &dp) {
    int n = s.size();
    if (i == n || isPalindrome(i, n - 1, s)) return 0;
    if (dp[i] != -1) return dp[i];

    int mini = INT_MAX;
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, s)) {
            int cost = 1 + topdown(j + 1, s, dp);
            mini = min(mini, cost);
        }
    }
    return dp[i] = mini;
}

int minCutTopDown(string s) {
    int n = s.size();
    vector<int> dp(n, -1);
    return topdown(0, s, dp);
}

// ---------- Bottom-Up (Iterative DP) ----------
int minCutBottomUp(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = -1; // base case: no cut needed beyond last char

    for (int i = n - 1; i >= 0; i--) {
        int mini = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, s)) {
                mini = min(mini, 1 + dp[j + 1]);
            }
        }
        dp[i] = mini;
    }
    return dp[0];
}

// ---------- Main (Multiple Test Cases) ----------
int main() {
    vector<string> testCases = {
        "aab",           // Expected: 1
        "a",             // Expected: 0
        "ab",            // Expected: 1
        "noon",          // Expected: 0
        "ababbbabbababa" // Expected: 3
    };

    for (auto &s : testCases) {
        cout << "String: " << s << "\n";
        cout << "Top-Down  -> " << minCutTopDown(s) << "\n";
        cout << "Bottom-Up -> " << minCutBottomUp(s) << "\n";
        cout << "------------------------------------\n";
    }

    return 0;
}
