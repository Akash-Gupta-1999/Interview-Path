#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
    int minOpen = 0, maxOpen = 0;  
    // minOpen = minimum '(' count we must keep (treat '*' as ')')
    // maxOpen = maximum '(' count possible (treat '*' as '(')

    for (char c : s) {
        if (c == '(') {
            minOpen++;
            maxOpen++;
        } else if (c == ')') {
            minOpen--;
            maxOpen--;
        } else { // c == '*'
            minOpen--;   // if '*' acts as ')'
            maxOpen++;   // if '*' acts as '('
        }

        if (minOpen < 0) minOpen = 0;   // can't have negative open
        if (maxOpen < 0) return false; // too many ')'
    }

    return minOpen == 0;  // valid if we can fully balance
}

int main() {
    vector<string> tests = {
        "()",       // true
        "(*)",      // true
        "(*))",     // true
        "*)(",      // false
        "(((******))", // true
        "(((*)",    // false
        "*",        // true
        "",         // true (empty string is balanced)
    };

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test " << i+1 << " (" << tests[i] << "): "
             << (checkValidString(tests[i]) ? "true" : "false") << endl;
    }
}
