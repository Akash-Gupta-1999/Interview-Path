#include <bits/stdc++.h>
using namespace std;

/*
-----------------------------------------------------
 Method 1: Using 'sum' as the running total
 Time Complexity: O(2^9) = O(512) in worst case 
   - We have at most 9 numbers (1 to 9) to choose from, 
     each number can be taken or not taken (subset generation).
 Space Complexity: O(k) for recursion stack + O(#solutions * k) for storing results.
-----------------------------------------------------
*/
void rec_sum_sumVar(int i, int sum, vector<int>& nums, vector<vector<int>>& res, vector<int> curr, int k, int n) {
    if (curr.size() == k && sum == n) { // Corrected to check exactly k elements
        res.push_back(curr);
        return;
    }
    if (curr.size() >= k || sum > n || i >= nums.size())
        return;

    // Include nums[i]
    curr.push_back(nums[i]);
    rec_sum_sumVar(i + 1, sum + nums[i], nums, res, curr, k, n);
    curr.pop_back();

    // Exclude nums[i]
    rec_sum_sumVar(i + 1, sum, nums, res, curr, k, n);
}

vector<vector<int>> combinationSum3_sumVar(int k, int n) {
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> res;
    rec_sum_sumVar(0, 0, nums, res, {}, k, n);
    return res;
}

/*
-----------------------------------------------------
 Method 2: Using 'n' as the running total (sum renamed to n)
 Time Complexity: Same as Method 1 → O(2^9)
 Space Complexity: Same as Method 1 → O(k + #solutions * k)
-----------------------------------------------------
*/
void rec_sum_nVar(int i, int n, vector<int>& nums, vector<vector<int>>& res, vector<int> curr, int k, int target) {
    if (curr.size() == k && n == target) {
        res.push_back(curr);
        return;
    }
    if (curr.size() >= k || n > target || i >= nums.size())
        return;

    // Include nums[i]
    curr.push_back(nums[i]);
    rec_sum_nVar(i + 1, n + nums[i], nums, res, curr, k, target);
    curr.pop_back();

    // Exclude nums[i]
    rec_sum_nVar(i + 1, n, nums, res, curr, k, target);
}

vector<vector<int>> combinationSum3_nVar(int k, int target) {
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> res;
    rec_sum_nVar(0, 0, nums, res, {}, k, target);
    return res;
}

int main() {
    int k = 3, target = 7;

    cout << "=== Method 1 (sum) ===\n";
    auto ans1 = combinationSum3_sumVar(k, target);
    for (auto &vec : ans1) {
        for (int x : vec) cout << x << " ";
        cout << "\n";
    }

    cout << "\n=== Method 2 (n) ===\n";
    auto ans2 = combinationSum3_nVar(k, target);
    for (auto &vec : ans2) {
        for (int x : vec) cout << x << " ";
        cout << "\n";
    }
}
