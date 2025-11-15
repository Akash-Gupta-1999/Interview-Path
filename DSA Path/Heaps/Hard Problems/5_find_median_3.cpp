#include <bits/stdc++.h>
using namespace std;

/*
Hybrid MedianFinder:
- 99% numbers in [0..100] → store counts in a fixed-size freq array.
- Outliers (<0 or >100) → stored in heaps.
- To find median:
  1. If median lies within [0..100], compute using freq[] scan.
  2. Else, fall back to heaps.
*/

class MedianFinder {
    vector<int> freq;     // frequency of numbers in [0..100]
    int count_in_range;   // how many numbers are in [0..100]
    int total_count;      // total numbers inserted

    priority_queue<int> left_heap; // max-heap for numbers <0
    priority_queue<int, vector<int>, greater<int>> right_heap; // min-heap for numbers >100

public:
    MedianFinder() : freq(101, 0), count_in_range(0), total_count(0) {}

    void addNum(int num) {
        if (0 <= num && num <= 100) {
            freq[num]++;
            count_in_range++;
        } else if (num < 0) {
            left_heap.push(num);
        } else {
            right_heap.push(num);
        }
        total_count++;
    }

    double findMedian() {
        int mid1 = (total_count + 1) / 2;
        int mid2 = (total_count % 2 == 0) ? (total_count / 2 + 1) : mid1;

        // Step 1: handle numbers in range [0..100] via freq array
        int c = left_heap.size(); // elements before range
        int num1 = -1, num2 = -1;

        // First, check if median lies in left_heap
        if (mid2 <= c) {
            // Both medians are inside left_heap
            vector<int> temp;
            int needed = c - mid2 + 1; // position from top
            int val1, val2;
            for (int i = 0; i < needed; i++) {
                temp.push_back(left_heap.top());
                left_heap.pop();
            }
            val1 = left_heap.top();
            val2 = (mid1 == mid2) ? val1 : temp.back();
            for (int x : temp) left_heap.push(x);
            return (val1 + val2) / 2.0;
        }

        // Step 2: check if median lies in [0..100]
        c = left_heap.size();
        for (int i = 0; i <= 100; i++) {
            c += freq[i];
            if (num1 == -1 && c >= mid1) num1 = i;
            if (num2 == -1 && c >= mid2) {
                num2 = i;
                break;
            }
        }
        if (num1 != -1 && num2 != -1) return (num1 + num2) / 2.0;

        // Step 3: otherwise, median lies in right_heap
        c = left_heap.size() + count_in_range;
        int needed = mid2 - c; // index inside right_heap
        vector<int> temp;
        int val1, val2;
        for (int i = 0; i < needed; i++) {
            temp.push_back(right_heap.top());
            right_heap.pop();
        }
        val2 = right_heap.top();
        val1 = (mid1 == mid2) ? val2 : temp.back();
        for (int x : temp) right_heap.push(x);
        return (val1 + val2) / 2.0;
    }
};

int main() {
    MedianFinder mf;

    // Mostly inside [0..100]
    vector<int> nums1 = {5, 15, 1, 3, 200, -5, 50, 60, 99, 101};
    cout << "Stream medians: ";
    for (int x : nums1) {
        mf.addNum(x);
        cout << mf.findMedian() << " ";
    }
    cout << "\n";

    // All in [0..100]
    MedianFinder mf2;
    vector<int> nums2 = {10, 20, 30, 40, 50};
    cout << "Stream medians: ";
    for (int x : nums2) {
        mf2.addNum(x);
        cout << mf2.findMedian() << " ";
    }
    cout << "\n";

    // All outliers
    MedianFinder mf3;
    vector<int> nums3 = {-1000, 2000, -500, 3000};
    cout << "Stream medians: ";
    for (int x : nums3) {
        mf3.addNum(x);
        cout << mf3.findMedian() << " ";
    }
    cout << "\n";
}
