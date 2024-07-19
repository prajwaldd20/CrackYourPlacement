class Solution {
    int solve(TreeNode* root, int &maxi)
    {
        if(root == NULL)
        return 0;

        int lh = solve(root->left, maxi);
        int rh =solve(root->right, maxi);
        maxi = max((lh+rh), maxi);
        return max(lh, rh)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
            int maxi = 0;
            solve(root, maxi);
            return maxi;
    }
};
