/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define LONG_LONG_MIN (1 << ((8 * sizeof(long long)) - 1))
#define LONG_LONG_MAX (LONG_LONG_MIN - 1)
class Solution {
    bool isValidBST(TreeNode* root, long long max_val, long long min_val) {
        if (NULL == root || (NULL == root->right && NULL == root->left))
        {
            return true;
        }
        if (NULL != root->right)
        {
            if (root->right->val <= root->val || static_cast<long long>(root->right->val) >= max_val)
            {
                return false;
            }
        }
        if (NULL != root->left)
        {
            if (root->left->val >= root->val || static_cast<long long>(root->left->val) <= min_val)
            {
                return false;
            }
        }
        return isValidBST(root->left, root->val, min_val) && isValidBST(root->right, max_val, root->val);
    }
    long long getMax(TreeNode* root)
    {
        if (NULL == root)
        {
            return 0;
        }
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root->val;
    }
    long long getMin(TreeNode* root)
    {
        if (NULL == root)
        {
            return 0;
        }
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root->val;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, getMax(root) + 1, getMin(root) - 1);
    }
};