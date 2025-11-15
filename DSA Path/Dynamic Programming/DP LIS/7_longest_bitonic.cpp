#include <bits/stdc++.h>
using namespace std;

/*
Intuition:
-----------
Longest Bitonic Subsequence = first increasing, then decreasing.
- Compute LIS ending at each index (from left) using DP.
- Compute LDS starting at each index (from right) using DP.
- LBS length at i = LIS[i] + LDS[i] - 1.

Time Complexity:  O(N^2)
Space Complexity: O(N)
*/

// Function to compute LIS ending at each index (same style as previous code)
vector<int> getLIS(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n, 1);  // dp[i] = LIS ending at i
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
    }
    return dp;
}

// Function to compute LDS starting at each index (same style as previous code)
vector<int> getLDS(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n, 1);  // dp[i] = LDS starting at i
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j > i; j--){
            if(nums[i] > nums[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
    }
    return dp;
}

// Function to compute length of Longest Bitonic Subsequence
int longestBitonicSubsequence(vector<int>& nums){
    int n = nums.size();
    if(n == 0) return 0;

    vector<int> lis = getLIS(nums);
    vector<int> lds = getLDS(nums);

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, lis[i] + lds[i] - 1); // subtract 1 because nums[i] counted twice
    }
    return ans;
}

int main(){
    vector<vector<int>> testCases = {
        {1, 11, 2, 10, 4, 5, 2, 1},  // Expected: 6
        {12, 11, 40, 5, 3, 1},       // Expected: 5
        {80, 60, 30, 40, 20, 10},    // Expected: 5
        {1, 3, 5, 4, 2},             // Expected: 5
        {1, 2, 3, 4, 5}              // Expected: 5
    };

    for(auto nums : testCases){
        cout << "Array: ";
        for(auto &x : nums) cout << x << " ";
        cout << "\nLongest Bitonic Subsequence Length: " 
             << longestBitonicSubsequence(nums) << "\n";
        cout << "-------------------------------------\n";
    }

    return 0;
}
