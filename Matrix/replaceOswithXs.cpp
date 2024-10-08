class Solution{
    private:
    
         
         
         
         void dfs(int row, int col,  vector<vector<bool>> &vis,
         vector<vector<char>>& mat
         )
         {
             vis[row][col] = true;
             int delrow[4] = {-1,0,1,0};
             int delcol[4] = {0, -1, 0, 1};
             int n=mat.size() , m=mat[0].size();
             // traverse top, bottom , left and right
             for(int i=0;i<4;i++)
             {
                 
                 int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                && vis[nrow][ncol]== false && mat[nrow][ncol] == 'O'
                )
                {
                    dfs(nrow, ncol, vis, mat);
                }
             }
         }
public:
       
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        
        
         
         vector<vector<bool>> vis(n, vector<bool>(m, false));
         
         // traverse first and last row
         
         for(int j =0;j<m;j++)
         {
             
             // first row
             
             if(!vis[0][j] && mat[0][j] == 'O')
             {
                 dfs(0, j, vis, mat);
             }
             
             
             // last row
             
             if(!vis[n-1][j] && mat[n-1][j] == 'O')
             {
                 dfs(n-1, j, vis, mat);
             }
         }
         
         
         // traverse first and last col
         
         for(int i= 0;i<n;i++)
         {
             //first col
             if(!vis[i][0] && mat[i][0] == 'O')
             {
                 dfs(i, 0, vis, mat);
             }
             
             //last col
             if(!vis[i][m-1] && mat[i][m-1] == 'O')
             {
                 dfs(i, m-1, vis, mat);
             }
         }
         
         // if mat[i][j] not visited and it is 'O' 
         // then, convert O to X
         
         for(int i = 0;i<n;i++)
         {
             for(int j= 0;j<m;j++)
             {
                 if(!vis[i][j] && mat[i][j] == 'O')
                 {
                     mat[i][j] = 'X';
                 }
             }
         }
         
         return mat;
    }
};
