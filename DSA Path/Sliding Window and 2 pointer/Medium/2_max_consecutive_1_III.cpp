#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int left = 0, zeros = 0, ans = 0;

    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) zeros++;

        // shrink window until we have at most k zeros
        while (zeros > k) {
            if (nums[left] == 0) zeros--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}

int main() {
    vector<int> nums1 = {1,1,1,0,0,0,1,1,1,1,0};
    cout << longestOnes(nums1, 2) << "\n"; // expected 6

    vector<int> nums2 = {0,0,1,1,1,0,0};
    cout << longestOnes(nums2, 0) << "\n"; // expected 3

    vector<int> nums3 = {1,1,1,1,1};
    cout << longestOnes(nums3, 2) << "\n"; // expected 5

    vector<int> nums4 = {0,0,0,0};
    cout << longestOnes(nums4, 2) << "\n"; // expected 2

    vector<int> nums5 = {1,0,1,0,1,0,1};
    cout << longestOnes(nums5, 1) << "\n"; // expected 3

    return 0;
}
