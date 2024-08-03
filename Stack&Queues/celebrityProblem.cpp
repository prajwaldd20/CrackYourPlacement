//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        
        int n= mat.size();
        
        int top= 0 , down = n-1;
        
        while(top < down)
        {
            if(mat[top][down] == 1 ) // top knows down
            {
                top++;
            }
            else if( mat[down][top] == 1)
            {
                down--;
            }
            else
            {
                top++;down--;
            }
        }
        
        
        if(down > top) return -1;
        
        for(int i=0;i<n;i++)
        {
            if(i == top) continue;
            if(mat[i][top] == 1 && mat[top][i] == 0)
            {
              ;   
            }
            else
            {
                return -1;
            }
        }
        
        return top;
    }
};

