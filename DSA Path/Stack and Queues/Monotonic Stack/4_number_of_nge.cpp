#include <bits/stdc++.h>
using namespace std;

// 🔧 Function to implement // O(n*n)
vector<int> countNextGreaterToRight(vector<int>& nums) {
    vector<int> ans(nums.size(),0);
    stack<int> st,temp;
    for(int i = nums.size()-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums[i]){
            temp.push(st.top());
            st.pop();
        }
        ans[i] = st.size();
        st.push(nums[i]);
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
    return ans;
}

// Optimized O(nlogn) : Merge sort

void sorting(vector<pair<int,int>>& nums, int low, int mid,int high, vector<int>& ans){
    vector<pair<int,int>> left,right;
    for(int i=low;i<=mid;i++)
        left.push_back(nums[i]);
    for(int i=mid+1;i<=high;i++)
        right.push_back(nums[i]);
    int n1 = left.size(), n2 = right.size();
    int i = 0, j = 0, k = low;
    while(i<n1 && j<n2){
        if(left[i] < right[j]){
            ans[left[i].second]+= n2-j;
            nums[k] = left[i];
            k++;
            i++;
        }else{
            nums[k] = right[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        nums[k] = left[i];
        i++;
        k++;
    }
    while(j<n2){
        nums[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(vector<pair<int,int>>& nums, int low, int high, vector<int>& ans){
    if(low>=high)
        return;
    int mid = low + (high-low)/2;
    mergesort(nums,low,mid,ans);
    mergesort(nums,mid+1,high,ans);
    sorting(nums,low,mid,high,ans);
}

vector<int> opt_countNextGreaterToRight(vector<int>& nums) {
    vector<int> ans(nums.size(),0);
    vector<pair<int,int>> idx_nums;
    for(int i=0;i<nums.size();i++)
        idx_nums.push_back({nums[i],i});
    mergesort(idx_nums,0,nums.size()-1,ans);
    return ans;
}

int main() {
    // Test case 1
    vector<int> nums1 = {4, 5, 2, 10, 8};
    vector<int> res1 = countNextGreaterToRight(nums1);
    cout << "Input: {4, 5, 2, 10, 8}\nOutput: ";
    for (int x : res1) cout << x << " ";
    cout << "\n";
    vector<int> res11 = opt_countNextGreaterToRight(nums1);
    cout << "Input: {4, 5, 2, 10, 8}\nopt_Output: ";
    for (int x : res11) cout << x << " ";
    cout << "\n\n";

    // Test case 2
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> res2 = countNextGreaterToRight(nums2);
    cout << "Input: {1, 2, 3, 4}\nOutput: ";
    for (int x : res2) cout << x << " ";
    cout << "\n";
    vector<int> res21 = opt_countNextGreaterToRight(nums2);
    cout << "Input: {1, 2, 3, 4}\nopt_Output: ";
    for (int x : res21) cout << x << " ";
    cout << "\n\n";

    // Test case 3
    vector<int> nums3 = {6, 5, 4, 3};
    vector<int> res3 = countNextGreaterToRight(nums3);
    cout << "Input: {6, 5, 4, 3}\nOutput: ";
    for (int x : res3) cout << x << " ";
    cout << "\n";
    vector<int> res31 = opt_countNextGreaterToRight(nums3);
    cout << "Input: {6, 5, 4, 3}\nopt_Output: ";
    for (int x : res31) cout << x << " ";
    cout << "\n";

    return 0;
}
