class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n= nums.size() ;
        int dest = n-1;

        for(int i= n-1;i >= 0; i--)
        {
            if(nums[i] + i >= dest)
            {
                dest = i;
            }

        }

        return dest == 0;


    }
};
