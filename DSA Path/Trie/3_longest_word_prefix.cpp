#include <bits/stdc++.h>
using namespace std;

/* -------------------------------------------------------------------------- */
/*                     Problem: Longest Word With All Prefixes                */
/* -------------------------------------------------------------------------- */
/*
Given an array of strings `words`, find the longest string such that:
1. All prefixes of the string are also present in the array.
2. If there are multiple answers, return the lexicographically smallest one.

Example:
Input:  words = ["n","ni","nin","ninj","ninja","ninga"]
Output: "ninja"

Constraints:
- 1 <= words.length <= 10^4
- 1 <= words[i].length <= 10
- words[i] consists of lowercase English letters.
*/

class TrieNode {
private:
    TrieNode* links[26];
    bool isEnd;

public:
    TrieNode(){
        memset(links,0,sizeof(links));
        isEnd = false;
    }
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    void put(char ch, TrieNode* node){
        links[ch-'a'] = node;
    }
    TrieNode* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        isEnd = true;
    }
    bool isEndWord(){
        return isEnd;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie(){
        root = new TrieNode;
    }
    void insert(string word){
        int n = word.size();
        TrieNode* temp = root;
        for(int i=0;i<n;i++){
            if(!temp->containsKey(word[i])){
                temp->put(word[i],new TrieNode);
            }
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }
    bool checkIfAllPrefixesExist(string word){
        int n = word.size();
        TrieNode* temp = root;
        for(int i=0;i<n;i++){
            if(temp->containsKey(word[i])){
                temp = temp->get(word[i]);
                if(!temp->isEndWord()) return false;
            }
            else
                return false;
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words){
        Trie tr;

        for(auto it : words)
            tr.insert(it);
        
        string longest = "";
        for(int i=0;i<words.size();i++){
            if(tr.checkIfAllPrefixesExist(words[i])){
                if(longest.size() < words[i].size())
                    longest = words[i];
                else if(longest.size() == words[i].size() && longest > words[i])
                    longest = words[i];
            }
        }
        return longest;
    }
};

/* -------------------------------------------------------------------------- */
/*                                   MAIN                                    */
/* -------------------------------------------------------------------------- */

int main() {
    Solution sol;
    vector<string> words = {"n","ni","nin","ninj","ninja","ninga"};
    
    cout << sol.longestWord(words) << endl; // Expected: "ninja"
    return 0;
}
