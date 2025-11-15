#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;

/*
Problem: Evaluate Boolean Expression to True
--------------------------------------------
Given a boolean expression containing:
- 'T' for True
- 'F' for False
- '&' (AND), '|' (OR), '^' (XOR)
Return the number of ways to parenthesize the expression
so that it evaluates to TRUE.

Example:
Input:  exp = "T|F&T^T"
Output: 5
Explanation: There are 5 ways to evaluate this to TRUE.

--------------------------------------------
Approaches:
1️⃣ Top-Down (Recursion + Memoization)
2️⃣ Bottom-Up (Tabulation)
--------------------------------------------
Complexity:
- Time: O(N^3)
- Space: O(N^2)
--------------------------------------------
*/

// ------------------- Top-Down (Memoization) -------------------
int topdown(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp) {
    if (i > j) return 0;

    if (i == j) {
        if (isTrue) return exp[i] == 'T';
        else return exp[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    ll ways = 0;

    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        ll lT = topdown(i, ind - 1, 1, exp, dp);
        ll lF = topdown(i, ind - 1, 0, exp, dp);
        ll rT = topdown(ind + 1, j, 1, exp, dp);
        ll rF = topdown(ind + 1, j, 0, exp, dp);

        char op = exp[ind];
        if (op == '&') {
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lT * rF + lF * rT + lF * rF) % mod) % mod;
        }
        else if (op == '|') {
            if (isTrue) ways = (ways + (lT * rT + lT * rF + lF * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else if (op == '^') {
            if (isTrue) ways = (ways + (lT * rF + lF * rT) % mod) % mod;
            else ways = (ways + (lT * rT + lF * rF) % mod) % mod;
        }
    }

    return dp[i][j][isTrue] = ways % mod;
}

int evaluateExpTopDown(string &exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    return topdown(0, n - 1, 1, exp, dp);
}

// ------------------- Bottom-Up (Tabulation) -------------------
int evaluateExpBottomUp(string &exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));

    // Base case: single symbol
    for (int i = 0; i < n; i++) {
        if (exp[i] == 'T') dp[i][i][1] = 1;
        else if (exp[i] == 'F') dp[i][i][0] = 1;
    }

    // Length of substring (must be at least 3 to include operator)
    for (int len = 3; len <= n; len += 2) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            for (int ind = i + 1; ind <= j - 1; ind += 2) {
                ll lT = dp[i][ind - 1][1];
                ll lF = dp[i][ind - 1][0];
                ll rT = dp[ind + 1][j][1];
                ll rF = dp[ind + 1][j][0];
                char op = exp[ind];

                if (op == '&') {
                    dp[i][j][1] = (dp[i][j][1] + (lT * rT) % mod) % mod;
                    dp[i][j][0] = (dp[i][j][0] + (lT * rF + lF * rT + lF * rF) % mod) % mod;
                }
                else if (op == '|') {
                    dp[i][j][1] = (dp[i][j][1] + (lT * rT + lT * rF + lF * rT) % mod) % mod;
                    dp[i][j][0] = (dp[i][j][0] + (lF * rF) % mod) % mod;
                }
                else if (op == '^') {
                    dp[i][j][1] = (dp[i][j][1] + (lT * rF + lF * rT) % mod) % mod;
                    dp[i][j][0] = (dp[i][j][0] + (lT * rT + lF * rF) % mod) % mod;
                }
            }
        }
    }

    return dp[0][n - 1][1]; // #ways to evaluate to TRUE
}

// ------------------- Main -------------------
int main() {
    vector<string> testCases = {
        "F|T^F",
        "T|F&T^T",
        "T^T^F",
        "T|T&F^T",
        "T",
        "F"
    };

    for (auto &exp : testCases) {
        cout << "Expression: " << exp << "\n";
        cout << "Top-Down  -> " << evaluateExpTopDown(exp) << "\n";
        cout << "Bottom-Up -> " << evaluateExpBottomUp(exp) << "\n";
        cout << "--------------------------------------\n";
    }

    return 0;
}
