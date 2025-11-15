#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s) {
    int n = s.size();
    stack<char> st;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '(') 
            st.push(s[i]);
        else{
            if(!st.empty()) 
                st.pop();
            else 
                ans++; // we need an extra '('
        }
    }
    ans += st.size(); // remaining '(' need ')'
    return ans;
}

int main() {
    vector<string> testcases = {
        "())",
        "(((",
        "()",
        "()))((",
        "(()))(",
        "",
        ")(",
        "(()(()"
    };

    cout << boolalpha;
    for(string &s : testcases) {
        cout << "Input: \"" << s << "\"  -->  Output: " << minAddToMakeValid(s) << endl;
    }

    return 0;
}
