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
void bfs(TreeNode* root, map<TreeNode*, bool> &vis)
{
    if(root == NULL)
    return;

    if(vis[root] == true)
    return;

    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* front = q.front();
        q.pop();

        if(vis[front] == true)
        {
            continue;
        }

        vis[front] = true;

        TreeNode* temp = front->left;
        front->left =front->right;
        front->right = temp;

        if(front->left)
        q.push(front->left);

        if(front->right)
        q.push(front->right);


    }

    return;
}
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
        return root;

    /*
        //Approach using recursion
        // Using Post Order Traversal

        invertTree(root->left);
        invertTree(root->right);

        TreeNode* temp = root->left;

        root->left = root->right;

        root->right =temp;


        return root;

*/ 

        // Approach 2 using BFS

        // visited map
        map<TreeNode*, bool> vis;
        bfs(root, vis);
        return root; 

    }
};
