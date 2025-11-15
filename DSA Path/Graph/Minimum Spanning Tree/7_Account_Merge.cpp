#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // path compression
    }

    void unionBySize(int u, int v) {
        int u_par = findParent(u);
        int v_par = findParent(v);
        if (u_par == v_par) return;

        if (size[u_par] > size[v_par]) {
            parent[v_par] = u_par;
            size[u_par] += size[v_par];
        } else {
            parent[u_par] = v_par;
            size[v_par] += size[u_par];
        }
    }
};

// ====================================
// Function: accountsMerge
// ====================================
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    DisjointSet dsu(n);
    unordered_map<string, int> hash;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < accounts[i].size(); j++) {
            if (hash.find(accounts[i][j]) == hash.end())
                hash[accounts[i][j]] = i;
            else
                dsu.unionBySize(i, hash[accounts[i][j]]);
        }
    }

    vector<vector<string>> acc_merged(n);
    for (auto it : hash) {
        string mail = it.first;
        int node = dsu.findParent(it.second);
        acc_merged[node].push_back(mail);
    }

    vector<vector<string>> ans;
    for (int i = 0; i < n; i++) {
        if (acc_merged[i].size() == 0) continue;
        sort(acc_merged[i].begin(), acc_merged[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]); // original line (no change)
        for (auto it : acc_merged[i]) temp.push_back(it);
        ans.push_back(temp);
    }
    return ans;
}

// ====================================
// Main Function with Multiple Test Cases
// ====================================
int main() {
    vector<vector<vector<string>>> testCases = {
        {
            {"John", "johnsmith@mail.com", "john00@mail.com"},
            {"John", "johnnybravo@mail.com"},
            {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
            {"Mary", "mary@mail.com"}
        },
        {
            {"Alex", "alex@mail.com", "alex1@mail.com"},
            {"Alex", "alex2@mail.com"},
            {"Alex", "alex1@mail.com", "alex3@mail.com"}
        },
        {
            {"Bob", "b1@mail.com"},
            {"Bob", "b2@mail.com"},
            {"Bob", "b1@mail.com", "b2@mail.com"},
            {"Alice", "a1@mail.com"}
        }
    };

    for (int t = 0; t < testCases.size(); t++) {
        cout << "==============================\n";
        cout << "Test Case " << t + 1 << "\n";
        cout << "==============================\n";

        auto accounts = testCases[t];
        auto res = accountsMerge(accounts);

        for (auto &acc : res) {
            for (auto &s : acc)
                cout << s << " ";
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}
