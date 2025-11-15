#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {
    int i = num.size() - 1;
    while(i >= 0) {
        int dig = num[i] - '0';
        if(dig % 2 != 0)
            break;
        i--;
    }
    return num.substr(0, i + 1);
}

int main() {
    string input = "47206";
    string result = largestOddNumber(input);

    cout << "Input:    " << input << endl;
    cout << "Output:   " << (result.empty() ? "\"\"" : result) << endl;

    // You can test with more inputs:
    // vector<string> testCases = {"4206", "35427068", "731", "52", "2468"};
    // for(string test : testCases)
    //     cout << "Input: " << test << "  →  Output: " << largestOddNumber(test) << endl;

    return 0;
}
