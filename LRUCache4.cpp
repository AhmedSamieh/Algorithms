static const auto fast = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}
();
class LRUCache
{
    int cache_capacity;
    list<pair<int, int>> key_val;
    unordered_map<int, list<pair<int, int>>::iterator> cache; // unordered_map of key to list iterator
public:
    LRUCache(int capacity) : cache_capacity(capacity) {}
    int get(int key)
    {
        auto iter = cache.find(key);

        if (iter == cache.end()) {
            return -1;
        } else {
            key_val.splice(key_val.begin(), key_val, iter->second);
            return key_val.front().second;
        }
    }
    void put(int key, int value)
    {
        auto iter = cache.find(key);

        if (iter == cache.end()) {
            if (cache.size() == cache_capacity) {
                cache.erase(key_val.back().first);
                key_val.pop_back();
            }

            key_val.emplace_front(key, value);
            cache.emplace(key, key_val.begin());
        } else {
            iter->second->second = value;
            key_val.splice(key_val.begin(), key_val, iter->second);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
