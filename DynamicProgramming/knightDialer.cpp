class Solution {
    int M = 1e9 +7 ;
    // adj list for possible jumps 
    vector<vector<int>> adj{
        {4, 6},
        {6, 8},
        {7, 9},
        {4,8},
        {0, 3, 9},
        {},
        {1,7,0},
        {2,6},
        {1,3},
        {2,4}
    };

    int t[5001][10];
    int solve(int n, int cell)
    {
        if( n==0 ) return 1;

        int ans=0;
        for(int &nextCell:adj[cell])
        {
            ans = (ans + solve(n-1, nextCell)) % M;
        }
        return ans;
    }

public:
    int knightDialer(int n) {
        
        int result =0;
        memset(t, -1,sizeof(t));

        // base condition

        for(int cell =0 ;cell<=9;cell++)
        {
            t[0][cell] = 1;
        }

        for(int i=1;i<= n-1 ;i++)
        {
            for(int j=0;j<=9;j++)
            {
                int ans =0;
                for( auto & nextCell: adj[j])
                {
                    ans = (ans + t[i-1][nextCell] ) % M;
                }

                t[i][j] = ans;
            }

        }

        for(int cell =0; cell<=9;cell++)
        {
            result  = (result + t[n-1][cell] ) % M;
        }
        return result;
    }
};
