#include <bits/stdc++.h>
using namespace std;

/* -------------------------------------------------------------------------- */
/*                            Trie (Prefix Tree)                              */
/* -------------------------------------------------------------------------- */
/*
Implement the Trie class:

void insert(string word)       → Inserts a word into the trie.
bool search(string word)       → Returns true if the word is in the trie.
bool startsWith(string prefix) → Returns true if there is any word that starts with the prefix.
*/

class TrieNode {
private:
    TrieNode* links[26];
    bool isEnd;

public:
    TrieNode() {
        memset(links, 0, sizeof(links));
        isEnd = false;
    }

    // Helper functions for clean abstraction
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        isEnd = true;
    }

    bool isEndWord() {
        return isEnd;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    // Returns true if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch))
                return false;
            node = node->get(ch);
        }
        return node->isEndWord();
    }

    // Returns true if there is any word in the trie that starts with the prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch))
                return false;
            node = node->get(ch);
        }
        return true;
    }
};

/* -------------------------------------------------------------------------- */
/*                                   MAIN                                    */
/* -------------------------------------------------------------------------- */

int main() {
    Trie trie;

    trie.insert("apple");
    cout << boolalpha;
    cout << trie.search("apple") << endl;   // true
    cout << trie.search("app") << endl;     // false
    cout << trie.startsWith("app") << endl; // true
    trie.insert("app");
    cout << trie.search("app") << endl;     // true

    return 0;
}
