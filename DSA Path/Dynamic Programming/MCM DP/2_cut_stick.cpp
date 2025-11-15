#include <bits/stdc++.h>
using namespace std;

/*
Problem: Minimum Cost to Cut a Stick
-----------------------------------
You are given a stick of length 'n' and an array 'cuts[]' where cuts[i] denotes
the position to make a cut. You can make cuts in any order, but each cut costs
the current length of the stick being cut.

Find the minimum total cost to cut the entire stick.

Example:
--------
Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation:
    If we cut at 3 first -> cost = 7
    Then cut [1,3] at 1 -> cost = 3
    Then cut [3,7] at 5 -> cost = 4
    Then cut [3,5] at 4 -> cost = 2
    Total = 16

Intuition:
----------
This is similar to Matrix Chain Multiplication.
Each cut divides the stick into two subproblems (left and right parts).
We try every possible cut 'k' between i and j, compute cost, and take the minimum.
*/

// ------------------- Recursive + Memoization (Top-Down) -------------------
int topdown(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;
    for (int k = i; k <= j; k++) {
        int cost = cuts[j + 1] - cuts[i - 1]
                 + topdown(i, k - 1, cuts, dp)
                 + topdown(k + 1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

// ------------------- Tabulation (Bottom-Up) -------------------
int bottomup(int n, vector<int>& cuts) {
    int c = cuts.size() - 2; // actual number of cuts (excluding 0 and n)
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--) {
        for (int j = 1; j <= c; j++) {
            if (i > j) continue;
            int mini = INT_MAX;
            for (int k = i; k <= j; k++) {
                int cost = cuts[j + 1] - cuts[i - 1]
                         + dp[i][k - 1] + dp[k + 1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = (mini == INT_MAX ? 0 : mini);
        }
    }

    return dp[1][c];
}

// ------------------- Wrapper Function -------------------
int minCost(int n, vector<int>& cuts) {
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    // Top-Down
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    int topDownAns = topdown(1, c, cuts, dp);

    // Bottom-Up
    int bottomUpAns = bottomup(n, cuts);

    cout << "Top-Down (Memoization): " << topDownAns << endl;
    cout << "Bottom-Up (Tabulation): " << bottomUpAns << endl;

    return bottomUpAns;
}

// ------------------- Main Function -------------------
int main() {
    vector<pair<int, vector<int>>> testCases = {
        {7, {1,3,4,5}},      // Expected: 16
        {9, {5,6,1,4,2}},    // Expected: 22
        {10, {2,4,7}},       // Expected: 20
        {5, {1,3}},          // Expected: 8
        {6, {1,2,5}}         // Expected: 13
    };

    for (auto &[n, cuts] : testCases) {
        cout << "Stick length: " << n << ", Cuts: ";
        for (int x : cuts) cout << x << " ";
        cout << "\n";
        minCost(n, cuts);
        cout << "------------------------------------\n";
    }

    return 0;
}
