#include <bits/stdc++.h>
using namespace std;

/*
Backtracking function:
idx  -> current index in digits
str  -> current combination string
digits -> input digit string
tel  -> digit-to-letters mapping
res  -> stores all possible combinations
*/
void rec_let(int idx, string str, string digits, vector<vector<char>>& tel, vector<string>& res) {
    // Base case: if we've used all digits, save combination
    if (idx == digits.size()) {
        res.push_back(str);
        return;
    }
    // Get letters corresponding to current digit
    vector<char> num = tel[digits[idx] - '0'];
    for (char c : num) {
        str.push_back(c); // choose
        rec_let(idx + 1, str, digits, tel, res); // explore
        str.pop_back(); // backtrack
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    
    vector<vector<char>> tel = {
        {}, {}, {'a','b','c'}, {'d','e','f'}, {'g','h','i'},
        {'j','k','l'}, {'m','n','o'}, {'p','q','r','s'},
        {'t','u','v'}, {'w','x','y','z'}
    };
    
    vector<string> res;
    rec_let(0, "", digits, tel, res);
    return res;
}

/*
Time Complexity:  O(4^n) where n = length of digits
Space Complexity: O(n) recursion stack + O(4^n) results storage
*/

int main() {
    vector<string> tests = {"23", "7", "", "234"};
    
    for (string digits : tests) {
        cout << "Digits: " << (digits.empty() ? "(empty)" : digits) << "\n";
        auto combos = letterCombinations(digits);
        if (combos.empty()) {
            cout << "No combinations.\n";
        } else {
            for (auto &c : combos) cout << c << " ";
            cout << "\n";
        }
        cout << "----------------\n";
    }
}
