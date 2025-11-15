#include <bits/stdc++.h>
using namespace std;

int priority(char c){
    if(c == '+' || c == '-')
        return 1;
    if(c == '/' || c == '*')
        return 2;
    if(c == '^')
        return 3;
    return 0;
}

string infixToPostfix(string expr) {
    int i = 0;
    string ans = "";
    stack<char> st;
    while(i < expr.size()){
        if(isalnum(expr[i])){   // operand → directly add to result
            ans += expr[i];
        }
        else if(expr[i] == '('){
            st.push(expr[i]);
        }
        else if(expr[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        else{ // operator
            if(st.empty()){
                st.push(expr[i]);
            } else {
                // 🔑 Intuition:
                // For left-associative ops (+,-,*,/):
                //   pop while precedence(curr) <= precedence(top)
                // For right-associative op (^):
                //   pop while precedence(curr) < precedence(top)
                while(!st.empty() && 
                      ((priority(expr[i]) < priority(st.top())) || 
                       (priority(expr[i]) == priority(st.top()) && expr[i] != '^'))) {
                    ans += st.top();
                    st.pop();
                }
                st.push(expr[i]);
            }
        }
        i++;
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main() {
    vector<string> testcases = {
        "a+b+c",
        "a+b*c",                  // simple precedence
        "(a+b)*c",                // parentheses
        "a+b*(c^d-e)^(f+g*h)-i",  // complex
        "a^b^c"                   // right-associativity test
    };

    for (auto &expr : testcases) {
        cout << "Infix: " << expr << endl;
        cout << "Postfix: " << infixToPostfix(expr) << endl;
        cout << "-------------------" << endl;
    }

    return 0;
}
