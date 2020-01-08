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
    bool findTargetHelper(TreeNode* node, TreeNode* root, int k) {
        if (NULL == node) {
            return false;
        }
        int delta = k - node->val;
        TreeNode* iter = root;
        while (NULL != iter) {
            if (node != iter && iter->val == delta) {
                return true;
            }
            else if (iter->val >= delta) {
                iter = iter->left;
            }
            else {
                iter = iter->right;
            }
        }
        return findTargetHelper(node->right, root, k) || findTargetHelper(node->left, root, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        return findTargetHelper(root, root, k);
    }
};