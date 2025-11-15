#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    int n = s.size();
    vector<int> freq(3, 0);  // frequency of 'a','b','c' in current window
    int left = 0, count = 0, ans = 0;

    for (int right = 0; right < n; right++) {
        // expand window: include s[right]
        if (freq[s[right] - 'a'] == 0) count++;  
        freq[s[right] - 'a']++;

        // if window has all 3 chars, try shrinking
        while (count == 3) {
            // Every substring that starts at 'left' or before 
            // and ends at 'right' is valid.
            // Number of such substrings = (n - right)
            ans += (n - right);

            // shrink from left
            freq[s[left] - 'a']--;
            if (freq[s[left] - 'a'] == 0) count--; // lost one unique char
            left++;
        }
    }
    return ans;
}

int main() {
    cout << numberOfSubstrings("abcabc") << "\n"; // expected 10
    cout << numberOfSubstrings("aaacb") << "\n";  // expected 3
    cout << numberOfSubstrings("abc") << "\n";    // expected 1
    cout << numberOfSubstrings("aaaa") << "\n";   // expected 0
    return 0;
}
