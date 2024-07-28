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
    bool isIdentical(TreeNode* node1, TreeNode* node2) {
        if (node1 == NULL && node2 == NULL)
            return true;

        // since, one is null and other is not , so, they are not same
        if (node1 == NULL || node2 == NULL)
            return false;

        if (node1->val != node2->val)
            return false;

        return isIdentical(node1->left, node2->left) &&
               isIdentical(node1->right, node2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == NULL)
            return true;

        if (root == NULL)
            return false;

        if (isIdentical(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
