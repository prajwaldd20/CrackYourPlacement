/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getPaths(TreeNode* node, vector<string> &ans, string path)
    {
        if(node == NULL ) return;

        if(!path.empty()) {
            path += "->";
        }
        path += to_string(node->val);
        if(node->left == NULL && node->right == NULL)
        {
            ans.push_back(path);
        }

        else
        {
            getPaths(node->left, ans, path);
            getPaths(node->right, ans, path);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL ) return {};

        vector<string> ans;

        getPaths(root, ans,"" );


        return ans;

        
    }
};
