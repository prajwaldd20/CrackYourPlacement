class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        if(n ==0 ) return {0};
            ans[0] = 0;
        for(int i=0;i<=n;i++)
        {
            if( i %2 == 0) // even
            {
                ans[i] = ans[i/2];
            }
            else
            {
                ans[i] = ans[i/2] + 1 ;
            }
        }

        return ans;

    }
};
