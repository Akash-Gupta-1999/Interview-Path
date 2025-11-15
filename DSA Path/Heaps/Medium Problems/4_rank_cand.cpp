#include <bits/stdc++.h>
using namespace std;

// Steps (hint):
    // 1. Copy arr into a temp array
    // 2. Sort and remove duplicates
    // 3. Map each element to its rank
    // 4. Replace arr[i] with its rank
// Function to replace array elements by their rank
vector<int> replaceWithRank(vector<int>& arr) {
    unordered_map<int,int> order;
    vector<int> temp = arr;
    int rank = 1;
    sort(temp.begin(),temp.end());
    for(int i=0;i<temp.size();i++){
        if(order.find(temp[i]) == order.end()){
            order[temp[i]] = rank++;
        }
    }
    for(int i=0;i<arr.size();i++)
        arr[i] = order[arr[i]];
    return arr; // placeholder
}

int main() {
    vector<vector<int>> testcases = {
        {40, 10, 20, 30},       // expected: [4,1,2,3]
        {100, 100, 100},        // expected: [1,1,1]
        {37, 12, 28, 9, 100, 56, 80, 5, 12}, // expected: [5,3,4,2,9,6,8,1,3]
        {7, 7, 7, 8, 8, 9},     // expected: [1,1,1,2,2,3]
    };

    for (int t = 0; t < testcases.size(); t++) {
        auto arr = testcases[t];
        cout << "Testcase " << t+1 << ":\n";
        cout << "Original: ";
        for (int x : arr) cout << x << " ";
        cout << "\n";

        auto ranked = replaceWithRank(arr);

        cout << "Ranked:   ";
        for (int x : ranked) cout << x << " ";
        cout << "\n\n";
    }

    return 0;
}
