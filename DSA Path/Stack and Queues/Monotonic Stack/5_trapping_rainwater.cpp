#include <bits/stdc++.h>
using namespace std;

// ---------------------
// Method 1: Prefix & Suffix Max Arrays (O(n) space)
// ---------------------
int trapWithSuffix(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> leftMax(n), rightMax(n);

    // leftMax[i] = tallest bar on the left (including current)
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i - 1], height[i]);

    // rightMax[i] = tallest bar on the right (including current)
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rightMax[i] = max(rightMax[i + 1], height[i]);

    // water[i] = min(leftMax[i], rightMax[i]) - height[i]
    int water = 0;
    for (int i = 0; i < n; i++)
        water += min(leftMax[i], rightMax[i]) - height[i];

    return water;
}

// ---------------------
// Method 2: Two Pointer Approach (O(1) space – Optimal)
// ---------------------
int trapTwoPointer(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0, water = 0;

    // Key idea:
    // Water depends on the shorter boundary side.
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left];  // update left boundary
            else
                water += leftMax - height[left]; // trapped water
            left++;
        } else {
            if (height[right] >= rightMax)
                rightMax = height[right]; // update right boundary
            else
                water += rightMax - height[right]; // trapped water
            right--;
        }
    }
    return water;
}

// ---------------------
// Main function with test cases
// ---------------------
int main() {
    vector<int> height = {4,2,0,3,2,5};

    cout << "Using Prefix & Suffix Max Arrays (O(n) space): "
         << trapWithSuffix(height) << endl;

    cout << "Using Two Pointer Approach (O(1) space): "
         << trapTwoPointer(height) << endl;

    return 0;
}
