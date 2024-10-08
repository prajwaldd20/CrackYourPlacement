//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	    // Topological sort using Kahn's Algo
	    
	    vector<int> indegree(V);
	    
	    for(int i=0;i<V; i++)
	    {
	        for(auto j: adj[i])
	        {
	            indegree[j]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    for(int i=0;i<V; i++)
	    {
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    vector<int> ans;
	    while(!q.empty())
	    {
	        int front =q.front();
	        q.pop();
	        
	        ans.push_back(front);
	        for(auto  neigh : adj[front])
	        {
	            indegree[neigh]--;
	            if(indegree[neigh] == 0)
	             q.push(neigh);
	        }
	        
	    }
	    
	    return ans;
	    
	}
};


