/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*class Solution {
    vector<int> v;
    int index;
    void getVector(TreeNode* node)
    {
        if (NULL == node) return;
        getVector(node->right);
        v.push_back(node->val);
        getVector(node->left);
    }
    void updateBST(TreeNode* node)
    {
        if (NULL == node) return;
        updateBST(node->right);
        node->val = v[index++];
        updateBST(node->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        index = 0;
        getVector(root);
        for (int i = 1; i < v.size(); ++i)
        {
            v[i] += v[i - 1];
        }
        updateBST(root);
        return root;
    }
};*/
class Solution {
    int sum;
    void updateBST(TreeNode* node)
    {
        if (NULL != node->right)
        {
            updateBST(node->right);
        }
        sum = (node->val += sum);
        if (NULL != node->left)
        {
            updateBST(node->left);
        }
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        if (NULL != root)
        {
            sum = 0;
            updateBST(root);
        }
        return root;
    }
};
