#include <bits/stdc++.h>
using namespace std;

// Struct to hold meeting data
struct Meeting {
    int start, end;
};

// Comparator struct for sorting
// 🔹 Intuition: We want the meeting that ends earliest first,
// because it leaves the room free for maximum upcoming meetings
struct MeetingComparator {
    bool operator()(const Meeting &a, const Meeting &b) const {
        return a.end < b.end;
    }
};

int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<Meeting> meetings(n);

    for (int i = 0; i < n; i++) {
        meetings[i] = {start[i], end[i]};
    }

    // 🔹 Step 1: Sort meetings by end time using comparator struct
    sort(meetings.begin(), meetings.end(), MeetingComparator());

    int count = 1;                  // Always select the first meeting
    int lastEnd = meetings[0].end;  // Track end time of last chosen meeting

    // 🔹 Step 2: Traverse remaining meetings
    for (int i = 1; i < n; i++) {
        // If meeting starts after the last one ended → select it
        if (meetings[i].start > lastEnd) {
            count++;
            lastEnd = meetings[i].end; // Update last end
        }
        // Else → overlapping → skip
    }

    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    cout << "Maximum number of meetings: "
         << maxMeetings(start, end) << endl;

    // Extra test case
    vector<int> start2 = {1, 2, 3};
    vector<int> end2   = {2, 3, 4};
    cout << "Maximum number of meetings: "
         << maxMeetings(start2, end2) << endl;

    return 0;
}
