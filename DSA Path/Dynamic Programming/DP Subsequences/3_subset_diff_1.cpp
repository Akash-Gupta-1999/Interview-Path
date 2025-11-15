#include <bits/stdc++.h>
using namespace std;

/* ======================================================
   1️⃣ RECURSION + MEMOIZATION
   ====================================================== */

bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (ind == 0) return arr[0] == target;
    if (dp[ind][target] != -1) return dp[ind][target];

    bool notTake = subsetSumUtil(ind - 1, target, arr, dp);
    bool take = false;
    if (arr[ind] <= target)
        take = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = take || notTake;
}

int minSubsetSumDifference_memo(vector<int>& arr) {
    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));

    for (int target = 0; target <= totalSum; target++)
        subsetSumUtil(n - 1, target, arr, dp);

    int mini = 1e9;
    for (int s1 = 0; s1 <= totalSum / 2; s1++) {
        if (dp[n - 1][s1] == true) {
            int s2 = totalSum - s1;
            mini = min(mini, abs(s2 - s1));
        }
    }
    return mini;
}

/* ======================================================
   2️⃣ TABULATION (BOTTOM-UP)
   ====================================================== */

int minSubsetSumDifference_tab(vector<int>& arr) {
    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));

    // Base case
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    if (arr[0] <= totalSum)
        dp[0][arr[0]] = true;

    // Build DP table
    for (int i = 1; i < n; i++) {
        for (int target = 1; target <= totalSum; target++) {
            bool notTake = dp[i - 1][target];
            bool take = false;
            if (arr[i] <= target)
                take = dp[i - 1][target - arr[i]];
            dp[i][target] = take || notTake;
        }
    }

    int mini = 1e9;
    for (int s1 = 0; s1 <= totalSum / 2; s1++) {
        if (dp[n - 1][s1]) {
            int s2 = totalSum - s1;
            mini = min(mini, abs(s2 - s1));
        }
    }
    return mini;
}

/* ======================================================
   3️⃣ SPACE OPTIMIZATION
   ====================================================== */

int minSubsetSumDifference_spaceOpt(vector<int>& arr) {
    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    vector<bool> prev(totalSum + 1, false), curr(totalSum + 1, false);
    prev[0] = true;
    if (arr[0] <= totalSum)
        prev[arr[0]] = true;

    for (int i = 1; i < n; i++) {
        curr[0] = true;
        for (int target = 1; target <= totalSum; target++) {
            bool notTake = prev[target];
            bool take = false;
            if (arr[i] <= target)
                take = prev[target - arr[i]];
            curr[target] = take || notTake;
        }
        prev = curr;
    }

    int mini = 1e9;
    for (int s1 = 0; s1 <= totalSum / 2; s1++) {
        if (prev[s1]) {
            int s2 = totalSum - s1;
            mini = min(mini, abs(s2 - s1));
        }
    }
    return mini;
}

/* ======================================================
   🧪 MAIN + MULTIPLE TEST CASES
   ====================================================== */

int main() {
    vector<vector<int>> testcases = {
        {1, 2, 3, 9},
        {1, 2, 7},
        {1, 6, 11, 5},
        {3, 1, 4, 2, 2, 1}
    };

    cout << "=== Minimum Subset Sum Difference (Striver style) ===\n\n";
    for (auto arr : testcases) {
        cout << "Array: ";
        for (int x : arr) cout << x << " ";
        cout << "\n";

        cout << "Memoization: " << minSubsetSumDifference_memo(arr) << "\n";
        cout << "Tabulation: " << minSubsetSumDifference_tab(arr) << "\n";
        cout << "Space Opt.: " << minSubsetSumDifference_spaceOpt(arr) << "\n\n";
    }

    return 0;
}
