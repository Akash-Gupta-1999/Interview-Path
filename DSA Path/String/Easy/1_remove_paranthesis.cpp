#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    string ans = "";
    int counter = 0;
    int i = 0;
    while(i<s.size()){
        if(s[i] == '('){
            if(counter != 0) ans += s[i];
            counter++;
        }
        else{
            counter--;
            if(counter != 0)
                ans+=s[i];
        }
        i++;
    }
    return ans;
}

int main() {
    string input = "(()())(())(()(()))";
    string output = removeOuterParentheses(input);
    cout << "Output:   " << output << endl;
    // Expected Output: "()()()()(())"
    return 0;
}
