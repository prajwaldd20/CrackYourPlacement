//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
    
    char keypad[4][3] = {
         {'1','2' ,'3' },
         { '4','5','6'},
         {'7','8','9'},
         {'*','0','#'}
         
    };
    
    long long  t[4][3][26];
    
    long long  solve(int i, int j, int n  )
    {
        if ( i<0 || i>=4 || j<0 || j>=3 || keypad[i][j] == '*' || keypad[i][j] =='#')
        return 0;
        
        if( n== 1) return 1;
        
        if(t[i][j][n] != -1) return t[i][j][n];
        
        long long ans =solve(i,j, n-1) + 
                        solve(i-1, j, n-1)+
                        solve(i+1, j, n-1)+
                        solve(i, j+1, n-1)+
                        solve(i, j-1, n-1);
                        
        return t[i][j][n] = ans;
         
        
    }
    
    
    
  public:
    long long getCount(int n) {
        // Your code goes here
        long long count =0;
        
        memset(t, -1, sizeof(t));
        
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(keypad[i][j] != '#' && keypad[i][j] !='*')
                 count += solve(i, j, n);
            }
        }
        
        return count;
    }
};

