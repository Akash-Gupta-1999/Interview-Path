#include <bits/stdc++.h>
using namespace std;

void rec_generate(int n, int open, string curr, vector<string> &ans) {
    if ((int)curr.size() == 2 * n) {
        ans.push_back(curr);
        return;
    }
    if (open < n) 
        rec_generate(n, open + 1, curr + "(", ans);
    if ((int)curr.size() - open < open) 
        rec_generate(n, open, curr + ")", ans);
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    rec_generate(n, 0, "", ans);
    return ans;
}

int main() {
    vector<int> testCases = {1, 2, 3, 4};

    for (int n : testCases) {
        cout << "All valid parentheses combinations for n = " << n << ":\n";
        vector<string> res = generateParenthesis(n);
        for (auto &s : res) {
            cout << s << "\n";
        }
        cout << "Total: " << res.size() << "\n\n";
    }

    return 0;
}
