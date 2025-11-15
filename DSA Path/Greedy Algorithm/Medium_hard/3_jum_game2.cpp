#include <bits/stdc++.h>
using namespace std;

// Jump Game II: Minimum number of jumps to reach the last index
int jump(vector<int>& nums) {
    if (nums.size() == 1) return 0; // already at last index

    int jumps = 0;
    int currentEnd = 0;   // boundary of current jump
    int farthest = 0;     // farthest index reachable in this range

    for (int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);

        // When we reach the end of the current jump range → must jump
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
            if (currentEnd >= nums.size() - 1) 
                break;  // already can reach last index
        }
    }
    return jumps;
}

/*
🔹 Intuition (Greedy, BFS-like):
- Traverse array while tracking:
   - farthest = farthest index reachable so far
   - currentEnd = boundary of current jump
- Each time i reaches currentEnd → we need a new jump.
- Expand currentEnd to farthest, repeat until last index is covered.
- Time: O(n), Space: O(1).
*/

int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Minimum jumps: " << jump(nums1) << endl;  // 2 (0->1->4)

    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Minimum jumps: " << jump(nums2) << endl;  // 2 (0->1->4)

    vector<int> nums3 = {1, 2, 1, 1, 1};
    cout << "Minimum jumps: " << jump(nums3) << endl;  // 3 (0->1->3->4)

    vector<int> nums4 = {0};
    cout << "Minimum jumps: " << jump(nums4) << endl;  // 0 (already at last)

    return 0;
}
