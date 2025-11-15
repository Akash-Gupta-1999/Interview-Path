#include <bits/stdc++.h>
using namespace std;

bool countSubsequencesWithSumK(int i, int sum, vector<int>& nums, int k) {
    if (i == nums.size()) {
        return sum == k;
    }
    // Include current element
    if (countSubsequencesWithSumK(i + 1, sum + nums[i], nums, k))
        return true;
    // Exclude current element
    if (countSubsequencesWithSumK(i + 1, sum, nums, k))
        return true;
    
    return false;
}

int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 1}, 3},        // true  ({1,2} or {2,1})
        {{1, 2, 3}, 3},        // true  ({1,2} or {3})
        {{1, 1, 1}, 2},        // true  ({1,1})
        {{2, 4, 6, 10}, 16},   // true  ({6,10} or {2,4,10})
        {{}, 0},               // true  (empty subsequence)
        {{1, -1, 2, -2}, 0},   // true  (several possible)

        // ❌ False cases
        {{1, 2, 5}, 10},       // false (max sum is 8)
        {{-1, -2, -3}, 5},     // false (max sum is negative)
        {{2, 4, 6}, 5},        // false (all sums are even)
        {{100}, 50},           // false (only one element, not matching)
        {{}, 5}                // false (empty array, k != 0)
    };

    for (int i = 0; i < testCases.size(); i++) {
        auto nums = testCases[i].first;
        int k = testCases[i].second;

        cout << "Test case " << i + 1 << ": ";
        cout << "Array = { ";
        for (auto x : nums) cout << x << " ";
        cout << "}, k = " << k << "\n";

        bool result = countSubsequencesWithSumK(0, 0, nums, k);
        cout << "Result: " << (result ? "true" : "false") << "\n\n";
    }

    return 0;
}
