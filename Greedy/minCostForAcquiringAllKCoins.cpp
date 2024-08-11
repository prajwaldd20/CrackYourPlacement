//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>coins, int amount)
	{
	    // Code here
	     int n= coins.size();

        // create a dp matrix

        vector<vector<int>> t(n+1, vector<int>(amount+1));

        // initialize first row with infinity
        
        for(int j=0; j<=amount;j++)
        {
            t[0][j] = INT_MAX-1;
        }

        // initialize first col (except first cell) to 0
        for(int i=1;i<= n;i++)
        {
            t[i][0] = 0;
        }

        // initialize second row 

        int firstElement = coins[0];
        for(int j=1;j<=amount;j++)
        {
            if ( j %  firstElement  == 0 ) // divides the coin value
            {
                t[1][j] = j / firstElement;
            }
            else
            {
                t[1][j] = INT_MAX-1;
            }
        }



        // run two for loops

        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if( coins[i-1] <= j )
                {
                    t[i][j] = min( 1 + t[i][j-coins[i-1]] , t[i-1][j]);
                }
                else
                {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return t[n][amount] != INT_MAX-1 ? t[n][amount] : -1;
	}
};

