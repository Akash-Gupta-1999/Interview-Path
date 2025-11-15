#include <bits/stdc++.h>
using namespace std;

bool searchMatrix_opt(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    //apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m; // this is the case 
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

// My Approach

bool binary_search(vector<int>& arr, int target){
    int low = 0, high = arr.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target)
            return true;
        else if(arr[mid] > target)
            high = mid -1;
        else
            low = mid + 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int low = 0, high = m-1, ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(matrix[mid][0] <= target){
            ans = mid;
            low = mid+1;
        }else
            high = mid-1;
    }
    if(ans  == -1)
        return false;
    return binary_search(matrix[ans],target);
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
    searchMatrix_opt(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}