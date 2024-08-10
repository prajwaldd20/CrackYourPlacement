class Solution {
   
    int t[20];

    int solve(int n)
    {
        if( n==0 || n== 1) return 1;
        if(t[n] != -1) return t[n];

      int ans= 0;

        for(int i=1;i<=n;i++)
        {
            ans += (solve(i-1) * solve(n-i));
        }

        return t[n] = ans;
    }
public:
    int numTrees(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};
