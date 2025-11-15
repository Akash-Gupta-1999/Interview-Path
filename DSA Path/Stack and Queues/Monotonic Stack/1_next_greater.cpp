#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> umap;
    vector<int> ans;
    stack<int> st;
    int i = 0;
    
    while (i < nums2.size()) {
        while (!st.empty() && st.top() < nums2[i]) {
            umap[st.top()] = nums2[i];
            st.pop();
        }
        st.push(nums2[i]);
        i++;
    }
    
    while (!st.empty()) {
        umap[st.top()] = -1;
        st.pop();
    }
    
    for (int i = 0; i < nums1.size(); i++) {
        ans.push_back(umap[nums1[i]]);
    }
    return ans;
}

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    
    vector<int> result = nextGreaterElement(nums1, nums2);
    
    cout << "Result for nums1 = {4,1,2}, nums2 = {1,3,4,2}: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    // Extra test case 1
    nums1 = {2, 4};
    nums2 = {1, 2, 3, 4};
    result = nextGreaterElement(nums1, nums2);
    cout << "Result for nums1 = {2,4}, nums2 = {1,2,3,4}: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    // Extra test case 2
    nums1 = {1, 3, 5};
    nums2 = {6, 5, 4, 3, 2, 1, 7};
    result = nextGreaterElement(nums1, nums2);
    cout << "Result for nums1 = {1,3,5}, nums2 = {6,5,4,3,2,1,7}: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
