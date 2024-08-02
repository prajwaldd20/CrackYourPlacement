//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
   
    bool subsetSum(int arr[], int n, int sum)
    {
        bool dp[n+1][sum+1];
        
        // init dp array
        
        for(int i=0;i<n+1;i++)
        {
            for(int  j=0;j< sum+1 ;j++)
            {
            if( i==0)
            dp[i][j] = false;
            
             if(j == 0)
            dp[i][j] = true;
            }
        }
        
        
        for(int  i = 1;i<n+1;i++)
        {
            for(int  j=1;j<sum+1;j++)
            {
                if( arr[i-1] <= j )
                {
                    dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        
        return dp[n][sum];
        
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
       int  sum = 0;
        
        for(int i=0;i<N;i++)
        {
            sum += arr[i];
        }
        
        // sum is odd
        if(sum %2 != 0 )
        {
            return 0;
        }
        
        
        return subsetSum(arr, N, sum/2)== true ? 1: 0;
    }
};

