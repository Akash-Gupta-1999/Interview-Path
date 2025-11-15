#include <bits/stdc++.h>
using namespace std;

// Helper: counts subarrays with at most k odd numbers
int atmost(vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0, count = 0, ans = 0;

    for (int r = 0; r < n; r++) {
        // expand window
        if (nums[r] % 2 != 0)
            count++;  // one more odd

        // shrink window if we have more than k odds
        while (count > k) {
            if (nums[left] % 2 != 0)
                count--;  // removing one odd
            left++;
        }

        // all subarrays ending at r and starting in [left..r] are valid
        ans += (r - left + 1);
    }
    return ans;
}

// main function: exactly k odds = atMost(k) - atMost(k-1)
int numberOfSubarrays(vector<int>& nums, int k) {
    return atmost(nums, k) - atmost(nums, k - 1);
}

int main() {
    vector<int> nums1 = {1,1,2,1,1};
    int k1 = 3;
    cout << "Test1: " << numberOfSubarrays(nums1, k1) << "\n"; // expected 2

    vector<int> nums2 = {2,4,6};
    int k2 = 1;
    cout << "Test2: " << numberOfSubarrays(nums2, k2) << "\n"; // expected 0

    vector<int> nums3 = {2,2,2,1,2,2,1,2,2,2};
    int k3 = 2;
    cout << "Test3: " << numberOfSubarrays(nums3, k3) << "\n"; // expected 16

    return 0;
}
