class LRUCache
{
    int cache_capacity;
    list<int> order; // key
    unordered_map<int, pair<int, list<int>::iterator> > cache; // cach[key] = pair<value, order.iterator>
public:
    LRUCache(int capacity) : cache_capacity(capacity)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    int get(int key)
    {
        auto iter = cache.find(key);
        if (iter == cache.end())
        {
            return -1;
        }
        else
        {
            order.splice(order.end(), order, iter->second.second);
            return iter->second.first;
        }
    }
    void put(int key, int value)
    {
        auto iter = cache.find(key);
        if (iter == cache.end())
        {
            if (cache.size() == cache_capacity)
            {
                cache.erase(order.front());
                order.pop_front();
            }
            cache.emplace(key, make_pair(value, order.insert(order.end(), key)));
        }
        else
        {
            iter->second.first = value;
            order.splice(order.end(), order, iter->second.second);
        }
    }
};
