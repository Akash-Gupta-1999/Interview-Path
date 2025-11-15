#include <bits/stdc++.h>
using namespace std;

/*
    COIN CHANGE (Leetcode 322)
    Goal: Minimum number of coins to make given amount.
    Pattern: Unbounded Knapsack (we can take same coin multiple times)
*/

// -------------------- TOP-DOWN (Recursion + Memoization) --------------------
int topdown(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
    // Base case 1: If amount == 0, we need 0 coins
    if (amount == 0) return 0;

    // Base case 2: If we have no coins left (i < 0) and amount > 0, impossible
    if (i < 0) return 1e9;

    if (dp[i][amount] != -1)
        return dp[i][amount];

    // Choice 1: Do not take current coin
    int notTake = topdown(i - 1, amount, coins, dp);

    // Choice 2: Take current coin (can reuse)
    int take = 1e9;
    if (coins[i] <= amount)
        take = 1 + topdown(i, amount - coins[i], coins, dp);

    return dp[i][amount] = min(take, notTake);
}

int coinChange_topdown(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = topdown(n - 1, amount, coins, dp);
    return (ans >= 1e9) ? -1 : ans;
}

// -------------------- BOTTOM-UP (Tabulation) --------------------
int coinChange_bottomup(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    // Base Case: First coin
    // We can only use coins[0] → if amount divisible by coins[0], it's possible
    for (int t = 0; t <= amount; t++) {
        if (t % coins[0] == 0)
            dp[0][t] = t / coins[0];
        else
            dp[0][t] = 1e9; // impossible
    }

    // Build up the table
    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= amount; t++) {
            int notTake = dp[i - 1][t];
            int take = 1e9;
            if (coins[i] <= t)
                take = 1 + dp[i][t - coins[i]];
            dp[i][t] = min(take, notTake);
        }
    }

    int ans = dp[n - 1][amount];
    return (ans >= 1e9) ? -1 : ans;
}

// -------------------- SPACE OPTIMIZED (1D DP) --------------------
int coinChange_spaceOpt(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

    // Base Case: Only using first coin
    for (int t = 0; t <= amount; t++) {
        if (t % coins[0] == 0)
            prev[t] = t / coins[0];
        else
            prev[t] = 1e9;
    }

    // Iterate coins
    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= amount; t++) {
            int notTake = prev[t];
            int take = 1e9;
            if (coins[i] <= t)
                take = 1 + curr[t - coins[i]]; // notice: same 'curr' → reuse allowed
            curr[t] = min(take, notTake);
        }
        prev = curr;
    }

    int ans = prev[amount];
    return (ans >= 1e9) ? -1 : ans;
}

// -------------------- MAIN + TEST CASES --------------------
int main() {
    vector<vector<int>> testCoins = {
        {1, 2, 5},
        {2},
        {1},
        {2, 5, 10, 1}
    };
    vector<int> testAmounts = {11, 3, 0, 27};

    for (int i = 0; i < testCoins.size(); i++) {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Coins: ";
        for (auto c : testCoins[i]) cout << c << " ";
        cout << "\nAmount: " << testAmounts[i] << endl;

        cout << "Top-Down Ans: " << coinChange_topdown(testCoins[i], testAmounts[i]) << endl;
        cout << "Bottom-Up Ans: " << coinChange_bottomup(testCoins[i], testAmounts[i]) << endl;
        cout << "Space Opt Ans: " << coinChange_spaceOpt(testCoins[i], testAmounts[i]) << endl;
        cout << "---------------------------------\n";
    }

    return 0;
}
