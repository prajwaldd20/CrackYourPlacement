class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        map<int, int> mp;
        mp[0] = 1;
        int rem, sum = 0;
        // Using prefix sum
        for(int i =0 ;i<nums.size(); i++)
        {
            sum += nums[i];
            rem = sum%k;
            if(rem <0) rem = rem +k;
            if(mp[rem]!=0)
            {
                ans += mp[rem];
                mp[rem]++;
            }
            else
            {
                mp[rem]++;
            }
        }
        return ans;
    }
};
