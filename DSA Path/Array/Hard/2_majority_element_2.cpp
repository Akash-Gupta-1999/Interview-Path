#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums, int k) {
    vector<int> ans;
    unordered_map<int, int> candidates;
    for(int i=0;i<nums.size();i++){
        if(candidates.count(nums[i]))
            candidates[nums[i]]++;
        else if(candidates.size() < k-1)  // for (n/k) times there should be atmost (k-1) keys
            candidates[nums[i]] = 1;
        else{
            for(auto it = candidates.begin();it!=candidates.end();){
                if(--(it->second) == 0){
                    it = candidates.erase(it);
                }else
                    it++;
            }
        }
    }
    unordered_map<int,int> freq;
    for(int i=0;i<nums.size();i++){
        if(candidates.count(nums[i])){
            freq[nums[i]]++;
        }
    }
    for(auto it = freq.begin(); it!=freq.end();it++){
        if(it->second > (nums.size()/k))
            ans.push_back(it->first);
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 3, 3, 2, 1, 2, 4};
    int k = 3;
    vector<int> ans = majorityElement(arr,k);
    for(auto it : ans)
        cout << it << " ";
    cout<<endl;
    return 0;
}