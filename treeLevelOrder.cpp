/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    vector<vector<int>> ds;
    void scan(TreeNode *node, int level)
    {
        if (ds.size() <= level) {
            ds.emplace_back(1, node->val);
        } else {
            ds[level].push_back(node->val);
        }

        if (NULL != node->left) {  // order matter
            scan(node->left, level + 1);
        }

        if (NULL != node->right) {
            scan(node->right, level + 1);
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (NULL != root) {
            scan(root, 0);
        }

        return ds;
    }
};