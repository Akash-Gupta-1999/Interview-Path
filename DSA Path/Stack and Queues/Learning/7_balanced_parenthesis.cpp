#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    unordered_map<char,char> umap = {
        {')','('},
        {']','['},
        {'}','{'}
    };
    
    stack<char> st;
    for (char c : s) {
        if (umap.count(c)) { // if it's a closing bracket
            if (st.empty() || st.top() != umap[c])
                return false;
            st.pop();
        } else {
            st.push(c); // must be an opening bracket
        }
    }
    return st.empty();
}

int main() {
    vector<string> testcases = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[]}",
        "",
        "(",
        "((((()))))",
        "((){})",
        "({[)]]"
    };

    for (auto &s : testcases) {
        cout << "Input: " << s 
             << " -> " << (isValid(s) ? "Valid" : "Invalid") << endl;
    }

    return 0;
}
