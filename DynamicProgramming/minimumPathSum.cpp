class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();

        vector<vector<int>> t(n,vector<int> (m,0));

        // first row -> same value
        t[0][0] = grid[0][0];
        for(int j=1;j<m;j++)
        {
            t[0][j] =grid[0][j] +t[0][j-1];
        }

        // first col -> same value

        for(int i=1;i<n;i++)
        {
            t[i][0]  = grid[i][0] + t[i-1][0] ;
        }


        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                t[i][j] = min(  grid[i][j] + t[i-1][j] , grid[i][j] + t[i][j-1]  );
            }
        }

        return t[n-1][m-1];
    }
};
