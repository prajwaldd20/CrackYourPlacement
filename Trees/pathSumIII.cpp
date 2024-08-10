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
    int count=0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        

        if(root == NULL ) return 0;

        unordered_map<long long, int> mp;
        // mp[0] = 1;

        solve(root, 0,targetSum, mp);

        return count;


    }

    void solve(TreeNode* curr, long long sum , int target, unordered_map<long long, int> &mp)
    {
        if (curr == NULL) return;

        // add val to sum
        sum += curr->val;
        
        if(sum == target) count++;

        if( mp.find(sum - target) != mp.end() ) // sum exists
        {
            count += mp[sum- target];
        }

        mp[sum]++;

        solve(curr->left, sum, target, mp);
        solve(curr->right, sum, target, mp);

        mp[sum]--;

        return ;



    }
};
