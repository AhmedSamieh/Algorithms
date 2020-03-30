static const auto fast=[](){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return nullptr;}();
class LFUCache {
    class Node {
        int _key;
        int _val;
        int _freq;
    public:
        Node() : _key(0), _val(0), _freq(1) {}
        Node(int key, int val) : _key(key), _val(val), _freq(1) {}
        Node(Node& node) : _key(node._key), _val(node._val), _freq(node._freq) {}
        int get_freq() const {return _freq;}
        void inc_freq() {++_freq;}
        void set_val(int val) {_val = val;}
        int get_val() const {return _val;}
        int get_key() const {return _key;}
    };
    int cache_capacity;
    int min_freq;
    unordered_map<int, list<Node>::iterator> key_node_iter; // key: node_iter
    unordered_map<int, list<Node>> freq_nodes; // freq: node list
public:
    LFUCache(int capacity) : cache_capacity(capacity) {}
    int get(int key) {
        auto iter = key_node_iter.find(key); // O(1)
        if (iter == key_node_iter.end()) {
            return -1;
        }
        else {
			// O(1)
            // move node from freq x list to freq x + 1 list
            freq_nodes[iter->second->get_freq() + 1].splice(freq_nodes[iter->second->get_freq() + 1].begin(),
                                                            freq_nodes[iter->second->get_freq()],
                                                            iter->second);
            if (freq_nodes[min_freq].size() == 0) {
                ++min_freq;
            }
            iter->second->inc_freq();
            return iter->second->get_val();
        }
    }
    void put(int key, int value) {
        if (cache_capacity > 0) {
            auto iter = key_node_iter.find(key); // O(1)
            if (iter == key_node_iter.end()) {
				// O(1)
                if (key_node_iter.size() == cache_capacity) {
                    key_node_iter.erase(freq_nodes[min_freq].back().get_key());
                    freq_nodes[min_freq].pop_back();
                }
                min_freq = 1;
                freq_nodes[min_freq].emplace_front(key, value);
                key_node_iter.emplace(key, freq_nodes[min_freq].begin());
            }
            else {
				// O(1)
                // move node from freq x list to freq x + 1 list
                freq_nodes[iter->second->get_freq() + 1].splice(freq_nodes[iter->second->get_freq() + 1].begin(),
                                                                freq_nodes[iter->second->get_freq()],
                                                                iter->second);
                if (freq_nodes[min_freq].size() == 0) {
                    ++min_freq;
                }
                iter->second->inc_freq();
                iter->second->set_val(value);
            }
        }
    }
};
