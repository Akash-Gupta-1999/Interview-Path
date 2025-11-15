#include <bits/stdc++.h>
using namespace std;

long long limit(string s) {
    vector<int> hash(3, 0);
    int left = 0, count = 0;
    long long ans = 0;  // keep as long long for safety

    for (int i = 0; i < s.size(); i++) {
        if (hash[s[i] - 'a'] == 0)
            count++;
        hash[s[i] - 'a']++;

        while (count == 3) {
            if (--hash[s[left] - 'a'] == 0)
                count--;
            left++;
        }
        ans += (i - left + 1);
    }
    return ans;
}

int numberOfSubstrings(string s) {
    long long n = s.size();
    long long total = (n * (n + 1LL)) / 2; // compute safely
    return static_cast<int>(total - limit(s)); // cast back to int
}

int main() {
    cout << numberOfSubstrings("abcabc") << "\n"; // expected 10
    cout << numberOfSubstrings("aaacb") << "\n";  // expected 3
    cout << numberOfSubstrings("abc") << "\n";    // expected 1
    cout << numberOfSubstrings("aaaa") << "\n";   // expected 0
    return 0;
}
