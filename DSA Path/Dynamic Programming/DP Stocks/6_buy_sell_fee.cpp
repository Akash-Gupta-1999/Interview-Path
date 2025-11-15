#include <bits/stdc++.h>
using namespace std;

/*
    🧠 Problem: Best Time to Buy and Sell Stock with Transaction Fee (LeetCode 714)

    You may complete as many transactions as you like — BUT
    each sale costs a transaction fee.

    State:
        idx  → current day
        buy  → 0 = can buy, 1 = can sell
*/


// ------------------ TOP-DOWN (Memoization) ------------------

int getProfit(int idx, int buy, vector<int>& prices, int n, int fee, vector<vector<int>>& dp) {
    if (idx == n) return 0;
    if (dp[idx][buy] != -1) return dp[idx][buy];

    int profit;
    if (buy == 0) {
        profit = max(-prices[idx] + getProfit(idx + 1, 1, prices, n, fee, dp),
                     0 + getProfit(idx + 1, 0, prices, n, fee, dp));
    } else {
        profit = max(prices[idx] - fee + getProfit(idx + 1, 0, prices, n, fee, dp),
                     0 + getProfit(idx + 1, 1, prices, n, fee, dp));
    }

    return dp[idx][buy] = profit;
}

int maxProfitMemo(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return getProfit(0, 0, prices, n, fee, dp);
}

/*
    ⏱️ Time:  O(N * 2)
    🧠 Space: O(N * 2 + recursion)
*/


// ------------------ BOTTOM-UP (Tabulation) ------------------

int maxProfitTab(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0)
                dp[idx][buy] = max(-prices[idx] + dp[idx + 1][1],
                                    dp[idx + 1][0]);
            else
                dp[idx][buy] = max(prices[idx] - fee + dp[idx + 1][0],
                                    dp[idx + 1][1]);
        }
    }
    return dp[0][0];
}

/*
    ⏱️ Time:  O(N * 2)
    🧠 Space: O(N * 2)
*/


// ------------------ SPACE-OPTIMIZED ------------------

int maxProfitSpaceOpt(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> ahead(2, 0), cur(2, 0);

    for (int idx = n - 1; idx >= 0; idx--) {
        cur[0] = max(-prices[idx] + ahead[1], ahead[0]);
        cur[1] = max(prices[idx] - fee + ahead[0], ahead[1]);
        ahead = cur;
    }
    return cur[0];
}

/*
    ⏱️ Time:  O(N)
    🧠 Space: O(1)
*/


// ------------------ MAIN DRIVER ------------------

int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{1,3,2,8,4,9}, 2},   // Expected: 8
        {{1,3,7,5,10,3}, 3},  // Expected: 6
        {{1,2,3,4,5}, 1},     // Expected: 3
        {{9,8,7,1,2}, 3}      // Expected: 0
    };

    for (auto &[prices, fee] : testCases) {
        cout << "Prices: ";
        for (int p : prices) cout << p << " ";
        cout << " Fee: " << fee << "\n";

        cout << "Memoization: " << maxProfitMemo(prices, fee) << "\n";
        cout << "Tabulation:  " << maxProfitTab(prices, fee) << "\n";
        cout << "Space Opt:   " << maxProfitSpaceOpt(prices, fee) << "\n";
        cout << "--------------------------------------\n";
    }
    return 0;
}
