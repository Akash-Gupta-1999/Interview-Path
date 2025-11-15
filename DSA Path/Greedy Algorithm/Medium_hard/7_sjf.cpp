#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid; // Process ID
    int at;  // Arrival Time
    int bt;  // Burst Time
};

struct comp {
    bool operator()(Process p1, Process p2) {
        return p1.at < p2.at; 
    }
};

void findWaitingTime(vector<Process>& processes, vector<int>& wt) {
    int n = processes.size();
    int time = 0, completed = 0;

    // Sort processes by arrival time first
    sort(processes.begin(), processes.end(), comp());

    // Min-heap (based on burst time)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // {burst_time, index}

    int i = 0; // index for processes
    while (completed < n) {
        // Push all processes that have arrived by 'time'
        while (i < n && processes[i].at <= time) {
            pq.push({processes[i].bt, i});
            i++;
        }

        if (pq.empty()) {
            time = processes[i].at; // jump to next process arrival
            continue;
        }

        // Pick shortest burst process
        auto [bt, idx] = pq.top(); pq.pop();
        wt[idx] = time - processes[idx].at;  // waiting time
        time += processes[idx].bt;
        completed++;
    }
}

// Turnaround Time
void findTurnAroundTime(vector<Process>& processes, vector<int>& wt, vector<int>& tat) {
    for (int i = 0; i < processes.size(); i++)
        tat[i] = wt[i] + processes[i].bt - processes[i].at;
}

// Driver
int main() {
    vector<Process> processes1 = {{0,0,7},{1,2,4},{2,4,1},{3,5,4}};
    vector<int> wt1(processes1.size(), 0);
    vector<int> tat1(processes1.size(), 0);

    findWaitingTime(processes1, wt1);
    findTurnAroundTime(processes1, wt1, tat1);

    cout << "Test 1\n";
    for (int i = 0; i < processes1.size(); i++) {
        cout << "P" << i << " WT=" << wt1[i] << " TAT=" << tat1[i] << endl;
    }

    vector<Process> processes2 = {{0,1,6},{1,1,8},{2,2,7},{3,3,3}};
    vector<int> wt2(processes2.size(), 0);
    vector<int> tat2(processes2.size(), 0);

    findWaitingTime(processes2, wt2);
    findTurnAroundTime(processes2, wt2, tat2);

    cout << "\nTest 2\n";
    for (int i = 0; i < processes2.size(); i++) {
        cout << "P" << i << " WT=" << wt2[i] << " TAT=" << tat2[i] << endl;
    }

    return 0;
}
