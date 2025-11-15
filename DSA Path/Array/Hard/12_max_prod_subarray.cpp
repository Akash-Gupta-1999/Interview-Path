#include <bits/stdc++.h>
using namespace std;

int maxProduct_dp(vector<int>& nums) {
    int curr_max = nums[0], curr_min = nums[0], max_prod = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] < 0) swap(curr_max, curr_min);   // 👈 Step 1
        curr_max = max(nums[i], curr_max * nums[i]); // 👈 Step 2
        curr_min = min(nums[i], curr_min * nums[i]); // 👈 Step 3
        max_prod = max(max_prod, curr_max);          // 👈 Step 4
    }
    return max_prod;
}

int maxProductSubArray(vector<int> &arr) {
    int n = arr.size(); //size of array.

    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray is: "
         << maxProductSubArray(arr) << "\n";
    cout << "The maximum product subarray is: "
         << maxProduct_dp(arr) << "\n";
    return 0;
}
