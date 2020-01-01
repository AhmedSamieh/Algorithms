static const auto fast=[](){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return nullptr;}();
class LFUCache {
    int cache_capacity;
    unordered_map<int, int> key_val;
    unordered_map<int, int> key_freq;
    unordered_map<int, int> key_lru;
    int lru;
public:
    LFUCache(int capacity) : cache_capacity(capacity), lru(0) {}
    
    int get(int key) {
        auto iter = key_val.find(key);
        if (iter == key_val.end()) {
            return -1;
        }
        else {
            key_freq[key]++;
            key_lru[key] = ++lru;
            return iter->second;
        }
    }
    
    void put(int key, int value) {
        if (cache_capacity > 0) {
            auto iter = key_val.find(key);
            if (iter == key_val.end()) {
                if (key_val.size() == cache_capacity) {
                    // O(N) // find lfu item to remove
                    int lfu_key = key_freq.begin()->first;
                    for (auto &i : key_freq) {
                        if (i.second < key_freq[lfu_key] ||
                            (i.second == key_freq[lfu_key] && key_lru[i.first] < key_lru[lfu_key])) {
                            lfu_key = i.first;
                        }
                    }
                    key_val.erase(lfu_key);
                    key_freq.erase(lfu_key);
                }
            }
            key_val[key] = value;
            key_freq[key]++;
            key_lru[key] = ++lru;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */