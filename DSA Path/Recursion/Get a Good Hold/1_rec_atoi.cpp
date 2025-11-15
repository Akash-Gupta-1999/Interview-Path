#include <bits/stdc++.h>
using namespace std;

int skip_spaces(const string &s, int i) {
    if (i >= s.size() || s[i] != ' ')
        return i;
    return skip_spaces(s, i + 1);
}

int is_sign(const string &s, int i, int &sign) {
    if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        return i + 1;
    }
    return i;
}

long long parse_digit(const string &s, int i, int sign, long long curr) {
    if (i >= s.size() || !isdigit(s[i]))
        return curr;
    curr = curr * 10 + (s[i] - '0');
    if (sign == 1 && curr > INT_MAX) return INT_MAX;
    if (sign == -1 && -curr < INT_MIN) return INT_MIN;
    return parse_digit(s, i + 1, sign, curr);
}

int myAtoi(string s) {
    int sign = 1;
    int start = skip_spaces(s, 0);
    start = is_sign(s, start, sign);
    long long curr = parse_digit(s, start, sign, 0);
    curr = sign * curr;
    return (int) curr;
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
