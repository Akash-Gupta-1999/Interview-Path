#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char,int> freq;
    int left = 0, ans = 0;

    for(int right = 0; right < s.size(); right++) {
        freq[s[right]]++;

        // shrink window if distinct chars > k
        while(freq.size() > k) {
            freq[s[left]]--;
            if(freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }

        ans = max(ans, right - left + 1);
    }
    return ans;
}

int main() {
    cout << "Test1: " << lengthOfLongestSubstringKDistinct("eceba", 2) << " (Expected 3)\n"; 
    cout << "Test2: " << lengthOfLongestSubstringKDistinct("aa", 1) << " (Expected 2)\n";
    cout << "Test3: " << lengthOfLongestSubstringKDistinct("a", 1) << " (Expected 1)\n";
    cout << "Test4: " << lengthOfLongestSubstringKDistinct("abcadcacacaca", 3) << " (Expected 11)\n";
    cout << "Test5: " << lengthOfLongestSubstringKDistinct("abcabcabc", 2) << " (Expected 2)\n";
    return 0;
}
