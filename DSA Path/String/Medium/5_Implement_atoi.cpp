#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int i = 0, n = s.size();

    // 1. Skip leading whitespaces
    while (i < n && s[i] == ' ') i++;

    // 2. Optional sign
    int sign = 1;
    if (i < n && (s[i] == '-' || s[i] == '+')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // 3. Read digits
    long long num = 0;
    while (i < n && isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');

        // 4. Clamp if overflow occurs
        if (sign == 1 && num > INT_MAX) return INT_MAX;
        if (sign == -1 && -num < INT_MIN) return INT_MIN;

        i++;
    }

    return (int)(sign * num);
}

int main() {
    vector<string> test_cases = {
        "42",                 // 42
        "   -42",             // -42
        "4193 with words",    // 4193
        "words and 987",      // 0
        "-91283472332",       // -2147483648 (INT_MIN)
        "91283472332",        // 2147483647 (INT_MAX)
        "+1",                 // 1
        "00000-42a1234",      // 0
        "   +0 123",          // 0
        "   +004500",         // 4500
        "-+12",               // 0
        "++1",                // 0
        "+-12",               // 0
        "",                   // 0
        "    ",               // 0
        "-",                  // 0
        "+",                  // 0
    };

    for (const string& s : test_cases) {
        cout << "Input: \"" << s << "\" => Output: " << myAtoi(s) << endl;
    }

    return 0;
}
