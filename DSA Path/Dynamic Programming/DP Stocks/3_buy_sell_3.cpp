#include <bits/stdc++.h>
using namespace std;

/*
    🧠 Problem: Best Time to Buy and Sell Stock III
    (At most 2 transactions allowed)

    INTUITION:
    - We can only make at most 2 transactions.
    - Each day, we have two states:
        -> buy = 0: we can buy
        -> buy = 1: we can sell
    - cap represents how many transactions are remaining.
    - On each day, we either:
        1️⃣ Take an action (buy/sell)
        2️⃣ Skip
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

int maxProfitMemo(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return getProfit(0, 0, 2, prices, n, dp);
}

/*
    ⏱️ Time: O(N * 2 * 3)
    🧠 Space: O(N * 2 * 3 + recursion stack)
*/


// ------------------- BOTTOM-UP (Tabulation) -------------------

int maxProfitTab(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                if (buy == 0)
                    dp[idx][buy][cap] = max(-prices[idx] + dp[idx + 1][1][cap],
                                             dp[idx + 1][0][cap]);
                else
                    dp[idx][buy][cap] = max(prices[idx] + dp[idx + 1][0][cap - 1],
                                             dp[idx + 1][1][cap]);
            }
        }
    }
    return dp[0][0][2];
}

/*
    ⏱️ Time: O(N * 2 * 3)
    🧠 Space: O(N * 2 * 3)
*/


// ------------------- SPACE OPTIMIZED DP -------------------

int maxProfitSpaceOpt(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> ahead(2, vector<int>(3, 0)), cur(2, vector<int>(3, 0));

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
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
    return ahead[0][2];
}

/*
    ⏱️ Time: O(N * 2 * 3)
    🧠 Space: O(2 * 3) = O(1)
*/


// ------------------- MAIN DRIVER -------------------

int main() {
    vector<vector<int>> testCases = {
        {3,3,5,0,0,3,1,4},    // Expected: 6
        {1,2,3,4,5},          // Expected: 4
        {7,6,4,3,1},          // Expected: 0
        {1,2,4,2,5,7,2,4,9,0} // Expected: 13
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
