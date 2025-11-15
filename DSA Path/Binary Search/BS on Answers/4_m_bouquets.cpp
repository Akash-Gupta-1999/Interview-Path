#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& flow, int m, int k,int mid){
    int start = 0, end = 0;
    while(end<flow.size()){
        while(end < flow.size() && flow[end] <= mid) end++;
        int temp = end - start;
        m = m - (temp/k);
        start = end + 1;
        end = start;            
    }
    if(m <= 0)
        return true;
    return false;
}
int roseGarden(vector<int> arr, int k, int m) {
    long long val = m * 1ll * k * 1ll;
    int n = arr.size(); //size of the array
    if (val > n) return -1; //impossible case.
    //find maximum and minimum:
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    //apply binary search:
    int low = mini, high = maxi;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(arr, m, k, mid)) {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}