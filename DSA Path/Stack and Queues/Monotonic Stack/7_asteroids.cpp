#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;

    for (int a : asteroids) {
        bool destroyed = false;

        // Only possible collision: a negative asteroid vs positive on stack
        while (!st.empty() && a < 0 && st.top() > 0) {
            if (st.top() < -a) {
                st.pop();       // stack asteroid smaller → destroyed
                continue;       // keep checking next positive
            } else if (st.top() == -a) {
                st.pop();       // both destroyed
            }
            destroyed = true;   // current asteroid destroyed
            break;
        }

        if (!destroyed) {
            st.push(a); // survives
        }
    }

    // Collect survivors from stack
    vector<int> ans(st.size());
    for (int i = st.size() - 1; i >= 0; i--) {
        ans[i] = st.top();
        st.pop();
    }
    return ans;
}

int main() {
    vector<vector<int>> testcases = {
        {5, 10, -5},     // expected: [5,10]
        {8, -8},         // expected: []
        {10, 2, -5},     // expected: [10]
        {-2, -1, 1, 2},  // expected: [-2,-1,1,2]
        {1, -2, -2, -2}  // expected: [-2,-2,-2]
    };

    for (auto &tc : testcases) {
        cout << "Input: ";
        for (int x : tc) cout << x << " ";
        cout << "\nOutput: ";
        vector<int> res = asteroidCollision(tc);
        for (int x : res) cout << x << " ";
        cout << "\n\n";
    }

    return 0;
}
