class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n =nums.size();
        int mid = n/2;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++)
        {
            ans += abs(nums[mid] - nums[i]);
        }

        return ans;
    }
};
