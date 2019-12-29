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
    int kthSmallestHelper(TreeNode* node, int& k) {
        if (NULL == node) {
            return 0;
        }
        int ret = kthSmallestHelper(node->left, k);
        if (k == 0) {
            return ret;
        }
        --k;
        if (k > 0) {
            return kthSmallestHelper(node->right, k);
        }
        return node->val;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallestHelper(root, k);
    }
};