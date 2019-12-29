static const auto fast=[](){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return nullptr;}();
class LRUCache {
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node() : prev(NULL), next(NULL) {}
        Node(int key, int val) : key(key), val(val), prev(NULL), next(NULL) {}
    };
    Node *head; // head->next : MRU
    Node *tail; // tail->prev : LRU
    int cache_capacity;
    unordered_map<int, Node*> cache; // unordered_map of key to Node*
    void remove(Node* node) {
        // remove from  old location
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    void push(Node* node) {
        // insert to the head
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
    }
public:
    LRUCache(int capacity) : cache_capacity(capacity), head(new Node(0, 0)), tail(new Node(9, 9)) {
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        auto iter = cache.find(key);
        if (iter == cache.end()) {
            return -1;
        }
        else {
            Node* node = iter->second;
            remove(node);
            push(node);
            return node->val;
        }
    }
    void put(int key, int value) {
        auto iter = cache.find(key);
        Node* node;
        if (iter == cache.end()) {
            if (cache.size() == cache_capacity) {
                // remove lru
                node = tail->prev;
                remove(node);
                cache.erase(node->key);
                // reuse the old node
                node->key = key;
                node->val = value;
            }
            else {
                node = new Node(key, value);
            }
            cache.emplace(key, node);
        }
        else {
            node = iter->second;
            remove(node);
            node->val = value;
        }
        push(node);
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
