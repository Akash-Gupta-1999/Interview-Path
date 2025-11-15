#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) {
        return false;
    }
    return (s + s).find(goal) != string::npos;
}

int main() {
    string s = "abcde";
    string goal = "cdeab";

    if (rotateString(s, goal)) {
        cout << "Yes, '" << goal << "' is a rotation of '" << s << "'." << endl;
    } else {
        cout << "No, '" << goal << "' is not a rotation of '" << s << "'." << endl;
    }

    return 0;
}
