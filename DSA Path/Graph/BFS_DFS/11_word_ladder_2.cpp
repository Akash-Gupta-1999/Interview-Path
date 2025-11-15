#include <bits/stdc++.h>
using namespace std;

// Function to find all shortest transformation sequences
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wl(wordList.begin(), wordList.end());
    vector<vector<string>> ans;

    if (wl.find(endWord) == wl.end()) return ans; // endWord must be in dict

    queue<vector<string>> q;
    q.push({beginWord});

    vector<string> used;
    int level = 1; // start with 1 word in path

    while (!q.empty()) {
        vector<string> path = q.front();
        q.pop();

        // if we moved to next level -> erase used words
        if (path.size() > level) {
            for (auto &w : used) wl.erase(w);
            used.clear();
            level = path.size();
        }

        string word = path.back();

        if (word == endWord) {
            ans.push_back(path);
            continue; // don't stop early, collect all
        }

        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == original) continue;
                word[i] = c;

                if (wl.find(word) != wl.end()) {
                    vector<string> newPath = path;
                    newPath.push_back(word);
                    q.push(newPath);
                    used.push_back(word);
                }
            }
            word[i] = original;
        }
    }

    return ans;
}

// Utility to print results
void printSequences(const vector<vector<string>>& ans) {
    if (ans.empty()) {
        cout << "No transformation sequence found." << endl;
        return;
    }
    for (auto &seq : ans) {
        for (auto &w : seq) cout << w << " ";
        cout << endl;
    }
}

// Driver with testcases
int main() {
    // Testcase 1
    string start1 = "der", end1 = "dfs";
    vector<string> dict1 = {"des","der","dfr","dgt","dfs"};
    cout << "TC1: der -> dfs\n";
    printSequences(findLadders(start1, end1, dict1));
    cout << "-------------------\n";

    // Testcase 2 (classic LeetCode case)
    string start2 = "hit", end2 = "cog";
    vector<string> dict2 = {"hot","dot","dog","lot","log","cog"};
    cout << "TC2: hit -> cog\n";
    printSequences(findLadders(start2, end2, dict2));
    cout << "-------------------\n";

    // Testcase 3 (end word missing)
    string start3 = "hit", end3 = "cog";
    vector<string> dict3 = {"hot","dot","dog","lot","log"};
    cout << "TC3: hit -> cog (missing)\n";
    printSequences(findLadders(start3, end3, dict3));
    cout << "-------------------\n";

    // Testcase 4 (single step)
    string start4 = "a", end4 = "c";
    vector<string> dict4 = {"a","b","c"};
    cout << "TC4: a -> c\n";
    printSequences(findLadders(start4, end4, dict4));
    cout << "-------------------\n";

    return 0;
}
