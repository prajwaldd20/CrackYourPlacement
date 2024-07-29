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
    void solve(TreeNode* root, vector<vector<int>> &ans)
    {
        if(root == NULL )
        return ;
        queue<TreeNode*> q;
        q.push(root);
        bool flag= true; // if true ->  L -> R
                        // if false -> R -> L
        
        while(!q.empty())
        {
            int s = q.size();
            vector<int> ar(s);
            for(int i=0;i<s; i++)
            {
                TreeNode* n = q.front();
                q.pop();

                int index= (flag ? i : s - i - 1);
                ar[index] = n->val;
                if(n->left)
                q.push(n->left);

                if(n->right)
                q.push(n->right);

             
            }
           flag = !flag;
                ans.push_back(ar);
        }
        


    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root, ans);
        return ans;

    }
};
