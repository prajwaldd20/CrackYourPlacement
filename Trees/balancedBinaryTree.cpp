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
     private:
    int getHeight(TreeNode* root)
    {
        if(root== NULL)
        return 0;
        
        int l = getHeight(root->left);
        int r= getHeight(root->right);
        int ans= max(l,r);
        return (ans+1);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
        return true;
        
        
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if(abs(left-right)>1)
        {
            return false;
        }
        // else
        // return true;
        bool lh= isBalanced(root->left);
        bool rh= isBalanced(root->right);
        if( lh && rh )
        return true;
        else
        return false;
    }
};
