class Solution {
        void solve( vector<int> nums ,vector <vector<int> > &ans, int pos )
    {
        if (pos >= nums.size())
        {
            ans.push_back(nums);
            return ;
        }
            
            unordered_set<int> st;
            
            
        for(int i=pos;i<nums.size(); i++)
        {
            if(st.find(nums[i]) != st.end() ) continue; 
           
            st.insert(nums[i]);
           swap(nums[pos], nums[i]);
           solve (nums, ans, pos+1 );
           swap(nums[pos], nums[i]); // backtracking
        }
    }  
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<vector<int>> ans;
         if(n == 0)
         return ans ;
         int pos = 0;
         solve(arr, ans,pos );
         sort(ans.begin(),ans.end());
         return ans;
    }
};
