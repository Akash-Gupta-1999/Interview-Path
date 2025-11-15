#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
    vector<int> dec = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string ans = "";

    for (int i = 0; i < dec.size(); ++i) {
        while (num >= dec[i]) {
            num -= dec[i];
            ans += roman[i];
        }
    }

    return ans;
}

int main() {
    vector<int> test_cases = {
        1,      // I
        4,      // IV
        9,      // IX
        58,     // LVIII
        1994,   // MCMXCIV
        40,     // XL
        444,    // CDXLIV
        3999    // MMMCMXCIX
    };

    for (int num : test_cases) {
        cout << "Integer: " << num << " => Roman: " << intToRoman(num) << endl;
    }

    return 0;
}
