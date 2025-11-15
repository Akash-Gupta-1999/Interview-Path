#include <bits/stdc++.h>
using namespace std;

/*
    🧠 Problem: Best Time to Buy and Sell Stock with Cooldown (LeetCode 309)

    You may complete as many transactions as you like BUT:
    After selling, you cannot buy the next day (1-day cooldown).

    States:
        idx  → current day
        buy  → 0 = can buy, 1 = can sell

    Transitions:
        If buy == 0:
            - Buy today → -prices[idx] + next day in sell state
            - Skip → stay in same buy state
        If buy == 1:
            - Sell today → +prices[idx] + jump 2 days ahead (cooldown)
            - Skip → stay in same sell state
*/


// ------------------- TOP-DOWN (Memoization) -------------------

int getProfit(int idx, int buy, vector<int>& prices, int n, vector<vector<int>>& dp) {
    if (idx >= n) return 0;              // base: out of bounds
    if (dp[idx][buy] != -1) return dp[idx][buy];

    int profit;
    if (buy == 0)
        profit = max(-prices[idx] + getProfit(idx + 1, 1, prices, n, dp),
                     0 + getProfit(idx + 1, 0, prices, n, dp));
    else
        profit = max(prices[idx] + getProfit(idx + 2, 0, prices, n, dp),
                     0 + getProfit(idx + 1, 1, prices, n, dp));

    return dp[idx][buy] = profit;
}

int maxProfitMemo(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return getProfit(0, 0, prices, n, dp);
}

/*
    ⏱️ Time:  O(N * 2)
    🧠 Space: O(N * 2 + recursion stack)
*/


// ------------------- BOTTOM-UP (Tabulation) -------------------

int maxProfitTab(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0)); // +2 to avoid out of bounds for cooldown

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0)
                dp[idx][buy] = max(-prices[idx] + dp[idx + 1][1],
                                    dp[idx + 1][0]);
            else
                dp[idx][buy] = max(prices[idx] + dp[idx + 2][0],
                                    dp[idx + 1][1]);
        }
    }

    return dp[0][0];
}

/*
    ⏱️ Time:  O(N * 2)
    🧠 Space: O(N * 2)
*/


// ------------------- SPACE OPTIMIZED -------------------

int maxProfitSpaceOpt(vector<int>& prices) {
    int n = prices.size();
    vector<int> ahead1(2, 0), ahead2(2, 0), cur(2, 0);

    for (int idx = n - 1; idx >= 0; idx--) {
        cur[0] = max(-prices[idx] + ahead1[1], ahead1[0]);
        cur[1] = max(prices[idx] + ahead2[0], ahead1[1]);

        ahead2 = ahead1;
        ahead1 = cur;
    }

    return cur[0];
}

/*
    ⏱️ Time:  O(N * 2)
    🧠 Space: O(1)
*/


// ------------------- MAIN DRIVER -------------------

int main() {
    vector<vector<int>> testCases = {
        {1,2,3,0,2},    // Expected: 3
        {1},            // Expected: 0
        {2,1,4},        // Expected: 3
        {6,1,3,2,4,7},  // Expected: 6
        {1,2,3,4,5}     // Expected: 4
    };

    for (auto &prices : testCases) {
        cout << "Prices: ";
        for (int p : prices) cout << p << " ";
        cout << "\n";

        cout << "Memoization: " << maxProfitMemo(prices) << "\n";
        cout << "Tabulation:  " << maxProfitTab(prices) << "\n";
        cout << "Space Opt:   " << maxProfitSpaceOpt(prices) << "\n";
        cout << "--------------------------------------\n";
    }

    return 0;
}
