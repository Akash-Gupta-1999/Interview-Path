#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    vector<int> freq;
    int count;

public:
    MedianFinder() : freq(101, 0), count(0) {}

    void addNum(int num) {
        freq[num]++;
        count++;
    }

    double findMedian() {
        int c = 0;
        int mid1 = (count + 1) / 2;
        int mid2 = (count % 2 == 0) ? (count / 2 + 1) : mid1;

        int num1 = -1, num2 = -1;
        for (int i = 0; i <= 100; i++) {
            c += freq[i];
            if (num1 == -1 && c >= mid1) num1 = i;
            if (num2 == -1 && c >= mid2) {
                num2 = i;
                break;
            }
        }
        return (num1 + num2) / 2.0;
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