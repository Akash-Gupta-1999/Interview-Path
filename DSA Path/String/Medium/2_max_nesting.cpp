#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

int maxDepth(string s) {
    int count = 0, max_count = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            count++;
            max_count = max(count, max_count);
        } else if(s[i] == ')') {
            count--;
        }
    }
    return max_count;
}

int main() {
    vector<pair<string, int>> testCases = {
        {"", 0},
        {"()", 1},
        {"(1+(2*3)+((8)/4))+1", 3},
        {"(1)+((2))+(((3)))", 3},
        {"1+(2*3)/(2-1)", 1},
        {"1", 0},
        {"(((((((((())))))))))", 10}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        string input = testCases[i].first;
        int expected = testCases[i].second;
        int result = maxDepth(input);
        cout << "Test case " << i+1 << ": ";
        cout << "Input: \"" << input << "\" | Expected: " << expected << " | Got: " << result;
        if(result == expected)
            cout << " ✅" << endl;
        else
            cout << " ❌" << endl;
    }

    return 0;
}
