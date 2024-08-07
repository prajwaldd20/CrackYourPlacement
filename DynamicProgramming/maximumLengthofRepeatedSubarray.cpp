class Solution {
    
    int solve(vector<int>& a, vector<int>& b, int n, int m,
     vector<vector<int>> &t
     )
    {
       int maxi = 0;

       for(int i=0;i<=n;i++)
       {
        for(int j=0;j<=m;j++)
        {
            if( i == 0 || j==0)
            {
                t[i][j] = 0;
            }
            else
            {
                if(a[i-1] == b[j-1])
                {
                    t[i][j] =1 + t[i-1][j-1];
                }
                else
                {
                    t[i][j] = 0;
                }
            }

            maxi =max(maxi,t[i][j]);
        }
       }

       return maxi;
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m = nums2.size();
        // memset(t, -1,sizeof(t));;
        vector<vector<int>> t(n+1, vector<int>(m+1,0));
        return solve(nums1, nums2, n,m,t);

    }
};
