#include <bits/stdc++.h>
using namespace std;

/* -------------------------------------------------------------------------- */
/*                              INTUITION / LOGIC                              */
/* -------------------------------------------------------------------------- */
/*
We want to answer multiple queries:
For each query (Xi, Ai), find maximum (Xi XOR num) such that num <= Ai from nums[].

Key Observations:
1. Maximum XOR of two numbers depends on **choosing opposite bits** where possible.
2. Trie is used to efficiently query the "best match" for maximizing XOR.
3. But we cannot insert all numbers blindly — each query has a different Ai limit.

Approach:
---------
1. Sort nums[] (so we can insert only values <= Ai).
2. For each query (Xi, Ai), sort queries by Ai also.
3. Maintain index i = 0 for nums:
      - Insert nums[i] into Trie while nums[i] <= Ai
4. Once all valid nums for this query are inserted,
      - Perform max XOR search in Trie.
5. If no nums were eligible (i == 0), answer is -1.

This ensures each number is inserted at most once → O(n * log(maxValue)).
*/

/* -------------------------------------------------------------------------- */
/*                                TRIE NODE                                    */
/* -------------------------------------------------------------------------- */

struct TrieNode{
    TrieNode* links[2];
    TrieNode(){
        memset(links,0,sizeof(links));
    }
    bool containsKey(int bit){
        return links[bit] != NULL;
    }
    TrieNode* get(int bit){
        return links[bit];
    }
    void put(int bit, TrieNode* node){
        links[bit] = node;
    }
};

/* -------------------------------------------------------------------------- */
/*                                   TRIE                                      */
/* -------------------------------------------------------------------------- */

struct Trie{
    TrieNode* root;
    Trie(){
        root = new TrieNode;
    }

    // Insert a number bit-by-bit (32-bit)
    void insert(int num){
        TrieNode* temp = root;
        for(int i=31;i>=0;i--){
            int bit = (num >> i) & 1;
            if(!temp->containsKey(bit))
                temp->put(bit, new TrieNode);
            temp = temp->get(bit);
        }
    }

    // Find maximum XOR pair value for `num`
    int findMax(int num){
        TrieNode* temp = root;
        int maxVal = 0;
        for(int i=31;i>=0;i--){
            int bit = (num >> i) & 1;

            // Greedy: Try to go opposite bit to maximize XOR
            if(temp->containsKey(1-bit)){
                maxVal |= (1 << i);
                temp = temp->get(1-bit);
            }
            else{
                temp = temp->get(bit);
            }
        }
        return maxVal;
    }
};

/* -------------------------------------------------------------------------- */
/*                                 SOLUTION                                    */
/* -------------------------------------------------------------------------- */

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), -1);
        vector<vector<int>> qr;
        Trie tr;

        sort(nums.begin(), nums.end()); // So we can insert only values <= Ai

        // Convert each query to (Ai, Xi, index)
        int idx = 0;
        for(auto &q : queries)
            qr.push_back({q[1], q[0], idx++});

        sort(qr.begin(), qr.end()); // Sort queries by Ai

        int i = 0, n = nums.size();
        for(auto &q : qr){
            int Ai = q[0], Xi = q[1], id = q[2];

            // Insert nums <= Ai
            while(i < n && nums[i] <= Ai){
                tr.insert(nums[i]);
                i++;
            }

            // If no valid values inserted → answer = -1
            if(i != 0)
                ans[id] = tr.findMax(Xi);
            else
                ans[id] = -1;
        }
        return ans;
    }
};

/* -------------------------------------------------------------------------- */
/*                                   MAIN                                      */
/* -------------------------------------------------------------------------- */

int main(){
    Solution sol;

    vector<int> nums1 = {3, 10, 5, 25, 2, 8};
    vector<vector<int>> q1 = {{5, 28}, {5, 2}, {25, 25}};
    auto ans1 = sol.maximizeXor(nums1, q1);
    cout << "Test Case 1: ";
    for(int x: ans1) cout << x << " ";
    cout << "\n";

    vector<int> nums2 = {0,1,2,3,4};
    vector<vector<int>> q2 = {{3,1},{1,3},{5,6}};
    auto ans2 = sol.maximizeXor(nums2, q2);
    cout << "Test Case 2: ";
    for(int x: ans2) cout << x << " ";
    cout << "\n";

    vector<int> nums3 = {7,7,7,7};
    vector<vector<int>> q3 = {{7,7},{0,7},{7,0}};
    auto ans3 = sol.maximizeXor(nums3, q3);
    cout << "Test Case 3: ";
    for(int x: ans3) cout << x << " ";
    cout << "\n";

    return 0;
}
