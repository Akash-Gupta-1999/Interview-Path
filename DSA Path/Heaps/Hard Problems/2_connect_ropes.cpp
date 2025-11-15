#include <bits/stdc++.h>
using namespace std;

int connectSticks(vector<int>& sticks) {
    int cost = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int num : sticks)
        pq.push(num);
    while(pq.size() > 1){
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        cost += first + second;
        pq.push(first+second);
    }
    return cost;
}

int main() {
    vector<vector<int>> testcases = {
        {2, 4, 3},        // Expected: 14
        {1, 8, 3, 5},     // Expected: 30
        {5},              // Expected: 0
        {5, 5, 5, 5}      // Expected: 40
    };

    for (auto& sticks : testcases) {
        cout << connectSticks(sticks) << "\n";
    }
    return 0;
}
