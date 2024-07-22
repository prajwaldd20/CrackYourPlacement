class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        vector<int> prefSum(n,0);
        prefSum[0] = nums[0];
        unordered_map<int, int> mp;
        //calc prefix sum
        for(int i=1;i<n;i++)
        {
            prefSum[i] = prefSum[i-1]+nums[i];
          
        }
        for(int i=0;i<n;i++)
        {
            if(prefSum[i] == k)
            ans++;

            if(mp.find(prefSum[i] - k) != mp.end())
            {
                ans+= mp[prefSum[i]-k];
            }
            mp[prefSum[i]]++;
        }
        return ans;
    }
};
