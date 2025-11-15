#include <bits/stdc++.h>
using namespace std;

int findmaxrow(vector<vector<int>>& mat, int m, int n,int col){
    int max_value = -1,max_idx = -1;
    for(int i=0;i<m;i++){
        if(mat[i][col] > max_value){
            max_value = mat[i][col];
            max_idx = i;
        }
    }
    return max_idx;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int low = 0, high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        int maxRowValue = findmaxrow(mat,m,n,mid);
        int left = mid - 1 >= 0 ? mat[maxRowValue][mid-1] : -1;
        int right = mid + 1 < n ? mat[maxRowValue][mid+1] : -1;
        if(mat[maxRowValue][mid] > left && mat[maxRowValue][mid] > right)
            return {maxRowValue,mid};
        else if(mat[maxRowValue][mid] < left)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return {-1,-1};
}

int main()
{
    vector<vector<int>> matrix = {{10,20,15},{21,30,14},{7,16,32}};
    vector<int> ans = findPeakGrid(matrix);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}