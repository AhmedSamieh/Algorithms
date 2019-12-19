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
    vector<vector<int>> ds;
    void scan(TreeNode* node, int level) {
        if (ds.size() <= level) {
            ds.emplace_back(1, node->val);
        }
        else {
            /*if (level & 1) {
                ds[level].insert(ds[level].begin(), node->val);// not the best
            }
            else {
                ds[level].push_back(node->val);
            }*/
            ds[level].push_back(node->val);
        }
        if (NULL != node->left) {
            scan(node->left, level + 1);
        }
        if (NULL != node->right) {
            scan(node->right, level + 1);
        }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (NULL != root) {
            scan(root, 0);
        }
        for (int i = 0; i < ds.size(); ++i) {
            if (i & 1) {
                reverse(ds[i].begin(), ds[i].end());
            }
        }
        return ds;
    }
};