#include <bits/stdc++.h>
using namespace std;

/* -------------------------------------------------------------------------- */
/*                 Problem: Number of Distinct Substrings in a String         */
/* -------------------------------------------------------------------------- */
/*
Given a string `s`, return the number of distinct substrings (including empty)
that can be formed from it.

Example:
Input:  s = "ababa"
Output: 11
Explanation: Distinct substrings are 
["", "a","b","ab","ba","aba","bab","abab","baba","ababa","ba"].
*/

/* -------------------------------------------------------------------------- */
/*                                 TRIE NODE                                  */
/* -------------------------------------------------------------------------- */

class TrieNode {
public:
    TrieNode* links[26];

    TrieNode() {
        memset(links, 0, sizeof(links));
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }
};

/* -------------------------------------------------------------------------- */
/*                                SOLUTION CLASS                              */
/* -------------------------------------------------------------------------- */

class Solution {
public:
    int countDistinctSubstrings(string s) {
        TrieNode* root = new TrieNode;
        int cnt = 1; // count empty substring
        int n = s.size();

        for (int i = 0; i < n; i++) {
            TrieNode* temp = root;
            for (int j = i; j < n; j++) {
                if (!temp->containsKey(s[j])) {
                    cnt++;
                    temp->put(s[j], new TrieNode);
                }
                temp = temp->get(s[j]);
            }
        }

        return cnt;
    }
};

/* -------------------------------------------------------------------------- */
/*                                   MAIN                                     */
/* -------------------------------------------------------------------------- */

int main() {
    Solution sol;

    vector<string> testCases = {
        "a",
        "aa",
        "ab",
        "aba",
        "ababa",
        "abc",
        "aaaa",
        "xyzxy",
        "abcdabc"
    };

    cout << boolalpha;
    cout << "Number of Distinct Substrings (including empty string)\n";
    cout << "------------------------------------------------------\n";

    for (auto &s : testCases) {
        cout << "Input: \"" << s << "\"\n";
        cout << "Output: " << sol.countDistinctSubstrings(s) << "\n";
        cout << "------------------------------------------------------\n";
    }

    return 0;
}
