 int findDuplicate(vector<int>& nums) {
        // Approached using map
        // But, it will take extra space

        // Tortoise hare method

        int slow=nums[0],fast=nums[0];
       do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while( slow != fast);

        fast = nums[0];

        while(slow != fast)
        {
            slow =nums[slow];
            fast =nums[fast];
        }

        return fast;

    }
