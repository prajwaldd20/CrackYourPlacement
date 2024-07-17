class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
        set<int> mp;
        int n=nums.size();
        for( int i=0;i<n; i++)
        {
            mp.insert(nums[i]);
        }
        int i=0, ans=0;
       while(!mp.empty())
        {
            nums[i++] = *mp.begin();
             mp.erase(mp.begin());
           
            ans++;
        }
        return ans;
        */

        // Using Two pointer


        int n= nums.size();
        int i=0;
        for(int j=1;j<n;j++)
        {
            if(nums[i] != nums[j])
            {
                i++;
                nums[i] =nums[j];
            }
        }
        return i+1;
    }
};
