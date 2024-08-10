class Solution {

void solve(int index, vector<int> &temp, int n, int k, vector<vector<int>> &ans, int val)
{
    if(index > k)
    {
        ans.push_back(temp);
        return;
    }

    for(int i = val; i<= n;i++)
    {
        temp.push_back(i);
        solve(index+1,temp, n,k,ans,i+1 );
        temp.pop_back();
    }
}

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;

        vector<int> temp;

        solve(1, temp, n,k,ans,1);
        return ans;
    }
};
