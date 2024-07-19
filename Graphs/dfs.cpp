
class Solution {
    
   void solveDFS( unordered_map<int, bool> &vis,vector<int> &ans, vector<int> adj[], int i )
   {
       
       if(vis[i] == true)
       return;
       
       ans.push_back(i);
       vis[i] = true;
       for(auto j: adj[i])
       {
           if(!vis[j])
           {
               solveDFS(vis, ans, adj, j);
           }
       }
       
       
   }
    
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int, bool> vis(V);
        vector<int> ans;
        
        int i= 0;
        solveDFS(vis, ans, adj, i);
        
        return ans;
        
    }
};

