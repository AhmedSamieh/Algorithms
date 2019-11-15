/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL)
        {
            if (p == q)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if (p->val != q->val)
        {
            return false;
        }
        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL || t == NULL)
        {
            if (s == t)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return isSameTree(s, t) || isSubtree(s->right, t) || isSubtree(s->left, t);
    }
};
