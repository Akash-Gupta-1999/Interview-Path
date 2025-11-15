#include<bits/stdc++.h>
using namespace std;

//O(n+m)
int rowWithMax1s_opt(vector<vector<int>>& matrix, int n, int m) {
    int max_row_index = -1;
    int j = m - 1; // start from top-right corner

    for (int i = 0; i < n; i++) {
        while (j >= 0 && matrix[i][j] == 1) {
            j--;
            max_row_index = i;
        }
    }

    return max_row_index;
}

int lower_bound(vector<int>& arr, int n){
    int low = 0, high = n-1, ans = n;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] == 1){
            ans = mid;
            high = mid-1;
        }else
            low = mid + 1;
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>>& matrix, int n,int m){
    int ans = n, res = -1;
    for(int i=0;i<m;i++){
        int pos = lower_bound(matrix[i],n);
        if(ans > pos){
            ans = pos;
            res = i;
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> matrix = {{0, 0, 0, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1}};
    int n = 6, m = 3;
    cout << "The row with maximum no. of 1's is: " <<
         rowWithMax1s(matrix, n, m) << '\n';
    cout << "The row with maximum no. of 1's is: " <<
         rowWithMax1s_opt(matrix, n, m) << '\n';
}