#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    TrieNode* links[26];
    int wordCount;
    int prefixCount;
public:
    TrieNode() {
        memset(links, 0, sizeof(links));
        wordCount = 0;
        prefixCount = 0;
    }
    bool containsKey(char ch) { return links[ch - 'a'] != NULL; }
    TrieNode* get(char ch) { return links[ch - 'a']; }
    void put(char ch, TrieNode* node) { links[ch - 'a'] = node; }
    void increaseWordCount() { wordCount++; }
    void increasePrefixCount() { prefixCount++; }
    void decreaseWordCount() { wordCount--; }
    void decreasePrefixCount() { prefixCount--; }
    int getWordCount() { return wordCount; }
    int getPrefixCount() { return prefixCount; }
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch))
                node->put(ch, new TrieNode());
            node = node->get(ch);
            node->increasePrefixCount();
        }
        node->increaseWordCount();
    }

    int countWordsEqualTo(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch))
                return 0;
            node = node->get(ch);
        }
        return node->getWordCount();
    }

    int countWordsStartingWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch))
                return 0;
            node = node->get(ch);
        }
        return node->getPrefixCount();
    }

    void erase(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch))
                return;
            node = node->get(ch);
            node->decreasePrefixCount();
        }
        node->decreaseWordCount();
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apple");

    cout << trie.countWordsEqualTo("apple") << endl;       // Expected: 2
    cout << trie.countWordsStartingWith("app") << endl;    // Expected: 3
    trie.erase("apple");
    cout << trie.countWordsEqualTo("apple") << endl;       // Expected: 1
}
