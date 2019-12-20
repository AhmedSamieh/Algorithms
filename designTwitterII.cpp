class Twitter {
    unordered_map<int, unordered_set<int>> follower_followee;
    unordered_map<int, list<pair<unsigned long long, int>>> tweets; // userId: pair(timestamp, tweetId)
    unsigned long long timestamp;
public:
    /** Initialize your data structure here. */
    Twitter() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        timestamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_front(make_pair(timestamp++, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        map<unsigned long long, int, greater<unsigned long long>> mostRecentTweets;
        // get the 10 most recent tweet for myself
        for (auto &tweet : tweets[userId]) {
            mostRecentTweets.insert(tweet);
            if (mostRecentTweets.size() == 10) {
                break;
            }
        }
        // replace my old tweets with the latest tweets of my followee
        for (auto &user : tweets) {
            if (follower_followee[userId].find(user.first) != follower_followee[userId].end()) {
                for (auto &tweet : user.second) {
                    if (mostRecentTweets.size() < 10) {
                        mostRecentTweets.insert(tweet);
                    }
                    else {
                        if (mostRecentTweets.rbegin()->first < tweet.first) {
                            mostRecentTweets.erase(mostRecentTweets.rbegin()->first);
                            mostRecentTweets.insert(tweet);
                        }
                        else {
                            break;
                        }
                    }
                }
            }
        }
        // convert to output format
        vector<int> ret;
        for (auto &tweet : mostRecentTweets) {
            ret.push_back(tweet.second);
        }
        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follower_followee[followerId].insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        follower_followee[followerId].erase(followeeId);
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