// Sort array of 0s, 1s, 2s

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // count 0s, 1s, 2s and modify the array according to count
       /* int c0 =0, c1 =0, c2 =0;
        for(int i=0;i<nums.size(); i++)
        {
            if(nums[i] == 0)
            c0++;
            else if(nums[i]==1)
            c1++;
            else
            c2++;
        }
        for(int i=0;i<nums.size(); )
        {
            if( c0!=0)
            {
                while(c0--)
                {
                    nums[i] =0;
                    i++;
                }
               
            }
            if( c1!=0)
            {
                while(c1--)
                {
                    nums[i] =1;
                    i++;
                }
                
            }
            if( c2!=0)
            {
                while(c2--)
                {
                    nums[i] =2;
                    i++;
                }
            }
        }
        */

        // Dutch Nahtional Flag Algorithm
        // Basically, 3 conditions are there:
        /*
       0 to low-1 => 0
       low to mid-1 => 1
       mid to high => unsorted
       high+1 to n-1 => 2
        */

        int n= nums.size();
        int low = 0, mid=0, high=n-1;

        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                low++, mid++;
            }
           else  if(nums[mid] == 1)
            {
                mid++;
            }
          else if(nums[mid] == 2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
