#include <iostream>
#include <string>
using namespace std;

string reverseWords(string s) {
    string ans = "", temp = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            temp += s[i];
        } else if (!temp.empty()) {
            if (!ans.empty())
                ans = temp + " " + ans;
            else
                ans = temp;
            temp = "";
        }
    }
    if (!temp.empty()) {
        if (!ans.empty())
            ans = temp + " " + ans;
        else
            ans = temp;
    }
    return ans;
}

int main() {
    string input = "  the sky   is blue  ";
    string output = reverseWords(input);
    cout << "Input:  \"" << input << "\"" << endl;
    cout << "Output: \"" << output << "\"" << endl;
    // Expected: "blue is sky the"
    return 0;
}
