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
    void bstInsert(TreeNode *head, TreeNode *node)
    {
        if (node->val > head->val) {
            if (NULL == head->right) {
                head->right = node;
            } else {
                bstInsert(head->right, node);
            }
        } else {
            if (NULL == head->left) {
                head->left = node;
            } else {
                bstInsert(head->left, node);
            }
        }
    }
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *head = new TreeNode(preorder[0]);

        for (int i = 1; i < preorder.size(); ++i) {
            bstInsert(head, new TreeNode(preorder[i]));
        }

        return head;
    }
};
