#include <bits/stdc++.h>
using namespace std;

// Helper function: count subarrays with at most K distinct numbers
int atMost(vector<int>& nums, int K) {
    unordered_map<int,int> freq;
    int left = 0, ans = 0;

    for(int right = 0; right < nums.size(); right++) {
        freq[nums[right]]++;

        // shrink window if distinct > K
        while(freq.size() > K) {
            freq[nums[left]]--;
            if(freq[nums[left]] == 0)
                freq.erase(nums[left]);
            left++;
        }

        // all subarrays ending at `right` are valid
        ans += (right - left + 1);
    }
    return ans;
}

int subarraysWithKDistinct(vector<int>& nums, int K) {
    return atMost(nums, K) - atMost(nums, K - 1);
}

int main() {
    vector<int> nums1 = {1,2,1,2,3};
    cout << "Test1: " << subarraysWithKDistinct(nums1, 2) << " (Expected 7)\n";

    vector<int> nums2 = {1,2,1,3,4};
    cout << "Test2: " << subarraysWithKDistinct(nums2, 3) << " (Expected 3)\n";

    vector<int> nums3 = {1,2,1,2,1};
    cout << "Test3: " << subarraysWithKDistinct(nums3, 2) << " (Expected 7)\n";

    vector<int> nums4 = {1,2,3,4,5};
    cout << "Test4: " << subarraysWithKDistinct(nums4, 1) << " (Expected 5)\n";

    vector<int> nums5 = {1,2,3,4,5};
    cout << "Test5: " << subarraysWithKDistinct(nums5, 2) << " (Expected 4)\n";

    return 0;
}
