#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
class Twitter {
private:
    int count;
    map<int, vector<vector<int>>> tweet_map;
    map<int, set<int>> follow_map;
public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet_map[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> recentTweets;
        auto compare = [](const pair<int, int> &a, const pair<int, int> &b){
            return a.first < b.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> maxHeap(compare);

        follow_map[userId].insert(userId);
        for(auto & followerId : follow_map[userId]) {
            if(tweet_map.count(followerId)){
                vector<vector<int>>& tweets = tweet_map[followerId];
                for(auto & tweet: tweets) {
                    maxHeap.push({tweet[0], tweet[1]});
                }
            }
        }
        int k = 10;
        while(k >0 && !maxHeap.empty()) {
            recentTweets.push_back(maxHeap.top().second);
            maxHeap.pop();
            k--;
        }


        return recentTweets;
        
    }
    
    void follow(int followerId, int followeeId) {
        follow_map[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        follow_map[followerId].erase(followeeId);
    }
};
int main() {
    Twitter twitter;

    // 使用者 1 發佈推文
    twitter.postTweet(1, 101);
    twitter.postTweet(1, 102);
    
    // 使用者 2 發佈推文
    twitter.postTweet(2, 201);
    
    // 使用者 1 關注使用者 2
    twitter.follow(1, 2);

    // 獲取使用者 1 的動態消息
    vector<int> newsFeed1 = twitter.getNewsFeed(1);
    cout << "User 1's news feed:" << endl;
    for (int tweetId : newsFeed1) {
        cout << tweetId << " ";
    }
    cout << endl;

    // 使用者 1 取消關注使用者 2
    twitter.unfollow(1, 2);

    // 再次獲取使用者 1 的動態消息
    vector<int> newsFeed2 = twitter.getNewsFeed(1);
    cout << "User 1's news feed after unfollowing:" << endl;
    for (int tweetId : newsFeed2) {
        cout << tweetId << " ";
    }
    cout << endl;

    return 0;
}
