#include <bits/stdc++.h>
using namespace std;

// Job structure
struct Job {
    int id;      // Job ID
    int dead;    // Deadline
    int profit;  // Profit
};

// Comparator: sort jobs by profit descending
struct comp {
    bool operator()(Job a, Job b) {
        return a.profit > b.profit;
    }
};

// Function to find the maximum profit job sequence
vector<int> jobScheduling(vector<Job>& jobs) {
    // Step 1: sort by profit descending
    sort(jobs.begin(), jobs.end(), comp());

    // Step 2: find maximum deadline
    int maxDead = 0;
    for (auto& job : jobs)
        maxDead = max(maxDead, job.dead);

    // Step 3: slot array (-1 = free)
    vector<int> slot(maxDead + 1, -1);

    int count = 0, maxProfit = 0;

    // Step 4: schedule jobs greedily
    for (auto& job : jobs) {
        // try to schedule at latest available slot before deadline
        for (int t = job.dead; t > 0; t--) {
            if (slot[t] == -1) {
                slot[t] = job.id;
                count++;
                maxProfit += job.profit;
                break;
            }
        }
    }
    return {count, maxProfit};
}

int main() {
    // Test case 1
    vector<Job> jobs1 = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    vector<int> ans1 = jobScheduling(jobs1);
    cout << "Jobs done: " << ans1[0] << ", Profit: " << ans1[1] << endl;
    // ✅ Expected: Jobs done: 3, Profit: 142  (Jobs {1,3,5})

    // Test case 2
    vector<Job> jobs2 = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    vector<int> ans2 = jobScheduling(jobs2);
    cout << "Jobs done: " << ans2[0] << ", Profit: " << ans2[1] << endl;
    // ✅ Expected: Jobs done: 2, Profit: 60  (Jobs {3,1})

    // Test case 3
    vector<Job> jobs3 = {{1, 2, 50}, {2, 2, 60}, {3, 3, 20}};
    vector<int> ans3 = jobScheduling(jobs3);
    cout << "Jobs done: " << ans3[0] << ", Profit: " << ans3[1] << endl;
    // ✅ Expected: Jobs done: 3, Profit: 130 (Jobs {2,1,3})

    return 0;
}
