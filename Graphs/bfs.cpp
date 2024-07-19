
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        unordered_map<int, bool> vis(V);
        vector<int>  ans;
        queue<int> q;
        
        q.push(0);
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            if(vis[front] == false)
                ans.push_back(front);
            vis[front] = true;
            for(auto j : adj[front])
            {
                if(!vis[j])
                {
                    q.push(j);
                }
            }
        }
        
        return ans;
        
        
    }
};

