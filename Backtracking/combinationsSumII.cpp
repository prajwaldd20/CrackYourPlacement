class Solution {
    void solve(vector<int> &candidates, int index ,int target, vector<int> &curr, 
     vector<vector<int>> &ans
    )
    {
        if(target < 0) return;
        if( target == 0 )
        {
            ans.push_back(curr);
            return;
        }


        for(int i=index; i< candidates.size();i++)
        {
            if( i> index && candidates[i] == candidates[i-1])
            continue;

            curr.push_back(candidates[i]);
            solve(candidates,i+1, target - candidates[i], curr, ans);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());

        solve(candidates,0, target, curr, ans);
        return ans;
    }
};
