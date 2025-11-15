#include <bits/stdc++.h>
using namespace std;

/*
Problem: Matrix Chain Multiplication (MCM)
------------------------------------------
Given an array 'arr[]' of size N that represents the dimensions of matrices such that
the ith matrix has dimensions arr[i-1] x arr[i].
We need to find the minimum number of scalar multiplications needed
to multiply the chain of matrices.

Example:
Input: arr = {10, 20, 30, 40, 30}
Output: 30000
Explanation: (A1*(A2*A3)) gives minimum cost = 30000

Intuition:
-----------
We try every possible point `k` to split between i and j.
Cost = (cost of left part) + (cost of right part) + (cost of multiplying both parts)
We take the minimum over all k.
This is a classic Partition DP problem.
*/

// ------------------- Recursive + Memoization (Top-Down) -------------------
int mcmTopDown(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    
    int mini = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = arr[i - 1] * arr[k] * arr[j]
                 + mcmTopDown(i, k, arr, dp)
                 + mcmTopDown(k + 1, j, arr, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

// ------------------- Tabulation (Bottom-Up) -------------------
int mcmBottomUp(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j < n; j++) {
            int mini = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = arr[i - 1] * arr[k] * arr[j]
                         + dp[i][k] + dp[k + 1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = (mini == INT_MAX ? 0 : mini);
        }
    }

    return dp[1][n - 1];
}

// ------------------- Wrapper Function -------------------
int matrixMultiplication(vector<int>& arr) {
    int n = arr.size();

    // Top-Down (Memoization)
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int topDownAns = mcmTopDown(1, n - 1, arr, dp);

    // Bottom-Up (Tabulation)
    int bottomUpAns = mcmBottomUp(arr);

    cout << "Top-Down (Memoization): " << topDownAns << endl;
    cout << "Bottom-Up (Tabulation): " << bottomUpAns << endl;

    return bottomUpAns; // returning one for consistency
}

// ------------------- Main Function with Multiple Test Cases -------------------
int main() {
    vector<vector<int>> testCases = {
        {40, 20, 30, 10, 30},    // Expected: 26000
        {10, 20, 30, 40, 30},    // Expected: 30000
        {10, 20, 30},            // Expected: 6000
        {10, 20},                // Expected: 0
        {5, 10, 3, 12, 5, 50, 6} // Expected: 2010
    };

    for (auto arr : testCases) {
        cout << "Dimensions: ";
        for (auto &x : arr) cout << x << " ";
        cout << "\n";
        matrixMultiplication(arr);
        cout << "------------------------------------\n";
    }

    return 0;
}
