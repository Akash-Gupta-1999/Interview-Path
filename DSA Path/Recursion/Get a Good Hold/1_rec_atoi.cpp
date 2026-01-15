#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int i = 0, sign = 1;
    long long res = 0; // Using long to handle overflow cases

    // Trim leading spaces
    while (i < s.size() && s[i] == ' ') i++;
    if (i == s.size()) return 0;

    // Check for sign
    if (s[i] == '-') { sign = -1; i++; }
    else if (s[i] == '+') i++;

    // Process numerical characters
    while (i < s.size() && isdigit(s[i])) {
        res = res * 10 + (s[i] - '0');

        // Handle overflow
        if (sign * res > INT_MAX) return INT_MAX;  //if (res > (INT_MAX - digit) / 10) for interview safe
        if (sign * res < INT_MIN) return INT_MIN;

        i++;
    }

    return (int)(sign * res);
}

int main() {
    vector<string> tests = {
        "42",
        "   -42",
        "4193 with words",
        "words and 987",
        "-91283472332",    // underflow case
        "91283472332",     // overflow case
        "+123",
        "   +00456",
        "0",
        "-0",
        "2147483647",      // INT_MAX
        "-2147483648"      // INT_MIN
    };

    for (auto &t : tests) {
        cout << "\"" << t << "\" => " << myAtoi(t) << "\n";
    }

    return 0;
}
