class TimeMap {
    unordered_multimap<string, map<int, string, greater<int>>> storage;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto x = storage.find(key);
        if (x == storage.end())
        {
            map<int, string, greater<int>> m;
            x = storage.insert(make_pair(key, m));
        }
        x->second.insert(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        auto x = storage.find(key);
        if (x == storage.end())
        {
            return "";
        }
        auto y = x->second.find(timestamp);
        if (y == x->second.end())
        {
            for (y = x->second.begin(); y != x->second.end(); ++y)
            {
                if (y->first < timestamp)
                {
                    return y->second;
                }
            }
            return "";
        }
        return y->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */