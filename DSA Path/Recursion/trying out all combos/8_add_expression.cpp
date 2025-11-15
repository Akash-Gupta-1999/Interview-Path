#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int idx, string path, string& num, int target,
                   vector<string>& res, long long eval, long long prev) {
        if (idx == num.size()) {
            if (eval == target)
                res.push_back(path);
            return;
        }

        for (int i = idx; i < num.size(); i++) {
            if (i != idx && num[idx] == '0')   // skip leading zeros
                break;

            string currstr = num.substr(idx, i - idx + 1);
            long long curr = stoll(currstr);

            if (idx == 0) {
                backtrack(i+1, path+currstr, num, target, res, curr, curr);
            } else {
                backtrack(i+1, path+"+"+currstr, num, target, res, eval+curr, curr);
                backtrack(i+1, path+"-"+currstr, num, target, res, eval-curr, -curr);
                backtrack(i+1, path+"*"+currstr, num, target, res, eval-prev + prev*curr, prev*curr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> res;
        backtrack(0, "", num, target, res, 0, 0);
        return res;
    }
};

int main() {
    Solution sol;

    vector<pair<string,int>> tests = {
        {"123", 6},     // ["1+2+3","1*2*3"]
        {"232", 8},     // ["2*3+2","2+3*2"]
        {"105", 5},     // ["1*0+5","10-5"]
        {"00", 0},      // ["0+0","0-0","0*0"]
        {"3456237490", 9191} // []
    };

    for (auto &t : tests) {
        cout << "Input: num=\"" << t.first << "\", target=" << t.second << "\n";
        vector<string> ans = sol.addOperators(t.first, t.second);
        cout << "Output expressions:\n";
        for (auto &exp : ans) cout << exp << "\n";
        if (ans.empty()) cout << "(none)\n";
        cout << "-----------------------------------\n";
    }

    return 0;
}
