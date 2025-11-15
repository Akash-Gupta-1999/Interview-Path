#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    unordered_map<string, int> umap = {
        {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50},
        {"C", 100}, {"D", 500}, {"M", 1000},
        {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90},
        {"CD", 400}, {"CM", 900}
    };
    
    int ans = 0, i = s.size() - 1;
    while (i >= 0) {
        if (i > 0) {
            string two = s.substr(i - 1, 2);
            if (umap.find(two) != umap.end()) {
                ans += umap[two];
                i -= 2;
                continue;
            }
        }
        string one(1, s[i]);
        ans += umap[one];
        i--;
    }
    return ans;
}

int main() {
    vector<string> test_cases = {
        "III",      // 3
        "IV",       // 4
        "IX",       // 9
        "LVIII",    // 58
        "MCMXCIV",  // 1994
        "XL",       // 40
        "CDXLIV",   // 444
        "MMMCMXCIX" // 3999 (largest valid Roman numeral)
    };

    for (string s : test_cases) {
        cout << "Roman: " << s << " => Integer: " << romanToInt(s) << endl;
    }

    return 0;
}
