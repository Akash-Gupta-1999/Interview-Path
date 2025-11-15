#include <bits/stdc++.h>
using namespace std;

// Function to return the Longest Increasing Subsequence (LIS) as a vector
vector<int> getLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};

    vector<int> dp(n, 1), parent(n);
    int maxLen = 1, lastIndex = 0;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && dp[i] < 1 + dp[j]) {
                dp[i] = 1 + dp[j];
                parent[i] = j;
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            lastIndex = i;
        }
    }

    // Reconstruct LIS
    vector<int> lis;
    while (parent[lastIndex] != lastIndex) {
        lis.push_back(nums[lastIndex]);
        lastIndex = parent[lastIndex];
    }
    lis.push_back(nums[lastIndex]);
    reverse(lis.begin(), lis.end());
    return lis;
}

int main() {
    vector<vector<int>> testCases = {
        {10,9,2,5,3,7,101,18},   // Expected: {2,3,7,101}
        {0,1,0,3,2,3},           // Expected: {0,1,2,3}
        {7,7,7,7,7,7},           // Expected: {7}
        {1,2,4,3},               // Expected: {1,2,3}
        {3,10,2,1,20}            // Expected: {3,10,20}
    };

    for (auto nums : testCases) {
        cout << "Array: ";
        for (int x : nums) cout << x << " ";
        cout << "\n";

        vector<int> lis = getLIS(nums);
        cout << "LIS: ";
        if (lis.empty()) cout << "[]";
        else {
            for (int x : lis) cout << x << " ";
        }
        cout << "\n------------------------------------\n";
    }

    return 0;
}
