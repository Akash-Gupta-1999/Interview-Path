#include <bits/stdc++.h>
using namespace std;

/*
   Problem: Single Number III (LeetCode 260)

   In the array, every number appears exactly twice except for two numbers
   which appear only once. We need to find those two numbers.

   Approach:
   ----------
   1. XOR of all numbers = a ^ b   (where a and b are the two unique numbers).
   2. Since a != b, their XOR has at least one set bit.
   3. Isolate one set bit (here we use mask = x ^ (x & (x-1)) ).
   4. Partition numbers into two groups:
         - Group 1: numbers with that bit set
         - Group 2: numbers with that bit unset
      Duplicates cancel out → each group leaves one unique number.
*/

vector<int> singleNumber(vector<int>& nums) {
    long x = 0;
    for (int n : nums) x ^= n;  // XOR of all numbers = a ^ b

    int mask = x ^ (x & (x - 1)); // isolate rightmost set bit

    int num1 = 0, num2 = 0;
    for (int n : nums) {
        if (n & mask)
            num1 ^= n; // group 1
        else
            num2 ^= n; // group 2
    }
    return {num1, num2}; // return the two unique numbers
}

int main() {
    vector<vector<int>> testcases = {
        {1, 2, 1, 3, 2, 5},       // unique: 3, 5
        {4, 1, 2, 1, 2, 3},       // unique: 4, 3
        {10, 20, 30, 10, 20, 40}, // unique: 30, 40
        {7, 9},                   // only two numbers: 7, 9
        {2, 2, 3, 5}              // unique: 3, 5
    };

    for (auto& nums : testcases) {
        vector<int> ans = singleNumber(nums);
        cout << "Input: ";
        for (int n : nums) cout << n << " ";
        cout << "\nUnique numbers: " << ans[0] << " and " << ans[1] << "\n\n";
    }

    return 0;
}
