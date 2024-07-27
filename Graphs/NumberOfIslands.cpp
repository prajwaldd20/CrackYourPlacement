class Solution {
public:
    int n, m;
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if(i<0 || i>=n || j<0 || j>= m || grid[i][j] != '1')
        {
            return;
        }

        grid[i][j]= '$';

        dfs(grid, i-1, j); // prev row
        dfs(grid, i+1, j); // next row
        dfs(grid, i, j-1); // prev col
        dfs(grid, i, j+1); // next col

        
    }
    int numIslands(vector<vector<char>>& grid) {
         n= grid.size();
        m= grid[0].size();

        int count=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j] == '1')
                    {
                        count++;
                        dfs(grid, i, j);
                    }
                }
            }
            return count;
    }
};
