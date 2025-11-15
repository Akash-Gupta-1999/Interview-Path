#include <bits/stdc++.h>
using namespace std;

/*
Intuition:
-----------
We use the same "patience sorting" idea as before, but now we also
track the *actual LIS sequence* using two helper arrays:
1. `parent[i]` — stores the index of the previous element in the LIS ending at `i`.
2. `lisIndices[len]` — stores the index of the smallest tail element of all
   increasing subsequences of length `len`.

For every element:
- If nums[i] > last element of LIS, extend LIS and record parent.
- Otherwise, use lower_bound to find where nums[i] fits and replace it
  (updating parent and lisIndices accordingly).

After processing all elements, reconstruct the LIS by backtracking
from the last index in the LIS using the `parent` array.

Why is this approach better?
----------------------------
- Recursion (exponential): O(2^N)
- DP (memo/tabulation):    O(N^2)
- **This approach:**        O(N log N) — best possible for LIS
- Space: O(N)

It gives BOTH the LIS length and the actual LIS sequence efficiently.
*/

vector<int> getLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};

    vector<int> dp;               // stores the LIS values (for binary search)
    vector<int> lisIndices;       // stores indices of elements in `dp`
    vector<int> parent(n, -1);    // to reconstruct the LIS

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();

        if (pos == dp.size()) {
            dp.push_back(nums[i]);
            lisIndices.push_back(i);
        } else {
            dp[pos] = nums[i];
            lisIndices[pos] = i;
        }

        if (pos > 0)
            parent[i] = lisIndices[pos - 1]; // link to previous element
    }

    // Reconstruct LIS from the last index
    vector<int> lis;
    int lastIndex = lisIndices.back();
    while (lastIndex != -1) {
        lis.push_back(nums[lastIndex]);
        lastIndex = parent[lastIndex];
    }
    reverse(lis.begin(), lis.end());
    return lis;
}

int main() {
    vector<vector<int>> testCases = {
        {10,9,2,5,3,7,101,18},   // Expected LIS: {2,3,7,101}
        {0,1,0,3,2,3},           // Expected LIS: {0,1,2,3}
        {7,7,7,7,7,7},           // Expected LIS: {7}
        {1,2,4,3},               // Expected LIS: {1,2,3}
        {3,10,2,1,20}            // Expected LIS: {3,10,20}
    };

    for (auto nums : testCases) {
        cout << "Array: ";
        for (int x : nums) cout << x << " ";
        cout << "\n";

        vector<int> lis = getLIS(nums);
        cout << "LIS: ";
        for (int x : lis) cout << x << " ";
        cout << "\nLength of LIS: " << lis.size() << "\n";
        cout << "------------------------------------\n";
    }

    return 0;
}
