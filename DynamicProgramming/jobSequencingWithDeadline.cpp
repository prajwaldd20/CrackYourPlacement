//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    bool static cmp ( Job a, Job b)
    {
        return a.profit > b.profit;
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        sort(arr, arr+n, cmp);
        
        int maxi = arr[0].dead;
        
        for(int i=0;i<n;i++)
        {
            maxi = max( maxi, arr[i].dead );
        }
        
        vector<int> vec(maxi+1, -1);
        
        int count=0, maxProfit = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j = arr[i].dead ; j> 0; j--)
            {
                if(vec[j] == -1)
                {
                    vec[j] = i;
                    count++;
                    maxProfit += arr[i].profit;
                    break;
                    
                }
            }
        }
        
        return {count, maxProfit};
        
    } 
};

