#include <bits/stdc++.h>
using namespace std;

/*
    UNBOUNDED KNAPSACK
    -------------------------------------
    - Items: weight[i], value[i]
    - Knapsack capacity: W
    - Each item can be taken unlimited times
    - Goal: Maximize total value without exceeding capacity
*/

/* ============================================================
   1️⃣ TOP-DOWN RECURSION + MEMOIZATION
   ============================================================ */
int unboundedKnapsackTD(int idx, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    // Base case: only one item left (index 0)
    if (idx == 0) {
        // Maximum number of times we can take item 0
        return (W / wt[0]) * val[0];
    }

    if (dp[idx][W] != -1) return dp[idx][W];

    // Option 1: Do not take current item
    int notTake = unboundedKnapsackTD(idx - 1, W, wt, val, dp);

    // Option 2: Take current item (stay at same idx, since we can reuse)
    int take = 0;
    if (wt[idx] <= W)
        take = val[idx] + unboundedKnapsackTD(idx, W - wt[idx], wt, val, dp);

    return dp[idx][W] = max(take, notTake);
}

int unboundedKnapsack_topdown(vector<int>& wt, vector<int>& val, int W) {
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return unboundedKnapsackTD(n - 1, W, wt, val, dp);
}

/* ============================================================
   2️⃣ BOTTOM-UP TABULATION
   ============================================================ */
int unboundedKnapsack_tab(vector<int>& wt, vector<int>& val, int W) {
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Base case: only first item
    for (int w = 0; w <= W; w++) {
        dp[0][w] = (w / wt[0]) * val[0];
    }

    // Fill table
    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            int notTake = dp[i - 1][w];
            int take = 0;
            if (wt[i] <= w)
                take = val[i] + dp[i][w - wt[i]]; // reuse same item
            dp[i][w] = max(take, notTake);
        }
    }

    return dp[n - 1][W];
}

/* ============================================================
   3️⃣ SPACE OPTIMIZED DP
   ============================================================ */
int unboundedKnapsack_spaceOpt(vector<int>& wt, vector<int>& val, int W) {
    int n = wt.size();
    vector<int> dp(W + 1, 0);

    // Base case: only first item
    for (int w = 0; w <= W; w++)
        dp[w] = (w / wt[0]) * val[0];

    // Iterate over items
    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            int notTake = dp[w];
            int take = 0;
            if (wt[i] <= w)
                take = val[i] + dp[w - wt[i]];
            dp[w] = max(take, notTake);
        }
    }

    return dp[W];
}

/* ============================================================
   MAIN + TEST CASES
   ============================================================ */
int main() {
    vector<int> wt = {2, 3, 5};
    vector<int> val = {50, 100, 140};
    int W = 17;

    cout << "Top-down: " << unboundedKnapsack_topdown(wt, val, W) << endl;
    cout << "Tabulation: " << unboundedKnapsack_tab(wt, val, W) << endl;
    cout << "Space optimized: " << unboundedKnapsack_spaceOpt(wt, val, W) << endl;

    // More test
    vector<int> wt2 = {1, 3, 4, 5};
    vector<int> val2 = {10, 40, 50, 70};
    int W2 = 8;
    cout << "\nAnother test:\n";
    cout << "Max Value: " << unboundedKnapsack_spaceOpt(wt2, val2, W2) << endl;

    return 0;
}
