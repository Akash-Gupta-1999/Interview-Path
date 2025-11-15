#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
    int timer = 0;
    unordered_map<int,unordered_set<int>> followers;
    unordered_map<int,vector<pair<int,int>>> tweets;
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        followers[userId].insert(userId); // self follow
        tweets[userId].push_back({++timer,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        followers[userId].insert(userId);
        struct node {
            int time;
            int tweetid;
            int uid;
            int idx;
        };
        struct cmp {
            bool operator()(const node& a, const node& b) {
                return a.time < b.time; // max heap
            }
        };
        
        priority_queue<node,vector<node>,cmp> pq;
        
        // push latest tweet of each followee
        for(int fid : followers[userId]) {
            int i = tweets[fid].size() - 1;
            if(i >= 0) {
                auto &twt = tweets[fid][i];
                pq.push({twt.first,twt.second,fid,i-1});
            }
        }
        
        // extract up to 10 most recent
        while(!pq.empty() && ans.size() < 10) {
            auto top = pq.top(); pq.pop();
            ans.push_back(top.tweetid);
            if(top.idx >= 0) {
                auto &twt = tweets[top.uid][top.idx];
                pq.push({twt.first,twt.second,top.uid,top.idx-1});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
        followers[followerId].insert(followerId); // always follow self
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            followers[followerId].erase(followeeId);
        }
    }
};

int main() {
    Twitter twitter;

    // Test 1: User 1 posts tweet
    twitter.postTweet(1, 5);
    auto feed1 = twitter.getNewsFeed(1);
    cout << "Feed for user 1: ";
    for (int t : feed1) cout << t << " ";
    cout << "\n"; // Expected: 5

    // Test 2: User 1 follows user 2
    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    auto feed2 = twitter.getNewsFeed(1);
    cout << "Feed for user 1 after following 2: ";
    for (int t : feed2) cout << t << " ";
    cout << "\n"; // Expected: 6 5

    // Test 3: User 1 unfollows user 2
    twitter.unfollow(1, 2);
    auto feed3 = twitter.getNewsFeed(1);
    cout << "Feed for user 1 after unfollowing 2: ";
    for (int t : feed3) cout << t << " ";
    cout << "\n"; // Expected: 5

    // Test 4: Multiple tweets, more than 10
    for (int i = 100; i < 120; i++) {
        twitter.postTweet(1, i);
    }
    auto feed4 = twitter.getNewsFeed(1);
    cout << "Feed for user 1 (should show latest 10 tweets): ";
    for (int t : feed4) cout << t << " ";
    cout << "\n"; // Expected: 119 down to 110

    return 0;
}
