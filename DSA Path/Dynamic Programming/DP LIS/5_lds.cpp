#include <bits/stdc++.h>
using namespace std;

/*
Intuition:
-----------
We want the largest subset of numbers such that for every pair (a, b),
either a % b == 0 or b % a == 0.

This problem is similar to LIS (Longest Increasing Subsequence):
- Sort the array first → ensures if nums[i] % nums[j] == 0, then nums[i] >= nums[j].
- dp[i] → length of the largest divisible subset ending at i.
- parent[i] → to reconstruct the actual subset.

Transition:
------------
For each pair (j < i):
    if nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1
        dp[i] = dp[j] + 1
        parent[i] = j

Finally, backtrack from the index having the maximum dp[i] to reconstruct the subset.

Complexity:
------------
Time:  O(N²)
Space: O(N)

This is optimal for this problem since divisibility requires pairwise checking.
*/

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};

    sort(nums.begin(), nums.end());
    vector<int> dp(n, 1), parent(n);

    int maxi = 1, max_idx = 0;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]) {
                dp[i] = 1 + dp[j];
                parent[i] = j;
            }
        }
        if (dp[i] > maxi) {
            maxi = dp[i];
            max_idx = i;
        }
    }

    // Reconstruct the subset
    vector<int> lds;
    int i = max_idx;
    while (parent[i] != i) {
        lds.push_back(nums[i]);
        i = parent[i];
    }
    lds.push_back(nums[i]);
    reverse(lds.begin(), lds.end());

    return lds;
}

int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3},              // Expected: [1, 2] or [1, 3]
        {1, 2, 4, 8},           // Expected: [1, 2, 4, 8]
        {3, 4, 16, 8},          // Expected: [4, 8, 16]
        {1, 3, 6, 24},          // Expected: [1, 3, 6, 24]
        {2, 3, 4, 9, 8}         // Expected: [2, 4, 8]
    };

    for (auto nums : testCases) {
        cout << "Array: ";
        for (int x : nums) cout << x << " ";
        cout << "\nLargest Divisible Subset: ";
        vector<int> res = largestDivisibleSubset(nums);
        for (int x : res) cout << x << " ";
        cout << "\nLength: " << res.size() << "\n";
        cout << "------------------------------------\n";
    }

    return 0;
}
