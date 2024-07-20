class Solution {
public:
    int search(vector<int>& nums, int target) {
    int ans=-1;
    int n=nums.size();
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid= low+ (high - low)/2;
        if(nums[mid]== target)
        {
            return mid;
        }
        else if(nums[mid] >= nums[low])
        {
            // left part is sorted
            // Check whether element
            if( target <= nums[mid] && target>= nums[low])
            {
                high = mid-1;
            }
            else
            {
                low =mid+1;
            }
        }
        else
        {
            // right part sorted
            //check for element
            if( target>= nums[mid] && target<= nums[high])
            {
                low = mid+1;
            } 
            else{
                high = mid-1;
            }
        }
    }

    return ans;
    }
};
