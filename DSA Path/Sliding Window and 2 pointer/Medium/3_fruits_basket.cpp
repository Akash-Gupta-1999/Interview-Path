#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
    unordered_map<int,int> count;
    int left = 0, ans = 0;

    for(int right = 0; right < fruits.size(); right++) {
        count[fruits[right]]++;

        // shrink window if more than 2 distinct fruits
        while(count.size() > 2) {
            count[fruits[left]]--;
            if(count[fruits[left]] == 0)
                count.erase(fruits[left]);
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}

int main() {
    vector<int> f1 = {1,2,1};
    cout << totalFruit(f1) << "\n"; // expected 3

    vector<int> f2 = {0,1,2,2};
    cout << totalFruit(f2) << "\n"; // expected 3

    vector<int> f3 = {1,2,3,2,2};
    cout << totalFruit(f3) << "\n"; // expected 4

    vector<int> f4 = {3,3,3,1,2,1,1,2,3,3,4};
    cout << totalFruit(f4) << "\n"; // expected 5

    return 0;
}
