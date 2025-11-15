#include <bits/stdc++.h>
using namespace std;

// Partition function (Lomuto partition but modified for kth largest)
int partition(vector<int>& nums, int low, int high) {
    int pivotVal = nums[high]; // choose last element as pivot
    int storeIdx = low;
    for (int i = low; i < high; i++) {
        if (nums[i] > pivotVal) { // ">" ensures larger elements go left
            swap(nums[i], nums[storeIdx]);
            storeIdx++;
        }
    }
    swap(nums[storeIdx], nums[high]);
    return storeIdx;
}

// Quickselect algorithm
int quickselect(vector<int>& nums, int low, int high, int k) {
    while (low <= high) {
        int pivotIdx = partition(nums, low, high);
        if (pivotIdx == k - 1) {
            return nums[pivotIdx];
        } else if (pivotIdx > k - 1) {
            high = pivotIdx - 1;
        } else {
            low = pivotIdx + 1;
        }
    }
    return -1; // should never hit if k is valid
}

int findKthLargest(vector<int>& nums, int k) {
    return quickselect(nums, 0, nums.size() - 1, k);
}

int main() {
    vector<pair<vector<int>, int>> testcases = {
        {{3, 2, 1, 5, 6, 4}, 2},         // 2nd largest = 5
        {{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4},// 4th largest = 4
        {{10, 7, 11, 5, 8}, 3},          // 3rd largest = 8
        {{1}, 1},                        // only element = 1
        {{9, 8, 7, 6, 5}, 5}             // 5th largest = 5
    };

    for (int i = 0; i < testcases.size(); i++) {
        auto nums = testcases[i].first;
        int k = testcases[i].second;

        cout << "Testcase " << i+1 << ": nums = [ ";
        for (int x : nums) cout << x << " ";
        cout << "], k = " << k << "\n";

        cout << "  Quickselect: " << findKthLargest(nums, k) << "\n\n";
    }

    return 0;
}
