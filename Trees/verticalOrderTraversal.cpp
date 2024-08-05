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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL ) return {};
        map<int , map<int, vector<int> > > mp; // col , level and its nodes
  
        queue< pair<TreeNode*, pair<int, int> >> q; // Node and level & col 

        int level = 0;
        q.push({root, {0, level}});

        while(!q.empty())
        {
            int s = q.size();
            for(int i=0;i<s;i++)
            {
            auto front = q.front();
            q.pop();
            TreeNode* node= front.first;
            int col = front.second.first;

            mp[col][level].push_back(node->val);

            if(node->left)
            {
                q.push({node->left, { col-1, level}});
            }

            if(node->right)
            {
                q.push({node->right,{col+1, level}});
            }
            }
            level++;
        }


        for(auto it:mp) // first map
        {
            vector<int> temp;

            for(auto x:it.second) // this is also a map -> second map
            {
                 sort(x.second.begin(), x.second.end());
                 for(int i: x.second)
                 {
                    temp.push_back(i);
                 }

            }
           

            ans.push_back(temp);
        }

        return ans;

    }
};
