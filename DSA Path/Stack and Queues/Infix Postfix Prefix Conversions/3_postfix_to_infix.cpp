#include <bits/stdc++.h>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    if(c == '+' || c == '-' || c  == '/' || c == '*' || c == '^')
        return true;
    return false;
}

// Function to convert postfix expression to infix
string postfixToInfix(string postfix) {
    stack<string> st;
    int i = 0;
    while(i<postfix.size()){
        if(!isOperator(postfix[i]))
            st.push(string(1,postfix[i]));
        else{
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            op1 = "(" + op1 + postfix[i] + op2 + ")";
            st.push(op1);
        }
        i++;
    }
    return st.top();
}

int main() {
    // Test cases
    vector<string> testCases = {
        "ab+c*",   // expected: ((a+b)*c)
        "ab+cde+**", // expected: ((a+b)*(c*(d+e)))
        "abc^^",
        "ab+c+"
    };

    for (auto &postfix : testCases) {
        cout << "Postfix: " << postfix 
             << " -> Infix: " << postfixToInfix(postfix) << endl;
    }

    return 0;
}
