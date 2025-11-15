#include <bits/stdc++.h>
using namespace std;

/*
Intuition:
-----------
- dp[i] = length of LIS ending at index i
- count[i] = number of LIS ending at index i
- Transition:
    For each j < i:
        if nums[i] > nums[j]:
            if dp[i] < dp[j] + 1 -> dp[i] = dp[j]+1, count[i] = count[j]
            else if dp[i] == dp[j] + 1 -> count[i] += count[j]
- Finally, sum count[i] for all i where dp[i] == maximum length.

Time Complexity:  O(N^2)
Space Complexity: O(N)
*/

int findNumberOfLIS(vector<int>& nums){
    int n = nums.size();
    if(n == 0) return 0;

    vector<int> dp(n,1);     // Length of LIS ending at i
    vector<int> count(n,1);  // Number of LIS ending at i
    int maxi = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if(dp[i] == dp[j] + 1){
                    count[i] += count[j];
                }
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] == maxi) ans += count[i];
    }
    return ans;
}

int main(){
    vector<vector<int>> testCases = {
        {1,3,5,4,7},          // Expected: 2 ([1,3,4,7] and [1,3,5,7])
        {2,2,2,2,2},          // Expected: 5 (each 2 individually)
        {1,2,4,3,5,4,7,2},    // Expected: 3
        {1,2,3,4,5},          // Expected: 1
        {1,3,2,4,3,5,4,6}     // Expected: 5
    };

    for(auto nums : testCases){
        cout << "Array: ";
        for(auto &x : nums) cout << x << " ";
        cout << "\nNumber of Longest Increasing Subsequences: " 
             << findNumberOfLIS(nums) << "\n";
        cout << "-------------------------------------\n";
    }

    return 0;
}
