/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (NULL == node)
        {
            return NULL;
        }
        unordered_map<Node*, Node*> m;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* n = q.front();
            q.pop();
            if (m.find(n) == m.end()) {
                Node* cloned_node = new Node();
                cloned_node->val = n->val;
                m.insert(make_pair(n, cloned_node));
                for (auto &neighbor : n->neighbors) {
                    if (m.find(neighbor) == m.end()) {
                        q.push(neighbor);
                    }
                }
            }
        }
        for (auto &n : m)
        {
            for (auto &neighbor : n.first->neighbors)
            {
                n.second->neighbors.push_back(m[neighbor]);
            }
        }
        return m[node];
    }
};