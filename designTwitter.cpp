class Twitter
{
    unordered_map<int, unordered_set<int>> follower_followee;
    list<pair<int, int>> tweets; // userId, tweetId
public:
    /** Initialize your data structure here. */
    Twitter()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        follower_followee[userId].insert(userId);
        tweets.push_front(make_pair(userId, tweetId));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<int> ret;
        int i = 0;

        for (auto &t : tweets) {
            if (follower_followee[userId].find(t.first) != follower_followee[userId].end()) {
                ret.push_back(t.second);

                if (ret.size() == 10) {
                    break;
                }
            }
        }

        return ret;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        follower_followee[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        if (followerId != followeeId) {
            follower_followee[followerId].erase(followeeId);
        }
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
