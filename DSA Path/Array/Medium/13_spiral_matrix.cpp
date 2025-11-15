#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int i_top = 0, i_bottom = matrix.size(), j_left = 0, j_right = matrix[0].size();
    vector<int> ans;
    while(i_top < i_bottom && j_left < j_right){
        for(int j=j_left;j<j_right;j++){
            ans.push_back(matrix[i_top][j]);
        }
        i_top++;
        for(int i = i_top;i<i_bottom;i++){
            ans.push_back(matrix[i][j_right-1]);
        }
        j_right--;
        // for m * n where rows are less and cols are more
        if(i_top < i_bottom) {
            for(int j = j_right - 1; j >= j_left; j--)
                ans.push_back(matrix[i_bottom - 1][j]);
            i_bottom--;
        }
        // for m * n where cols are less and rows are more
        if(j_left < j_right) {
            for(int i = i_bottom - 1; i >= i_top; i--)
                ans.push_back(matrix[i][j_left]);
            j_left++;
        }
    } 
    return ans;
}

int main() {
    
  //Matrix initialization.
  vector<vector<int>> mat   {{1, 2, 3, 4},
                             {5, 6, 7, 8},
	                         {9, 10, 11, 12},
		                     {13, 14, 15, 16}};
		                     
  vector<int> ans = spiralOrder(mat);

  for(int i = 0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  
  return 0;
}