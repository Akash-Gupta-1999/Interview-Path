#include <bits/stdc++.h>
using namespace std;

// ✅ Function to check if a character is an operator
bool isOperator(char c) {
    if(c == '+' || c == '-' || c  == '*' || c == '/' || c == '^')
        return true;
    return false;
}

// ✅ Function to convert prefix expression to infix
string prefixToInfix(string prefix) {
    stack<string> st;
    int i = prefix.size()-1;
    while(i>=0){
        if(!isOperator(prefix[i]))
            st.push(string(1,prefix[i]));
        else{
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            op1 = '(' + op1 + prefix[i] + op2 + ')';
            st.push(op1);
        }
        i--;
    }
    return st.top(); // final infix expression
}

int main() {
    // 🧪 Test cases
    vector<string> testCases = {
        "*+abc",     // Expected: ((a+b)*c)
        "+a*bc",     // Expected: (a+(b*c))
        "-+abc",     // Expected: ((a+b)-c)
        "^a^bc",      // Expected: (a^(b^c))
        "++abc"
    };

    for (auto &prefix : testCases) {
        cout << "Prefix: " << prefix 
             << " -> Infix: " << prefixToInfix(prefix) << endl;
    }

    return 0;
}
