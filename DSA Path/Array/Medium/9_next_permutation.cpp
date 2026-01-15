#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Step 1: find break point
    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;

    // Step 2: find just larger element
    if (i >= 0) {
        int j = n - 1;
        while (nums[j] <= nums[i])
            j--;
        swap(nums[i], nums[j]);
    }

    // Step 3: reverse suffix
    reverse(nums.begin() + i + 1, nums.end());
}

int main()
{
    vector<int> ans = {2, 1, 5, 4, 3, 0, 0};
    nextPermutation(ans);

    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "]n";
    return 0;
}