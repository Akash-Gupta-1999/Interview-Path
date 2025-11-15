#include <bits/stdc++.h>
using namespace std;

/*
Intuition:
-----------
This approach uses the concept of "patience sorting" to find the
length of the Longest Increasing Subsequence (LIS) in O(N log N).

We maintain a temporary array `temp` where:
- Each element at index `i` represents the smallest possible tail
  value of an increasing subsequence of length `i+1`.

Steps:
1. Initialize `temp` with the first element.
2. For every new element `nums[i]`:
   - If it's greater than `temp.back()`, we can extend the LIS.
   - Otherwise, find the first element in `temp` that is >= `nums[i]`
     using binary search (lower_bound) and replace it.
     (This keeps `temp` as lexicographically small as possible.)

Note:
`temp` does NOT store the actual LIS — it only helps determine its length.
To reconstruct the LIS, we’d need to track predecessors separately.

Why is this approach better?
----------------------------
- Brute force recursion:     O(2^N)
- Memoized recursion (DP):   O(N^2)
- Tabulation (Bottom-up DP): O(N^2)
- **This (Patience Sorting): O(N log N)** → much faster for large arrays.

Space Complexity: O(N)
Time Complexity:  O(N log N)
*/

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> temp;
    temp.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (nums[i] > temp.back()) {
            // Extend the increasing subsequence
            temp.push_back(nums[i]);
        } else {
            // Replace the first element >= nums[i] to maintain minimal tails
            int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[idx] = nums[i];
        }
    }

    return temp.size();
}

int main() {
    vector<vector<int>> testCases = {
        {10,9,2,5,3,7,101,18},  // LIS length = 4 -> {2,3,7,101}
        {0,1,0,3,2,3},          // LIS length = 4 -> {0,1,2,3}
        {7,7,7,7,7,7},          // LIS length = 1 -> {7}
        {1,2,4,3},              // LIS length = 3 -> {1,2,3}
        {3,10,2,1,20}           // LIS length = 3 -> {3,10,20}
    };

    for (auto nums : testCases) {
        cout << "Array: ";
        for (int x : nums) cout << x << " ";
        cout << "\n";

        cout << "Length of LIS: " << lengthOfLIS(nums) << "\n";
        cout << "------------------------------------\n";
    }

    return 0;
}
