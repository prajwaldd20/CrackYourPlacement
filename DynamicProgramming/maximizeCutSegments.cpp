
class Solution
{
    int solve( int n, int x, int y, int z, int sum , vector<int> &t)
    {
        if( sum == n) return 0;
        
        if( sum > n ) return INT_MIN;
        
        if (t[sum] != -1) return t[sum];
        
        
        
        int xSum =1 +  solve(n, x, y,z, sum + x, t);
        int ySum = 1 + solve(n, x, y,z, sum + y, t);
        int zSum = 1 + solve(n, x, y,z, sum + z, t);
        
        
        return t[sum] =  max ( xSum, max(ySum, zSum));
    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> t(n+1, -1);
        int ans = solve( n, x, y, z, 0, t );
        if(ans< 0 ) return 0;
        return ans;
    }
};
