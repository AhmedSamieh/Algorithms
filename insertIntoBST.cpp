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
public:
    void insertIntoBSTHelper(TreeNode* node, int val) {
        if (node->val <= val)
        {
            if (NULL == node->right)
            {
                node->right = new TreeNode(val);
            }
            else
            {
                insertIntoBSTHelper(node->right, val);
            }
        }
        else
        {
            if (NULL == node->left)
            {
                node->left = new TreeNode(val);
            }
            else
            {
                insertIntoBSTHelper(node->left, val);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (NULL == root)
        {
            return new TreeNode(val);
        }
        insertIntoBSTHelper(root, val);
        return root;
    }
};