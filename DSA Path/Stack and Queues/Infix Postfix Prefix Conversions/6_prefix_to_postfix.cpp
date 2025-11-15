#include <bits/stdc++.h>
using namespace std;

// Utility function to check operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Convert Prefix to Postfix
string prefixToPostfix(string prefix) {
    stack<string> st;
    int i = prefix.size()-1;
    while(i>=0){
        if(!isOperator(prefix[i]))
            st.push(string(1,prefix[i]));
        else{
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            op1 = op1 + op2 + prefix[i];
            st.push(op1);
        }
        i--;
    }
    return st.top();
}

int main() {
    vector<string> testCases = {
        "*+abc",     // Prefix → Postfix: ab+c*
        "*+a*bc+de",  // Prefix → Postfix: ab+cde+**
        "++abc",
        "^a^bc"
    };

    for (auto &prefix : testCases) {
        cout << "Prefix: " << prefix
             << " -> Postfix: " << prefixToPostfix(prefix) << endl;
    }
    return 0;
}
