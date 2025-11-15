#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end()) return 0; // endWord not in list

    queue<pair<string,int>> q;
    q.push({beginWord, 1});
    dict.erase(beginWord);

    while (!q.empty()) {
        auto [word, steps] = q.front();
        q.pop();

        if (word == endWord) return steps;

        for (int i = 0; i < word.size(); i++) {
            string w = word;
            for (char c = 'a'; c <= 'z'; c++) {
                if (w[i] == c) continue;
                w[i] = c;

                if (dict.find(w) != dict.end()) {
                    q.push({w, steps + 1});
                    dict.erase(w); // mark visited
                }
            }
        }
    }
    return 0;
}

int main() {
    // Testcase 1
    vector<string> wordList1 = {"hot","dot","dog","lot","log","cog"};
    cout << "TC1 (hit -> cog): " 
         << ladderLength("hit", "cog", wordList1) << endl; 
    // Expected: 5 (hit -> hot -> dot -> dog -> cog)

    // Testcase 2
    vector<string> wordList2 = {"hot","dot","dog","lot","log"};
    cout << "TC2 (hit -> cog): " 
         << ladderLength("hit", "cog", wordList2) << endl; 
    // Expected: 0 (cog not in list)

    // Testcase 3
    vector<string> wordList3 = {"a","b","c"};
    cout << "TC3 (a -> c): " 
         << ladderLength("a", "c", wordList3) << endl;
    // Expected: 2 (a -> c)

    // Testcase 4
    vector<string> wordList4 = {"hot"};
    cout << "TC4 (hit -> hot): " 
         << ladderLength("hit", "hot", wordList4) << endl;
    // Expected: 2 (hit -> hot)

    return 0;
}
