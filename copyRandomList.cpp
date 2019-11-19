/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m; // key=oldPointer, val=newPointer
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        m.insert(make_pair<Node*, Node*>(NULL, NULL));
        for (Node* scanner = head; scanner != NULL; scanner = scanner->next)
        {
            Node* node = new Node();
            m.insert(make_pair(scanner, node));
        }
        for (auto const &i : m)
        {
            if (i.first != NULL)
            {
                i.second->val = i.first->val;
                i.second->next = m[i.first->next];
                i.second->random = m[i.first->random];
            }
        }
        return m[head];
    }
};
