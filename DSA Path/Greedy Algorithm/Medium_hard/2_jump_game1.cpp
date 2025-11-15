#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int maxReach = 0;  // farthest index we can reach

    // 🔹 Iterate through array
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) 
            return false;  // stuck before reaching i
        
        // Update farthest index reachable so far
        maxReach = max(maxReach, i + nums[i]);

        // If last index is within reach → done
        if (maxReach >= nums.size() - 1)
            return true;
    }
    return true;
}

/*
🔹 Intuition (Greedy):
- At every index, you know how far you can jump (nums[i]).
- Track the farthest index reachable so far (`maxReach`).
- If at any point current index > maxReach → you are stuck → return false.
- If `maxReach` ever reaches or crosses the last index → return true.
- Time: O(n), Space: O(1).
*/

int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << (canJump(nums1) ? "true" : "false") << endl;  // ✅ true (can reach end)

    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << (canJump(nums2) ? "true" : "false") << endl;  // ❌ false (stuck at 0)

    vector<int> nums3 = {0};
    cout << (canJump(nums3) ? "true" : "false") << endl;  // ✅ true (already at last index)

    vector<int> nums4 = {2, 0, 0};
    cout << (canJump(nums4) ? "true" : "false") << endl;  // ✅ true (2 can directly reach last)

    vector<int> nums5 = {1, 2, 0, 1, 0, 2, 1};
    cout << (canJump(nums5) ? "true" : "false") << endl;  // ✅ true (can maneuver around zeros)

    return 0;
}
