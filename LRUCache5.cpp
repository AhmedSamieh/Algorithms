#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
    size_t _capacity;
    list<pair<int, int>> _list; // key, value
    unordered_map<int, list<pair<int, int>>::iterator> _key_list;
public:
    LRUCache(size_t capacity) : _capacity(capacity) {}
    int get(int key) {
        //cout << "get " << key << endl;
        auto iter = _key_list.find(key);
        if (iter != _key_list.end()) {
            _list.splice(_list.begin(), _list, iter->second);
            return iter->second->second;
        }
        return -1;
    }
    void put(int key, int value) {
        //cout << "set " << key << " : " << val << endl;
        auto iter = _key_list.find(key);
        if (iter != _key_list.end()) {
            iter->second->second = value;
            _list.splice(_list.begin(), _list, iter->second);
        }
        else {
            _list.emplace_front(key, value);
            _key_list.emplace(key, _list.begin());
            if (_list.size() > _capacity) {
                _key_list.erase(_list.back().first);
                _list.pop_back();
            }
        }
    }
};

int main(int argc, char **argv) {
    LRUCache lru(2);
    lru.put(1, 1);
    cout << lru.get(1) << endl;
    lru.put(10, 10);
    lru.put(3, 3);
    cout << lru.get(1) << endl;
    cout << lru.get(10) << endl;
    lru.put(4, 4);
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl;
    lru.put(5, 5);
    cout << lru.get(4) << endl;
    cout << lru.get(10) << endl;
    return 0;
}
