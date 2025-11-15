#include <bits/stdc++.h>
using namespace std;

int minPlatforms(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int n = arr.size();
    int i = 0, j = 0;     // pointers for arrival and departure
    int platforms = 0;    // current platforms needed
    int maxPlatforms = 0; // answer

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            // New train arrives before earliest departs → need new platform
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
            i++;
        } else {
            // A train departs → free a platform
            platforms--;
            j++;
        }
    }
    return maxPlatforms;
}

/*
🔹 Intuition:
- Sort arrival and departure times.
- Traverse like merge process:
   - If arrival <= departure → train overlaps → need extra platform.
   - Else → departure frees a platform.
- Track maximum platforms needed at any point.
- Time: O(n log n) [sorting], Space: O(1).
*/

int main() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    cout << "Minimum number of platforms required: "
         << minPlatforms(arr, dep) << endl;

    // Extra test cases
    vector<int> arr2 = {900, 1100, 1235};
    vector<int> dep2 = {1000, 1200, 1240};
    cout << "Minimum number of platforms required: "
         << minPlatforms(arr2, dep2) << endl;

    vector<int> arr3 = {100, 200, 300, 400};
    vector<int> dep3 = {200, 300, 400, 500};
    cout << "Minimum number of platforms required: "
         << minPlatforms(arr3, dep3) << endl;

    return 0;
}
