#include <bits/stdc++.h>
using namespace std;

// Optimized Greedy formula solution
int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char,int> freq;
    for (char t : tasks) freq[t]++;

    int maxFreq = 0, countMax = 0;
    for (auto &p : freq) {
        if (p.second > maxFreq) {
            maxFreq = p.second;
            countMax = 1;
        } else if (p.second == maxFreq) {
            countMax++;
        }
    }

    // Intuition:
    // - (maxFreq - 1) full blocks of size (n+1)
    // - Each block = one task with max frequency + n idle slots
    // - Finally add all tasks that have max frequency (countMax)
    // - Take max with total tasks, because if tasks can fill idle slots,
    //   no extra idle time is needed.
    return max((int)tasks.size(), (maxFreq - 1) * (n + 1) + countMax);
}

int main() {
    vector<vector<char>> testcases = {
        {'A','A','A','B','B','B'}, // Expected: 8
        {'A','A','A','B','B','B','C','C','D'}, // Expected: 9
        {'A','A','A','A','B','C','D','E'}, // Expected: 10
        {'A','A','A'}, // Expected: 7 if n=2
    };
    vector<int> coolDowns = {2, 2, 2, 2};

    for (int i = 0; i < testcases.size(); i++) {
        cout << "Testcase " << i+1 << ": " 
             << leastInterval(testcases[i], coolDowns[i]) << "\n";
    }
}
