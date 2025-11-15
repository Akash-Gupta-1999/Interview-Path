#include <bits/stdc++.h>
using namespace std;

/*
Intuition:
- Sort both arrays in descending order.
- The max sum comes from picking top elements of A and B.
- Use a max-heap to always extract next largest sum.
- From (i,j), the next candidates are (i+1,j) and (i,j+1).
- Use a set to avoid duplicates.
- Extract top N sums.
Time Complexity: O(N log N), Space: O(N)
*/

vector<int> maxSumCombinations(vector<int>& A, vector<int>& B, int N) {
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    priority_queue<pair<int, pair<int,int>>> pq;
    set<pair<int,int>> s;

    // initial pair (0,0)
    pq.push({A[0] + B[0], {0,0}});
    s.insert({0,0});

    vector<int> result;
    for(int k = 0; k < N; k++) {
        auto top = pq.top(); pq.pop();
        int sum = top.first;
        int i = top.second.first;
        int j = top.second.second;
        result.push_back(sum);

        // push (i+1, j)
        if(i+1 < N && s.find({i+1, j}) == s.end()) {
            pq.push({A[i+1] + B[j], {i+1, j}});
            s.insert({i+1, j});
        }
        // push (i, j+1)
        if(j+1 < N && s.find({i, j+1}) == s.end()) {
            pq.push({A[i] + B[j+1], {i, j+1}});
            s.insert({i, j+1});
        }
    }
    return result;
}

int main() {
    vector<int> A, B;
    int N;

    // Testcase 1
    A = {1, 4, 2, 3}; B = {2, 5, 1, 6}; N = 4;
    auto ans1 = maxSumCombinations(A, B, N);
    cout << "TC1: "; for(int x: ans1) cout << x << " "; cout << "\n"; 
    // Expected: 10 9 9 8

    // Testcase 2
    A = {1, 2}; B = {3, 4}; N = 2;
    auto ans2 = maxSumCombinations(A, B, N);
    cout << "TC2: "; for(int x: ans2) cout << x << " "; cout << "\n";
    // Expected: 6 5

    // Testcase 3
    A = {10, 20, 30}; B = {1, 2, 3}; N = 3;
    auto ans3 = maxSumCombinations(A, B, N);
    cout << "TC3: "; for(int x: ans3) cout << x << " "; cout << "\n";
    // Expected: 33 32 31

    // Testcase 4
    A = {5, 5, 5}; B = {5, 5, 5}; N = 3;
    auto ans4 = maxSumCombinations(A, B, N);
    cout << "TC4: "; for(int x: ans4) cout << x << " "; cout << "\n";
    // Expected: 10 10 10

    // Testcase 5
    A = {1}; B = {2}; N = 1;
    auto ans5 = maxSumCombinations(A, B, N);
    cout << "TC5: "; for(int x: ans5) cout << x << " "; cout << "\n";
    // Expected: 3
}
