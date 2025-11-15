#include <bits/stdc++.h>
using namespace std;

/*
    LEETCODE 518 — COIN CHANGE II
    --------------------------------------
    Count the number of combinations that make up a given amount.
    Each coin can be used infinite times.

    ✅ Type: Unbounded Knapsack / Infinite Supply Coin DP
*/

/* ============================================================
   1️⃣ TOP-DOWN RECURSION + MEMOIZATION
   ============================================================ */
int topdown(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {
    // Base Case: Only one type of coin left (index 0)
    if (idx == 0) {
        // If amount is divisible by this coin, we can form it in exactly one way
        return (amount % coins[0] == 0);
    }

    if (dp[idx][amount] != -1)
        return dp[idx][amount];

    // Option 1: Do not take current coin
    int notTake = topdown(idx - 1, amount, coins, dp);

    // Option 2: Take current coin (stay at same index because we can reuse it)
    int take = 0;
    if (coins[idx] <= amount)
        take = topdown(idx, amount - coins[idx], coins, dp);

    return dp[idx][amount] = take + notTake;
}

int change_topdown(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return topdown(n - 1, amount, coins, dp);
}

/* ============================================================
   2️⃣ BOTTOM-UP TABULATION
   ============================================================ */
int change_tab(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    // Base case: first coin (only one type of coin)
    for (int t = 0; t <= amount; t++) {
        if (t % coins[0] == 0) dp[0][t] = 1;
    }

    // Build DP table
    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= amount; t++) {
            int notTake = dp[i - 1][t];
            int take = 0;
            if (coins[i] <= t)
                take = dp[i][t - coins[i]];
            dp[i][t] = take + notTake;
        }
    }

    return dp[n - 1][amount];
}

/* ============================================================
   3️⃣ SPACE OPTIMIZED DP
   ============================================================ */
int change_spaceOpt(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

    // Base case
    for (int t = 0; t <= amount; t++) {
        if (t % coins[0] == 0) prev[t] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= amount; t++) {
            int notTake = prev[t];
            int take = 0;
            if (coins[i] <= t)
                take = curr[t - coins[i]];
            curr[t] = take + notTake;
        }
        prev = curr;
    }

    return prev[amount];
}

/* ============================================================
   MAIN + TEST CASES
   ============================================================ */
int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    cout << "Top-down: " << change_topdown(amount, coins) << endl;
    cout << "Tabulation: " << change_tab(amount, coins) << endl;
    cout << "Space optimized: " << change_spaceOpt(amount, coins) << endl;

    // More tests
    vector<vector<int>> coinTests = {
        {1, 2, 5},
        {2},
        {10}
    };
    vector<int> amounts = {5, 3, 10};

    for (int i = 0; i < coinTests.size(); i++) {
        cout << "\nCoins: ";
        for (int c : coinTests[i]) cout << c << " ";
        cout << "\nAmount = " << amounts[i] << endl;
        cout << "Ways: " << change_topdown(amounts[i], coinTests[i]) << "\n";
    }

    return 0;
}
