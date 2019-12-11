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
class Solution {
    void connect(Node* l, Node* r) {
        if (NULL != l)
        {
            l->next = r;
            connect(l->left, l->right);
            if (NULL != r)
            {
                connect(l->right, r->left);
            }
        }
        if (NULL != r)
        {
            connect(r->left, r->right);
        }
    }
public:
    Node* connect(Node* root) {
        connect(root, NULL);
        return root;
    }
};