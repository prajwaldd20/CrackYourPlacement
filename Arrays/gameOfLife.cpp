class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n= board.size();
        int m= board[0].size();

        int delrow[]= {-1,-1,-1,0,0,1,1,1};
        int delcol[] ={1,0,-1,-1,1,-1,0,1}; 

        vector<vector<int> >mat(n, vector<int>(m, 0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int count =0 ; // count of live cells
                //traverse 8 direction
                for(int k=0;k<8;k++)
                {
                    int p = i + delrow[k];
                    int q = j + delcol[k];

                    if( p>=0 && p< n && q>=0 && q<m && board[p][q] == 1 )
                    {
                        count++;
                    }
                    
                }

                if(board[i][j] == 1) // cell is live
                {
                    if(count == 2 || count == 3)
                    {
                        mat[i][j] = 1;
                    }
                }
                else // cell is dead
                {
                    if(count == 3)
                    {
                        mat[i][j] = 1;
                    }
                }

            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                board[i][j] = mat[i][j];
            }
        }
    }
};
