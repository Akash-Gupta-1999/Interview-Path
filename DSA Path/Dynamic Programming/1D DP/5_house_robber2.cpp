#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Problem: House Robber II (circular houses)
// ============================================================
// Idea:
//   - Since first and last houses are adjacent, we cannot rob both.
//   - So we consider two cases:
//        1) Rob houses [0 ... n-2]
//        2) Rob houses [1 ... n-1]
//   - Take the maximum of both.
// ============================================================

// Helper function to solve the linear (non-circular) version
int solve(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    if (n == 1) return arr[0];
    if (n == 2) return max(arr[0], arr[1]);

    int prev2 = arr[0];
    int prev = max(arr[0], arr[1]);
    int curr;

    for (int i = 2; i < n; i++) {
        curr = max(arr[i] + prev2, prev);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

// Main function for House Robber II
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> arr0, arr1;
    for (int i = 0; i < n; i++) {
        if (i != 0) arr0.push_back(nums[i]);     // exclude first house
        if (i != n - 1) arr1.push_back(nums[i]); // exclude last house
    }

    int ans1 = solve(arr0);
    int ans2 = solve(arr1);

    return max(ans1, ans2);
}

// ============================================================
// Main with Multiple Test Cases
// ============================================================
int main() {
    vector<vector<int>> testCases = {
        {2, 3, 2},
        {1, 2, 3, 1},
        {1, 2, 3},
        {5, 1, 1, 5},
        {4, 4, 4, 4},
        {10}
    };

    cout << "==============================================\n";
    cout << "          HOUSE ROBBER II (CIRCULAR)          \n";
    cout << "==============================================\n";

    for (int t = 0; t < testCases.size(); t++) {
        auto nums = testCases[t];
        cout << "\nTest Case " << t + 1 << ": ";
        for (int x : nums) cout << x << " ";
        cout << "\n----------------------------------------------\n";
        cout << "Max amount that can be robbed: " << rob(nums) << "\n";
    }

    cout << "\n==============================================\n";
    cout << "Complexity: O(n) Time | O(1) Space\n";
    cout << "==============================================\n";

    return 0;
}
