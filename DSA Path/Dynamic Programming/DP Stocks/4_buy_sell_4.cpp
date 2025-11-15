#include <bits/stdc++.h>
using namespace std;

/*
    🧠 Problem: Best Time to Buy and Sell Stock IV
    (At most k transactions allowed)

    INTUITION:
    - We can perform at most `k` buy-sell transactions.
    - Each day, we have 2 states:
        -> buy = 0 → we can buy
        -> buy = 1 → we can sell
    - `cap` = number of transactions remaining.
    - For each state, we choose to take or skip the current action.
*/


// ------------------- TOP-DOWN (Memoization) -------------------

int getProfit(int idx, int buy, int cap, vector<int>& prices, int n,
              vector<vector<vector<int>>>& dp) {
    if (cap == 0 || idx == n) return 0;

    if (dp[idx][buy][cap] != -1) return dp[idx][buy][cap];

    int profit;
    if (buy == 0) {
        // Option 1: Buy
        // Option 2: Skip
        profit = max(-prices[idx] + getProfit(idx + 1, 1, cap, prices, n, dp),
                     0 + getProfit(idx + 1, 0, cap, prices, n, dp));
    } else {
        // Option 1: Sell
        // Option 2: Skip
        profit = max(prices[idx] + getProfit(idx + 1, 0, cap - 1, prices, n, dp),
                     0 + getProfit(idx + 1, 1, cap, prices, n, dp));
    }

    return dp[idx][buy][cap] = profit;
}

int maxProfitMemo(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return getProfit(0, 0, k, prices, n, dp);
}

/*
    ⏱️ Time: O(N * 2 * K)
    🧠 Space: O(N * 2 * K + recursion stack)
*/


// ------------------- BOTTOM-UP (Tabulation) -------------------

int maxProfitTab(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
                if (buy == 0)
                    dp[idx][buy][cap] = max(-prices[idx] + dp[idx + 1][1][cap],
                                             dp[idx + 1][0][cap]);
                else
                    dp[idx][buy][cap] = max(prices[idx] + dp[idx + 1][0][cap - 1],
                                             dp[idx + 1][1][cap]);
            }
        }
    }
    return dp[0][0][k];
}

/*
    ⏱️ Time: O(N * 2 * K)
    🧠 Space: O(N * 2 * K)
*/


// ------------------- SPACE OPTIMIZED DP -------------------

int maxProfitSpaceOpt(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> ahead(2, vector<int>(k + 1, 0)), cur(2, vector<int>(k + 1, 0));

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
                if (buy == 0)
                    cur[buy][cap] = max(-prices[idx] + ahead[1][cap],
                                         ahead[0][cap]);
                else
                    cur[buy][cap] = max(prices[idx] + ahead[0][cap - 1],
                                         ahead[1][cap]);
            }
        }
        ahead = cur;
    }
    return ahead[0][k];
}

/*
    ⏱️ Time: O(N * 2 * K)
    🧠 Space: O(2 * K) = O(K)
*/


// ------------------- MAIN DRIVER -------------------

int main() {
    vector<pair<int, vector<int>>> testCases = {
        {2, {3,3,5,0,0,3,1,4}},    // Expected: 6
        {2, {1,2,3,4,5}},          // Expected: 4
        {2, {7,6,4,3,1}},          // Expected: 0
        {3, {1,2,4,2,5,7,2,4,9,0}} // Expected: 15
    };

    for (auto &tc : testCases) {
        int k = tc.first;
        vector<int> prices = tc.second;

        cout << "k = " << k << ", Prices: ";
        for (int p : prices) cout << p << " ";
        cout << "\n";

        cout << "Memoization: " << maxProfitMemo(k, prices) << "\n";
        cout << "Tabulation:  " << maxProfitTab(k, prices) << "\n";
        cout << "Space Opt:   " << maxProfitSpaceOpt(k, prices) << "\n";
        cout << "--------------------------------------\n";
    }

    return 0;
}
