#include <bits/stdc++.h>
using namespace std;

// ========================
// Approach 1: Top-Down DP
// ========================
int topdown(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
    if(dp[i][j] != INT_MAX) return dp[i][j];
    if(i == triangle.size() - 1) return triangle[i][j];
    return dp[i][j] = triangle[i][j] + min(topdown(i + 1, j, triangle, dp),
                                          topdown(i + 1, j + 1, triangle, dp));
}

int minimumTotalTopDown(vector<vector<int>>& triangle){
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    return topdown(0, 0, triangle, dp);
}

// ========================
// Approach 2: Bottom-Up DP
// ========================
int minimumTotalBottomUp(vector<vector<int>>& triangle){
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Initialize last row
    for(int j = 0; j < n; j++) dp[n-1][j] = triangle[n-1][j];
    
    // Bottom-up computation
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    return dp[0][0];
}

// ========================
// Approach 3: Space-Optimized Bottom-Up
// ========================
int minimumTotalSpaceOpt(vector<vector<int>>& triangle){
    int n = triangle.size();
    vector<int> next(triangle.back());
    
    for(int i = n-2; i >= 0; i--){
        vector<int> curr(i+1);
        for(int j = 0; j <= i; j++){
            curr[j] = triangle[i][j] + min(next[j], next[j+1]);
        }
        next = curr;
    }
    return next[0];
}

// ========================
// Main Function with Test Cases
// ========================
int main(){
    vector<vector<vector<int>>> testCases = {
        {{2},
         {3,4},
         {6,5,7},
         {4,1,8,3}},
        
        {{-10}},
        
        {{1},
         {2,3}},
        
        {{1},
         {2,3},
         {3,6,7}}
    };
    
    cout << "========================================\n";
    cout << "        TRIANGLE MIN PATH SUM TESTS      \n";
    cout << "========================================\n\n";
    
    for(int t = 0; t < testCases.size(); t++){
        auto triangle = testCases[t];
        cout << "Test Case " << t+1 << ":\nTriangle:\n";
        for(auto &row : triangle){
            for(auto val : row) cout << val << " ";
            cout << "\n";
        }
        
        int ans1 = minimumTotalTopDown(triangle);
        int ans2 = minimumTotalBottomUp(triangle);
        int ans3 = minimumTotalSpaceOpt(triangle);
        
        cout << "Top-Down DP: " << ans1 << "\n";
        cout << "Bottom-Up DP: " << ans2 << "\n";
        cout << "Space-Optimized DP: " << ans3 << "\n\n";
    }
    
    cout << "Complexities:\n";
    cout << "Top-Down: O(n^2) time, O(n^2) space (recursion + memo)\n";
    cout << "Bottom-Up: O(n^2) time, O(n^2) space\n";
    cout << "Space-Optimized: O(n^2) time, O(n) space\n";
    
    return 0;
}
