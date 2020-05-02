/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
    void serialize(TreeNode *node, string &s)
    {
        if (!s.empty()) {
            s += ",";
        }

        if (NULL == node) {
            s += "null";
        } else {
            s += to_string(node->val);
            serialize(node->right, s);
            serialize(node->left, s);
        }
    }
    vector<string> string_tokenizer(string &s)
    {
        vector <string> tokens;
        stringstream ss(s);
        string token;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        return tokens;
    }
    TreeNode *deserialize(vector<string> &tokens, int &index)
    {
        if (tokens[index] == "null") {
            return NULL;
        } else {
            TreeNode *node = new TreeNode(stoi(tokens[index]));
            ++index;
            node->right = deserialize(tokens, index);
            ++index;
            node->left = deserialize(tokens, index);
            return node;
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s;
        serialize(root, s);
        //cout << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<string> tokens = string_tokenizer(data);
        int index = 0;
        return deserialize(tokens, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));