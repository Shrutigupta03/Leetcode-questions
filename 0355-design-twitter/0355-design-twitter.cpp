class Twitter {
public:
    
      vector<pair<int,int>> v;
    unordered_map<int,unordered_map<int,int>> m;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        v.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> n;
        int count = 0;
        for(int i=v.size()-1;i>=0;i--){
            if(count>9){
                break;
            }
            if(v[i].first == userId || m[userId][v[i].first] == 1){
                n.push_back(v[i].second);
                count++;
            }
        }
        return n;
    }
    
    void follow(int followerId, int followeeId) {
        m[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        m[followerId][followeeId] = 0;
    }

};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */