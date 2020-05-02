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
    TreeNode *constructMaximumBinaryTreeHelper(vector<int>::iterator iter_from, vector<int>::iterator iter_to)
    {
        TreeNode *node;

        if (iter_from == iter_to) {
            return NULL;
        }

        auto iter_max = max_element(iter_from, iter_to);
        node = new TreeNode(*iter_max);
        node->right = constructMaximumBinaryTreeHelper(next(iter_max), iter_to);
        node->left = constructMaximumBinaryTreeHelper(iter_from, iter_max);
        return node;
    }
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return constructMaximumBinaryTreeHelper(nums.begin(), nums.end());
    }
};