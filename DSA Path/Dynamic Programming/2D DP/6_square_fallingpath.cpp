#include <bits/stdc++.h>
using namespace std;

// ==========================
// Approach 1: Top-Down DP
// ==========================
int topdown(int i, int j, int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
    if(j < 0 || j >= n) return INT_MAX;
    if(i == 0) return matrix[i][j];
    if(dp[i][j] != INT_MAX) return dp[i][j];

    int leftdiag = topdown(i-1, j-1, m, n, matrix, dp);
    int up = topdown(i-1, j, m, n, matrix, dp);
    int rightdiag = topdown(i-1, j+1, m, n, matrix, dp);

    return dp[i][j] = matrix[i][j] + min({leftdiag, up, rightdiag});
}

int minFallingPathSumTopDown(vector<vector<int>>& matrix){
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    int mini = INT_MAX;
    for(int j = 0; j < n; j++)
        mini = min(mini, topdown(m-1, j, m, n, matrix, dp));
    return mini;
}

// ==========================
// Approach 2: Bottom-Up DP
// ==========================
int minFallingPathSumBottomUp(vector<vector<int>>& matrix){
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int j = 0; j < n; j++) dp[0][j] = matrix[0][j];

    for(int i = 1; i < m; i++){
        for(int j = 0; j < n; j++){
            int left = (j-1 >= 0) ? dp[i-1][j-1] : INT_MAX;
            int up = dp[i-1][j];
            int right = (j+1 < n) ? dp[i-1][j+1] : INT_MAX;
            dp[i][j] = matrix[i][j] + min({left, up, right});
        }
    }

    int mini = INT_MAX;
    for(int j = 0; j < n; j++) mini = min(mini, dp[m-1][j]);
    return mini;
}

// ==========================
// Approach 3: Space-Optimized DP
// ==========================
int minFallingPathSumSpaceOpt(vector<vector<int>>& matrix){
    int m = matrix.size(), n = matrix[0].size();
    vector<int> prev(matrix[0]);
    for(int i = 1; i < m; i++){
        vector<int> curr(n, INT_MAX);
        for(int j = 0; j < n; j++){
            int left = (j-1 >= 0) ? prev[j-1] : INT_MAX;
            int up = prev[j];
            int right = (j+1 < n) ? prev[j+1] : INT_MAX;
            curr[j] = matrix[i][j] + min({left, up, right});
        }
        prev = curr;
    }
    return *min_element(prev.begin(), prev.end());
}

// ==========================
// Main Function with Test Cases
// ==========================
int main(){
    vector<vector<vector<int>>> testCases = {
        {{2,1,3},
         {6,5,4},
         {7,8,9}},
         
        {{-19,57},
         {-40,-5}},
         
        {{2,2,1,3},
         {3,4,2,2},
         {5,2,6,1},
         {1,2,3,4}}
    };

    cout << "========================================\n";
    cout << "      MIN FALLING PATH SUM TESTS         \n";
    cout << "========================================\n\n";

    for(int t = 0; t < testCases.size(); t++){
        auto matrix = testCases[t];
        cout << "Test Case " << t+1 << ":\nMatrix:\n";
        for(auto &row : matrix){
            for(auto val : row) cout << val << " ";
            cout << "\n";
        }

        int ans1 = minFallingPathSumTopDown(matrix);
        int ans2 = minFallingPathSumBottomUp(matrix);
        int ans3 = minFallingPathSumSpaceOpt(matrix);

        cout << "Top-Down DP: " << ans1 << "\n";
        cout << "Bottom-Up DP: " << ans2 << "\n";
        cout << "Space-Optimized DP: " << ans3 << "\n\n";
    }

    cout << "Complexities:\n";
    cout << "Top-Down: O(m*n) time, O(m*n) space (recursion + memo)\n";
    cout << "Bottom-Up: O(m*n) time, O(m*n) space\n";
    cout << "Space-Optimized: O(m*n) time, O(n) space\n";

    return 0;
}
