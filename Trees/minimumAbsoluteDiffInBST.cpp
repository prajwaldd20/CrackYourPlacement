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
    void inorder(TreeNode* root, vector<int> &in)
    {
        if(root==  NULL)
        return;

        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int ans =INT_MAX;
        vector<int> in;
        inorder(root, in);
        for(int i=0;i<in.size()-1; i++)
        {
            ans = min( abs( in[i] - in[i+1]), ans  );
        }
        if(ans !=INT_MAX)
        return ans;
        else
        return 0;
    }
};
