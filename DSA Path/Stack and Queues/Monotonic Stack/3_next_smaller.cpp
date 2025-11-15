#include <bits/stdc++.h>
using namespace std;

// 🔧 Function to implement
vector<int> nextSmallerElements(vector<int>& nums) {
    vector<int> ans(nums.size(),-1);
    stack<int> st; 
    for(int i = nums.size()-1;i>=0;i--){
        while(!st.empty() && st.top() >= nums[i])
            st.pop();
        if(!st.empty())
            ans[i] = st.top();
        st.push(nums[i]);
    }
    return ans;
}

int main() {
    // Test case 1
    vector<int> nums1 = {4, 8, 5, 2, 25};
    vector<int> res1 = nextSmallerElements(nums1);
    cout << "Input: {4, 8, 5, 2, 25}\nOutput: ";
    for (int x : res1) cout << x << " ";
    cout << "\n\n";

    // Test case 2
    vector<int> nums2 = {13, 7, 6, 12};
    vector<int> res2 = nextSmallerElements(nums2);
    cout << "Input: {13, 7, 6, 12}\nOutput: ";
    for (int x : res2) cout << x << " ";
    cout << "\n\n";

    // Test case 3
    vector<int> nums3 = {1, 2, 3, 4};
    vector<int> res3 = nextSmallerElements(nums3);
    cout << "Input: {1, 2, 3, 4}\nOutput: ";
    for (int x : res3) cout << x << " ";
    cout << "\n";

    return 0;
}
