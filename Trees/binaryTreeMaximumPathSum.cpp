/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, int &sum) {
        if (root == NULL)
            return 0;
        
        int l_sum = max(0,solve(root->left, sum));
        int r_sum = max(0,solve(root->right, sum));
        sum = max(sum, (l_sum + r_sum+ root->val));
        return max(l_sum ,r_sum) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        
        // if(root == NULL)
        // return 0;
        // if(root->left == NULL && root->right == NULL)
        // return root->val;
        int sum = INT_MIN;
        solve(root, sum);
        return sum;
    }
};
