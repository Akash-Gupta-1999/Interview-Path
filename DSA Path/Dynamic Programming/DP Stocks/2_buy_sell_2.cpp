#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------
// 🧠 Problem Intuition:
// We can make as many transactions as we want (buy/sell pairs),
// but we can hold only ONE stock at a time.
//
// Choices at each day:
// - If we can BUY: either buy or skip.
// - If we can SELL: either sell or skip.
// -----------------------------------------------------------

// ===========================================================
// 1️⃣ Recursive + Memoization (Top-Down DP)
// -----------------------------------------------------------
int f(int ind, int canBuy, vector<int>& prices, vector<vector<int>>& dp) {
    if (ind == prices.size()) return 0;
    if (dp[ind][canBuy] != -1) return dp[ind][canBuy];

    int profit = 0;
    if (canBuy) {
        // Option 1: Buy today → subtract price, next day can't buy
        // Option 2: Skip today
        profit = max(-prices[ind] + f(ind + 1, 0, prices, dp),
                     f(ind + 1, 1, prices, dp));
    } else {
        // Option 1: Sell today → add price, next day can buy
        // Option 2: Skip today
        profit = max(prices[ind] + f(ind + 1, 1, prices, dp),
                     f(ind + 1, 0, prices, dp));
    }
    return dp[ind][canBuy] = profit;
}

int maxProfitTD(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, 1, prices, dp);
}

// Complexity: ⏱️ O(N*2) | 🧠 O(N*2) + Recursion Stack O(N)


// ===========================================================
// 2️⃣ Bottom-Up Tabulation DP
// -----------------------------------------------------------
int maxProfitBU(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int canBuy = 0; canBuy <= 1; canBuy++) {
            if (canBuy)
                dp[ind][canBuy] = max(-prices[ind] + dp[ind + 1][0],
                                       dp[ind + 1][1]);
            else
                dp[ind][canBuy] = max(prices[ind] + dp[ind + 1][1],
                                       dp[ind + 1][0]);
        }
    }
    return dp[0][1];
}

// Complexity: ⏱️ O(N*2) | 🧠 O(N*2)


// ===========================================================
// 3️⃣ Space Optimized DP
// -----------------------------------------------------------
int maxProfitSO(vector<int>& prices) {
    int n = prices.size();
    vector<int> ahead(2, 0), cur(2, 0);

    for (int ind = n - 1; ind >= 0; ind--) {
        cur[1] = max(-prices[ind] + ahead[0], ahead[1]); // buy state
        cur[0] = max(prices[ind] + ahead[1], ahead[0]);  // sell state
        ahead = cur;
    }
    return ahead[1];
}

// Complexity: ⏱️ O(N) | 🧠 O(1)


// ===========================================================
// 4️⃣ Greedy Approach (Simplest & Optimal)
// -----------------------------------------------------------
// Just add every positive price difference.
int maxProfitGreedy(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
        if (prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1];
    return profit;
}

// Complexity: ⏱️ O(N) | 🧠 O(1)


// ===========================================================
// 🔍 Driver Code with Multiple Test Cases
// -----------------------------------------------------------
int main() {
    vector<vector<int>> testCases = {
        {7, 1, 5, 3, 6, 4},       // Expected: 7
        {1, 2, 3, 4, 5},          // Expected: 4
        {7, 6, 4, 3, 1},          // Expected: 0
        {2, 1, 2, 0, 1},          // Expected: 2
        {3, 3, 5, 0, 0, 3, 1, 4}  // Expected: 8
    };

    for (auto &prices : testCases) {
        cout << "Prices: ";
        for (int p : prices) cout << p << " ";
        cout << "\n";

        cout << "Top-Down DP: " << maxProfitTD(prices) << "\n";
        cout << "Bottom-Up DP: " << maxProfitBU(prices) << "\n";
        cout << "Space Opt DP: " << maxProfitSO(prices) << "\n";
        cout << "Greedy: " << maxProfitGreedy(prices) << "\n";
        cout << "-----------------------------\n";
    }

    return 0;
}
