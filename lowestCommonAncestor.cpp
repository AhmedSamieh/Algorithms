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
    int lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode **node)
    {
        int found = 0;

        if (NULL != root) {
            found = lowestCommonAncestor(root->left, p, q, node) + lowestCommonAncestor(root->right, p, q, node);

            if (root == p || root == q) {
                found += 1;
            }

            if (2 == found && NULL == *node) {
                *node = root;
            }
        }

        return found;
    }
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *node = NULL;
        lowestCommonAncestor(root, p, q, &node);
        return node;
    }
};