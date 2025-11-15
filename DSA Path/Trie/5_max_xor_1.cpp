#include <bits/stdc++.h>
using namespace std;

// Each Trie node stores binary branches for 0 and 1.
struct TrieNode {
    TrieNode* links[2];
    TrieNode() {
        links[0] = links[1] = NULL;
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
        root = new TrieNode();
    }

    // Insert number from MSB to LSB into Trie
    void insert(int num) {
        TrieNode* temp = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!temp->containsKey(bit))
                temp->put(bit, new TrieNode());
            temp = temp->get(bit);
        }
    }

    // Find maximum XOR with given number
    int getMaxXor(int num) {
        TrieNode* temp = root;
        int maxXor = 0;

        // For each bit, try to go opposite bit to maximize XOR
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(temp->containsKey(1 - bit)) {
                maxXor |= (1 << i);
                temp = temp->get(1 - bit);
            } else {
                temp = temp->get(bit);
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    int maxXorTwoArrays(vector<int>& A, vector<int>& B) {
        Trie tr;

        // Step 1: Insert all elements of A into Trie
        for(int x : A) tr.insert(x);

        int result = 0;
        // Step 2: For each element in B, compute best XOR with A
        for(int x : B)
            result = max(result, tr.getMaxXor(x));
        
        return result;
    }
};

int main() {
    vector<int> A = {3, 9, 10, 5, 1};
    vector<int> B = {2, 7, 4};

    Solution s;
    cout << s.maxXorTwoArrays(A, B) << endl; // Output: maximum a^b

    return 0;
}
