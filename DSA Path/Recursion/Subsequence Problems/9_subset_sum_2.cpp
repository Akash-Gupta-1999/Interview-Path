#include <bits/stdc++.h>
using namespace std;

void rec_subset(int idx, vector<int>& nums, vector<vector<int>>& res, vector<int>& curr) {
    res.push_back(curr);
    for (int i = idx; i < nums.size(); i++) {
        if (i > idx && nums[i] == nums[i - 1]) continue; // skip duplicates
        curr.push_back(nums[i]);
        rec_subset(i + 1, nums, res, curr);
        curr.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> curr;
    sort(nums.begin(), nums.end());
    rec_subset(0, nums, res, curr);
    return res;
}

void printResult(const vector<vector<int>>& subsets) {
    cout << "[\n";
    for (auto &subset : subsets) {
        cout << "  [";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    cout << "]\n";
}

int main() {
    vector<vector<int>> testCases = {
        {},             // Empty input
        {1},            // Single element
        {1, 2, 2},      // Contains duplicates
        {1, 1, 1},      // All elements same
        {4, 4, 4, 1, 4} // Many duplicates
    };

    vector<int> targets; // Not needed here but for structure

    for (auto nums : testCases) {
        cout << "Input: ";
        for (auto x : nums) cout << x << " ";
        cout << "\nOutput:\n";
        auto subsets = subsetsWithDup(nums);
        printResult(subsets);
        cout << "-----------------------------\n";
    }

    return 0;
}
