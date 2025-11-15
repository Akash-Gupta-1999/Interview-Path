#include <bits/stdc++.h>
using namespace std;

// Helper: counts subarrays with sum <= goal
int atMost(vector<int>& nums, int goal) {
    if (goal < 0) return 0; // no valid subarray if goal < 0

    int left = 0, sum = 0, ans = 0;

    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right]; // expand window by including nums[right]

        // shrink window if sum exceeds goal
        // (only possible because nums[i] are 0 or 1)
        while (sum > goal) {
            sum -= nums[left++];
        }

        // all subarrays ending at `right` and starting from [left..right]
        // are valid because sum <= goal
        ans += (right - left + 1);
    }

    return ans;
}

// Main function: exact sum = atMost(goal) - atMost(goal-1)
int numSubarraysWithSum(vector<int>& nums, int goal) {
    return atMost(nums, goal) - atMost(nums, goal - 1);
}

int main() {
    vector<int> nums1 = {1,0,1,0,1};
    int goal1 = 2;
    cout << "Test1: " << numSubarraysWithSum(nums1, goal1) << "\n"; // expected 4

    vector<int> nums2 = {0,0,0,0,0};
    int goal2 = 0;
    cout << "Test2: " << numSubarraysWithSum(nums2, goal2) << "\n"; // expected 15

    vector<int> nums3 = {1,1,1};
    int goal3 = 2;
    cout << "Test3: " << numSubarraysWithSum(nums3, goal3) << "\n"; // expected 2

    vector<int> nums4 = {1,0,1,1,0,1};
    int goal4 = 3;
    cout << "Test4: " << numSubarraysWithSum(nums4, goal4) << "\n"; // expected 4

    return 0;
}
