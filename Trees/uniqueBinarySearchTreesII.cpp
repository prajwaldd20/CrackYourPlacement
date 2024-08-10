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

  


    vector<TreeNode*> solve(int start, int end)
    {
        if( start > end  ) return  {NULL};
   

        if(start == end) 
        {
            TreeNode* newNode = new TreeNode(start);
            return {newNode};
        }
      vector<TreeNode*> ans;

        for(int i=start;i<= end;i++)
        {
            vector<TreeNode*> leftBSTs = solve(start, i-1);
            vector<TreeNode*> rightBSTs =solve(i+1, end);

            for(TreeNode* leftRoot: leftBSTs)
            {
                for(TreeNode* rightRoot: rightBSTs)
                {
                    TreeNode* root =new TreeNode(i);

                    root->left = leftRoot;
                    root->right =rightRoot;

                    ans.push_back(root);
                    
                }
            }
        

        }


    return ans;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        
        if( n==0) return {};

        return solve(1, n);
    }
};
