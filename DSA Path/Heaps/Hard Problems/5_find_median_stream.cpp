#include <bits/stdc++.h>
using namespace std;

/*
Intuition:
- We maintain two heaps:
  1. max_pq (max-heap): left half of numbers (smaller half).
  2. min_pq (min-heap): right half of numbers (larger half).
- Invariant:
  - All elements in max_pq <= all elements in min_pq.
  - The size difference between heaps is at most 1.
- Adding number:
  1. Always push into max_pq first.
  2. Move the largest from max_pq into min_pq (ensures order).
  3. If min_pq has more elements, rebalance by moving top back to max_pq.
- Median:
  - If heaps are equal size → average of tops.
  - Else → top of the bigger heap (max_pq will always be >= min_pq in size).
Time Complexity: O(log n) per insertion, O(1) for median query.
*/

class MedianFinder {
public:
    priority_queue<int> max_pq; // left half (largest at top)
    priority_queue<int, vector<int>, greater<int>> min_pq; // right half (smallest at top)

    MedianFinder() {}

    void addNum(int num) {
        // Step 1: Insert into left (max heap)
        max_pq.push(num);

        // Step 2: Maintain ordering -> move largest of left to right
        min_pq.push(max_pq.top());
        max_pq.pop();

        // Step 3: Balance -> left can have one more element than right
        if (min_pq.size() > max_pq.size()) {
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
    }

    double findMedian() {
        if (max_pq.size() > min_pq.size()) return max_pq.top();
        return (max_pq.top() + min_pq.top()) / 2.0;
    }
};

int main() {
    MedianFinder mf;

    // Testcase 1
    vector<int> nums1 = {5, 15, 1, 3};
    cout << "TC1 stream: ";
    for (int x : nums1) {
        mf.addNum(x);
        cout << mf.findMedian() << " ";
    }
    cout << "\n"; 
    // Expected: 5 10 5 4

    // Testcase 2
    MedianFinder mf2;
    vector<int> nums2 = {2, 4, 6, 8};
    cout << "TC2 stream: ";
    for (int x : nums2) {
        mf2.addNum(x);
        cout << mf2.findMedian() << " ";
    }
    cout << "\n";
    // Expected: 2 3 4 5

    // Testcase 3
    MedianFinder mf3;
    vector<int> nums3 = {1};
    cout << "TC3 stream: ";
    for (int x : nums3) {
        mf3.addNum(x);
        cout << mf3.findMedian() << " ";
    }
    cout << "\n";
    // Expected: 1

    // Testcase 4 (all same elements)
    MedianFinder mf4;
    vector<int> nums4 = {7, 7, 7, 7};
    cout << "TC4 stream: ";
    for (int x : nums4) {
        mf4.addNum(x);
        cout << mf4.findMedian() << " ";
    }
    cout << "\n";
    // Expected: 7 7 7 7
}
