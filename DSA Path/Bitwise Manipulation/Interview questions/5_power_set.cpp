#include <bits/stdc++.h>
using namespace std;

/*
   Problem: Generate all subsets (the power set)

   Intuition:
   ----------
   - For a set of size n, there are 2^n subsets.
   - Each subset can be represented by a binary number from 0 to (2^n - 1).
       Example: nums = [1,2,3]
         Binary 000 -> {}
         Binary 001 -> {1}
         Binary 010 -> {2}
         Binary 011 -> {1,2}
         Binary 100 -> {3}
         Binary 101 -> {1,3}
         Binary 110 -> {2,3}
         Binary 111 -> {1,2,3}

   - At each bit i:
         - If the bit is set, include nums[i] in the current subset.
         - Otherwise, skip nums[i].

   Efficiency:
   ------------
   - Time: O(n * 2^n)
        -> because we loop over 2^n subsets,
           and for each subset we scan n bits.
   - Space: O(n * 2^n) to store all subsets.
   - This is OPTIMAL since the output itself has size O(n * 2^n).
*/

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int subsets = 1 << n;  // total number of subsets = 2^n
    vector<vector<int>> ans;

    for (int mask = 0; mask < subsets; mask++) {
        vector<int> list;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                list.push_back(nums[i]);
            }
        }
        ans.push_back(list);
    }
    return ans;
}

int main() {
    vector<vector<int>> testcases = {
        {1, 2, 3},
        {0},
        {5, 6},
        {},
        {1, 2, 3, 4}
    };

    for (auto& nums : testcases) {
        cout << "Input: ";
        for (int n : nums) cout << n << " ";
        cout << "\nSubsets:\n";

        vector<vector<int>> result = subsets(nums);
        for (auto& subset : result) {
            cout << "{";
            for (int i = 0; i < subset.size(); i++) {
                cout << subset[i] << (i + 1 < subset.size() ? "," : "");
            }
            cout << "} ";
        }
        cout << "\n\n";
    }

    return 0;
}
