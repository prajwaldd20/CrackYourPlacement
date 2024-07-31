int n, m;
    
    void dfsSolve( vector<vector<char>>& grid, int i, int j , 
     vector<vector<bool>> &visited
    )
    {
        if( i<0 || i>=n || j<0 || j>=m || grid[i][j] =='0' || visited[i][j] ==true)
        {
            return;
        }
        
        visited[i][j] =true;
        
        
       
              dfsSolve(grid, i+1, j, visited); // next row
              dfsSolve(grid, i-1, j, visited); // prev row
              dfsSolve(grid, i-1, j-1, visited); //diagonally prev
              dfsSolve(grid, i, j+1, visited); // next col
              dfsSolve(grid, i, j-1, visited); // prev col 
              dfsSolve(grid, i+1, j+1, visited); // diagonally next
              dfsSolve(grid, i+1, j-1, visited);
              dfsSolve(grid, i-1, j+1, visited);
       
        
        return;
      
    }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        // dfs
         n = grid.size();
         m =grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] =='1' && !visited[i][j])
                {
                    ans++;
                dfsSolve(grid,i, j, visited);
               
                }
            }
        }
        
        return ans;
    }
