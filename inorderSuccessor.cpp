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
    TreeNode* getMostLeft(TreeNode* node)
    {
        if (NULL != node)
        {
            while (NULL != node->left)
            {
                node = node->left;
            }
        }
        return node;
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (NULL == root || NULL == p)
        {
            return NULL;
        }
        if (root->val == p->val)
        {
            if (NULL != p->right && NULL != p->right->left)
            {
                return getMostLeft(p->right->left);
            }
            else
            {
                return p->right;
            }
        }
        else if (root->val < p->val)
        {
            return inorderSuccessor(root->right, p);
        }
        else //if (root->val > p->val)
        {
            TreeNode* node = inorderSuccessor(root->left, p);
            return NULL == node ? root : node;
        }
    }
};