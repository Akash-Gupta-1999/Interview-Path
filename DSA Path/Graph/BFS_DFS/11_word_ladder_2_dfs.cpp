#include <bits/stdc++.h>
using namespace std;

// BFS: compute shortest distances
void bfs(string beginWord, string endWord, unordered_set<string>& hash, unordered_map<string,int>& dist) {
    queue<string> q;
    q.push(beginWord);
    dist[beginWord] = 0;
    hash.erase(beginWord);

    while (!q.empty()) {
        string word = q.front(); q.pop();
        for (int i = 0; i < word.size(); i++) {
            string w = word;
            for (char c = 'a'; c <= 'z'; c++) {
                w[i] = c;
                if (hash.count(w)) {
                    q.push(w);
                    dist[w] = dist[word] + 1;
                    hash.erase(w);
                }
            }
        }
    }
}

// DFS: backward from endWord to beginWord
void dfs(string beginWord, string curr, unordered_map<string,int>& dist, vector<string>& path, vector<vector<string>>& ans) {
    if (curr == beginWord) {
        reverse(path.begin(), path.end());
        ans.push_back(path);
        reverse(path.begin(), path.end()); // restore for other paths
        return;
    }

    for (int i = 0; i < curr.size(); i++) {
        string w = curr;
        for (char c = 'a'; c <= 'z'; c++) {
            w[i] = c;
            if (dist.count(w) && dist[w] + 1 == dist[curr]) {
                path.push_back(w);
                dfs(beginWord, w, dist, path, ans);
                path.pop_back();
            }
        }
    }
}

// Main function to find all shortest ladders
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> ans;
    unordered_set<string> hash(wordList.begin(), wordList.end());
    if (!hash.count(endWord)) return ans;

    unordered_map<string,int> dist;
    bfs(beginWord, endWord, hash, dist);

    if (!dist.count(endWord)) return ans;

    vector<string> path = {endWord};
    dfs(beginWord, endWord, dist, path, ans);
    return ans;
}

// Utility to print sequences
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

int main() {
    // Testcase 1
    string start1 = "der", end1 = "dfs";
    vector<string> dict1 = {"des","der","dfr","dgt","dfs"};
    cout << "TC1: der -> dfs\n";
    printSequences(findLadders(start1, end1, dict1));
    cout << "-------------------\n";

    // Testcase 2
    string start2 = "hit", end2 = "cog";
    vector<string> dict2 = {"hot","dot","dog","lot","log","cog"};
    cout << "TC2: hit -> cog\n";
    printSequences(findLadders(start2, end2, dict2));
    cout << "-------------------\n";

    // Testcase 3 (endWord missing)
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

    // Testcase 5 (your previous example)
    string start5 = "hot", end5 = "dog";
    vector<string> dict5 = {"hot","dot","dog"};
    cout << "TC5: hot -> dog\n";
    printSequences(findLadders(start5, end5, dict5));
    cout << "-------------------\n";

    return 0;
}
