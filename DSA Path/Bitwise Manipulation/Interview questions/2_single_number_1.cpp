#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++)
        ans ^= nums[i];
    return ans;
}

int main() {
    vector<vector<int>> tests = {
        {2, 2, 1},
        {4, 1, 2, 1, 2},
        {1},
        {7, 3, 7, 5, 3}
    };

    for (auto &nums : tests) {
        cout << "singleNumber([ ";
        for (int x : nums) cout << x << " ";
        cout << "]) = " << singleNumber(nums) << "\n";
    }

    return 0;
}
