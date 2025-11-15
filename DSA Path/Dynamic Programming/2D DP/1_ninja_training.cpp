#include <bits/stdc++.h>
using namespace std;

// ===============================================
// Problem: Ninja Training
// ===============================================
// Given an n x 3 matrix 'points', where points[i][j]
// represents the merit points the Ninja can earn on day i
// for performing task j.
// The same task cannot be performed on two consecutive days.
//
// Return the maximum merit points the Ninja can earn after n days.
// ===============================================

// ------------------------
// Method 1: Top-Down (Memoization)
// ------------------------
int topdownRec(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
    if (dp[day][last] != -1) return dp[day][last];

    if (day == 0) {
        int maxi = 0;
        for (int i = 0; i < 3; i++) {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        return dp[day][last] = maxi;
    }

    int maxi = 0;
    for (int i = 0; i < 3; i++) {
        if (i != last) {
            int activity = points[day][i] + topdownRec(day - 1, i, points, dp);
            maxi = max(maxi, activity);
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraining_TopDown(int n, vector<vector<int>>& points) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return topdownRec(n - 1, 3, points, dp);
}

// ------------------------
// Method 2: Bottom-Up (Tabulation)
// ------------------------
int ninjaTraining_BottomUp(int n, vector<vector<int>>& points) {
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Base case
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    // Fill dp table
    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int activity = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }

    return dp[n - 1][3];
}

// ------------------------
// Method 3: Space Optimized
// ------------------------
int ninjaTraining_SpaceOptimized(int n, vector<vector<int>>& points) {
    vector<int> prev(4, 0), curr(4, 0);

    // Base case
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max({points[0][0], points[0][1], points[0][2]});

    // Transition
    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            curr[last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int activity = points[day][task] + prev[task];
                    curr[last] = max(curr[last], activity);
                }
            }
        }
        prev = curr;
    }

    return prev[3];
}

// ===============================================
// Main Function with Multiple Test Cases
// ===============================================
int main() {
    vector<pair<int, vector<vector<int>>>> testCases;

    // ---------- Test Case 1 ----------
    testCases.push_back({
        3,
        {{1, 2, 5},
         {3, 1, 1},
         {3, 3, 3}}
    });

    // ---------- Test Case 2 ----------
    testCases.push_back({
        4,
        {{10, 40, 70},
         {20, 50, 80},
         {30, 60, 90},
         {40, 70, 100}}
    });

    // ---------- Test Case 3 ----------
    testCases.push_back({
        2,
        {{5, 10, 15},
         {3, 6, 9}}
    });

    // ---------- Test Case 4 ----------
    testCases.push_back({
        1,
        {{10, 50, 100}}
    });

    cout << "==============================================\n";
    cout << "              NINJA TRAINING TESTS             \n";
    cout << "==============================================\n";

    for (int t = 0; t < testCases.size(); t++) {
        int n = testCases[t].first;
        auto points = testCases[t].second;

        cout << "\nTest Case " << t + 1 << ":\n";
        cout << "Days: " << n << "\nPoints Matrix:\n";
        for (auto& row : points) {
            for (int val : row) cout << val << " ";
            cout << "\n";
        }

        int ans1 = ninjaTraining_TopDown(n, points);
        int ans2 = ninjaTraining_BottomUp(n, points);
        int ans3 = ninjaTraining_SpaceOptimized(n, points);

        cout << "----------------------------------------------\n";
        cout << "Top-Down (Memoization): " << ans1 << "\n";
        cout << "Bottom-Up (Tabulation): " << ans2 << "\n";
        cout << "Space Optimized: " << ans3 << "\n";
    }

    cout << "\n==============================================\n";
    cout << "Complexities:\n";
    cout << "Top-Down: O(N*4*3),  Space: O(N*4) + O(N Recursion)\n";
    cout << "Bottom-Up: O(N*4*3), Space: O(N*4)\n";
    cout << "Space Optimized: O(N*4*3), Space: O(4)\n";
    cout << "==============================================\n";

    return 0;
}
