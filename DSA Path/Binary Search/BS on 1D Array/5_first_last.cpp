#include<bits/stdc++.h>

using namespace std;

int firstoccurence(vector<int> arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == x) {
            ans = mid;
            high = mid-1;
        }
        else if(arr[mid] > x) {
            high = mid - 1; 
        }else
            low = mid+1;
    }
    return ans;
}

int lastoccurence(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == x) {
            ans = mid;
            low = mid+1;
        }
        else if(arr[mid] > x) {
            high = mid - 1; 
        }else
            low = mid+1;
    }
    return ans;
}

int main() {
  int target = 13;
  int first,last;
  vector < int > v = {3,4,13,13,13,20,40};
  first = firstoccurence(v,target,v.size());
  if(first == v.size()){
    first = -1;
    last = -1;
  }else{
    last = lastoccurence(v,target,v.size());
  }
  cout<<first<<","<<last<<endl;
  cout<<"count of target is :"<<last-first+1<<endl;
  return 0;
}