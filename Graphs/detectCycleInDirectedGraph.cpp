
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        
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
	    int cnt =0;
	    while(!q.empty())
	    {
	        int front =q.front();
	        q.pop();
	        
	       cnt++;
	        for(auto  neigh : adj[front])
	        {
	            indegree[neigh]--;
	            if(indegree[neigh] == 0)
	             q.push(neigh);
	        }
	        
	    }
	    
	    return !(cnt == V);
    }
};

