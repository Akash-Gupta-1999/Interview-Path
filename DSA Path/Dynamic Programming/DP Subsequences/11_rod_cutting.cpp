#include <bits/stdc++.h>
using namespace std;

/* =========================================================
   ROD CUTTING — FULL DP TEMPLATE
   ========================================================= */

/* =========================================================
   1️⃣ TOP-DOWN RECURSION + MEMOIZATION
   ========================================================= */
int rodCuttingTD(int idx, int N, vector<int>& prices, vector<vector<int>>& dp) {
    if (N == 0) return 0;      // Rod fully used
    if (idx < 0) return 0;     // No piece types left

    if (dp[idx][N] != -1) return dp[idx][N];

    // Option 1: Do not take current piece
    int notTake = rodCuttingTD(idx - 1, N, prices, dp);

    // Option 2: Take current piece (unbounded)
    int take = 0;
    if (idx + 1 <= N)
        take = prices[idx] + rodCuttingTD(idx, N - idx - 1, prices, dp);

    return dp[idx][N] = max(take, notTake);
}

int rodCutting_topdown(vector<int>& prices, int N) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(N + 1, -1));
    return rodCuttingTD(n - 1, N, prices, dp);
}

/* =========================================================
   2️⃣ BOTTOM-UP TABULATION
   ========================================================= */
int rodCutting_tab(vector<int>& prices, int N) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(N + 1, 0));

    // Base case: first piece type (idx = 0)
    for (int j = 0; j <= N; j++)
        dp[0][j] = (j / 1) * prices[0]; // length 1 piece

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= N; j++) {
            int notTake = dp[i - 1][j];
            int take = (i + 1 <= j) ? prices[i] + dp[i][j - (i + 1)] : 0;
            dp[i][j] = max(take, notTake);
        }
    }

    return dp[n - 1][N];
}

/* =========================================================
   3️⃣ SPACE-OPTIMIZED DP
   ========================================================= */
int rodCutting_spaceOpt(vector<int>& prices, int N) {
    int n = prices.size();
    vector<int> prev(N + 1, 0);

    // Base case: first piece type (idx = 0)
    for (int j = 0; j <= N; j++)
        prev[j] = (j / 1) * prices[0];

    for (int i = 1; i < n; i++) {
        vector<int> curr(N + 1, 0);
        for (int j = 0; j <= N; j++) {
            int notTake = prev[j];
            int take = (i + 1 <= j) ? prices[i] + curr[j - (i + 1)] : 0; // use curr for unbounded
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[N];
}

/* =========================================================
   MAIN + MULTIPLE TEST CASES
   ========================================================= */
int main() {
    vector<pair<vector<int>, int>> tests = {
        {{1, 5, 8, 9}, 4},
        {{3, 5, 8, 9, 10, 17, 17, 20}, 8},
        {{2, 5, 7, 8, 10}, 5},
        {{1, 2, 3, 4, 5}, 5}
    };

    for (int t = 0; t < tests.size(); t++) {
        vector<int> prices = tests[t].first;
        int N = tests[t].second;
        cout << "Test Case " << t + 1 << " (Rod length " << N << "):\n";
        cout << "Top-down: " << rodCutting_topdown(prices, N) << endl;
        cout << "Tabulation: " << rodCutting_tab(prices, N) << endl;
        cout << "Space-opt: " << rodCutting_spaceOpt(prices, N) << endl;
        cout << "-----------------------------------------\n";
    }

    return 0;
}
