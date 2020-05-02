class LRUCache
{
    int cache_capacity;
    list< pair<int, int > > order; // list of [key, values] pairs
    unordered_map<int, list< pair<int, int> >::iterator> cache; // unordered_map of key to [key, value] pairs list iterator
public:
    LRUCache(int capacity) : cache_capacity(capacity)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    int get(int key)
    {
        auto iter = cache.find(key);

        if (iter == cache.end()) {
            return -1;
        } else {
            order.splice(order.end(), order, iter->second);
            return iter->second->second;
        }
    }
    void put(int key, int value)
    {
        auto iter = cache.find(key);

        if (iter == cache.end()) {
            if (cache.size() == cache_capacity) {
                cache.erase(order.front().first);
                order.pop_front();
            }

            cache.emplace(key, order.insert(order.end(), make_pair(key, value)));
        } else {
            iter->second->second = value;
            order.splice(order.end(), order, iter->second);
        }
    }
};