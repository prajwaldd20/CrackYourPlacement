class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int s= i+1, e=n-1;
            while(s<e)
            {
                int sum = nums[i]+nums[s]+nums[e];
                if(sum == 0)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[s]);
                    temp.push_back(nums[e]);
                    ans.push_back(temp);
                    s++;
                    while(nums[s]==nums[s-1] && s<e)
                    {
                        s++;
                    }
              
                }
                else if(sum < 0 )
                {
                    s++;
                }
                else
                {
                    e--;
                }
            }
        }
        return ans;
    }
};
