#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToPrefix(string postfix) {
    stack<string> st;
    int i=0;
    while(i<postfix.size()){
        if(!isOperator(postfix[i]))
            st.push(string(1,postfix[i]));
        else{
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            op1 = postfix[i] + op1 + op2;
            st.push(op1);
        }
        i++;
    }
    return st.top();
}

int main() {
    vector<string> testCases = {
        "ab+c*",      // postfix → prefix: *+abc
        "ab+cde+**",   // postfix → prefix: *+a*b c+de
        "ab+c+",
        "abc^^"
    };

    for (auto &postfix : testCases) {
        cout << "Postfix: " << postfix
             << " -> Prefix: " << postfixToPrefix(postfix) << endl;
    }

    return 0;
}
