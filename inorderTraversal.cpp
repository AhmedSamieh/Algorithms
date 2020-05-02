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
    void inorderTraversalHelper(TreeNode* root, vector<int>& v) {
        if (NULL != root)
        {
            inorderTraversalHelper(root->left, v);
            v.push_back(root->val);
            inorderTraversalHelper(root->right, v);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inorderTraversalHelper(root, v);
        return v;
    }
};*/
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;
        unordered_set<TreeNode *> visited;
        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();

            if (NULL != node) {
                if (visited.find(node) == visited.end()) {
                    st.push(node->right);
                    st.push(node);
                    st.push(node->left);
                    visited.insert(node);
                } else {
                    v.push_back(node->val);
                }
            }
        }

        return v;
    }
};
