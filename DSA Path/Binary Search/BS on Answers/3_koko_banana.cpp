#include <bits/stdc++.h>
using namespace std;

bool check(int mid, vector<int>& piles,int h){
    int x = 0;
    for(int i=0;i<piles.size();i++){
        x+=piles[i]/mid;
        if(piles[i]%mid != 0)
            x++;
        if(x>h)
            return false;
    }
    return true;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = *max_element(piles.begin(),piles.end());
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(check(mid,piles,h)){
            ans = mid;
            high = mid-1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minEatingSpeed(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}