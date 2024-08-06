class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n= nums.size();
        if(n  ==1)return nums[0];
       long long left =1;
       long long right =1;
       long long  ans=0;
        for(int i=0;i<n;i++)
        {
            left  = (left == 0 || left < INT_MIN) ? 1 : left;
            right = (right ==0 || right < INT_MIN) ? 1: right;

            left *= nums[i];
            right *= nums[ n-1-i];

            ans = max(ans, max(left, right)); 
        }

        return int(ans);

    }
};
