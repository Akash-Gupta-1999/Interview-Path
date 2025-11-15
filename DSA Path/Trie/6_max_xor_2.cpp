#include <bits/stdc++.h>
using namespace std;

/* -------------------------------------------------------------------------- */
/*               Problem: Maximum XOR of Two Numbers in an Array              */
/* -------------------------------------------------------------------------- */
/*
We want to pick two numbers A and B from the array such that A XOR B is maximum.

Key Insight:
------------
To maximize XOR, we always want opposite bits:
- If we have a 1, we want to match it with 0.
- If we have a 0, we want to match it with 1.

So while checking each number, we try to move in the Trie where the opposite bit exists.
This helps us build the maximum XOR bit-by-bit from the most significant bit (MSB) to LSB.
*/

/* -------------------------------------------------------------------------- */
/*                                   TRIE                                    */
/* -------------------------------------------------------------------------- */

struct TrieNode {
    TrieNode* links[2]; // Only 2 children: for bit 0 and bit 1
    TrieNode() {
        memset(links, 0, sizeof(links));
    }
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }
    TrieNode* get(int bit) {
        return links[bit];
    }
    void put(int bit, TrieNode* node) {
        links[bit] = node;
    }
};

struct Trie {
    TrieNode* root;
    Trie() {
        root = new TrieNode;
    }

    // Insert the 32-bit representation of number into Trie
    void insert(int num) {
        TrieNode* temp = root;
        for (int i = 31; i >= 0; i--) { // Check bit from MSB → LSB
            int bit = (num >> i) & 1;
            if (!temp->containsKey(bit)) {
                temp->put(bit, new TrieNode);
            }
            temp = temp->get(bit);
        }
    }

    // Find best possible XOR partner for 'num' from existing Trie values
    int findMaxXor(int num) {
        TrieNode* temp = root;
        int maxVal = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            // We prefer to go to the opposite bit to maximize XOR
            if (temp->containsKey(1 - bit)) {
                maxVal |= (1 << i); // Set this bit in result
                temp = temp->get(1 - bit);
            } 
            else {
                temp = temp->get(bit); // No choice, follow same bit
            }
        }
        return maxVal;
    }
};

/* -------------------------------------------------------------------------- */
/*                                SOLUTION CLASS                              */
/* -------------------------------------------------------------------------- */

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        /*
        Strategy:
        1. Insert numbers one by one into Trie.
        2. For each number, try to find a previously inserted number that
           gives maximum XOR with it.
        3. Track and return the maximum obtained.
        */

        Trie tr;
        int n = nums.size();
        int maxAns = 0;

        tr.insert(nums[0]); // Insert first number

        for (int i = 1; i < n; i++) {
            // Compute best XOR for current number with previous values
            maxAns = max(maxAns, tr.findMaxXor(nums[i]));
            // Insert current number for future comparisons
            tr.insert(nums[i]);
        }

        return maxAns;
    }
};

/* -------------------------------------------------------------------------- */
/*                                   MAIN                                     */
/* -------------------------------------------------------------------------- */

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {3, 9, 10, 5, 1},      // Expected: 15 -> (10 XOR 5)
        {26, 49, 30, 15, 69},  // Expected: 116 -> (69 XOR 49)
        {2, 4},                // Expected: 6
        {8, 10, 2},            // Expected: 10
        {0, 7},                // Expected: 7
        {5, 25}                // Expected: 28
    };

    for (auto& nums : testCases) {
        cout << "Input: ";
        for (auto x : nums) cout << x << " ";
        cout << "\nOutput: " << sol.findMaximumXOR(nums) << "\n";
        cout << "-----------------------------\n";
    }

    return 0;
}
