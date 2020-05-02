/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution
{
    vector<vector<Node *>> ds;
    void scan(Node *node, int level)
    {
        if (ds.size() <= level) {
            ds.emplace_back(1, node);
        } else {
            ds[level].push_back(node);
        }

        if (NULL != node->left) { // order matter
            scan(node->left, level + 1);
        }

        if (NULL != node->right) {
            scan(node->right, level + 1);
        }
    }
    void connect(void)
    {
        for (auto &level : ds) {
            for (int i = 0; i < level.size() - 1; ++i) {
                level[i]->next = level[i + 1];
            }
        }
    }
public:
    Node *connect(Node *root)
    {
        if (NULL != root) {
            scan(root, 0);
            connect();
        }

        return root;
    }
};