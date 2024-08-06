class Solution {
    int solve( int index, int prevIndex, vector<int> &arr, int n , vector<vector<int>> &t)
    {
        // base condition
        if(index == n) return 0;
         if(t[index][prevIndex+1] != -1) return t[index][prevIndex+1];
        // do not take element
        int len = solve(index+1, prevIndex, arr, n, t); 

       
        if(prevIndex == -1 || arr[index] > arr[prevIndex])
        {
            // if element is taken
            // increase len by 1 
            // set prevIndex to curr index
            len =  max(len , 1 + solve(index+1, index, arr, n, t)); 
        }

        return  t[index][prevIndex+1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        
       

        int n= nums.size();
        // since prevIndex can be -1
        // so store prevIndex+1
         vector<vector<int>> t(n, vector<int>(n+1, -1));
        return solve(0, -1, nums, n, t);


    }
};
