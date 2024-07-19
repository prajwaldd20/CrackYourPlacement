
class Solution {
    
    bool  bfsCycle( unordered_map<int, bool> &vs, int src,vector<int> adj[] )
    {
        
       unordered_map<int, int> parent;
       parent[src] = -1;
       
    
       queue<int> q;
       q.push(src);
         vs[src] = true;
       
       
       while(!q.empty())
       {
           int front = q.front();
           q.pop();
          vs[front] = true;
           for(auto j:adj[front])
           {
               if(vs[j] == true && parent[front] != j)
               {
                   return true;
               }
               else if(!vs[j])
               {
                    q.push(j);
                    vs[j] = true;
                    parent[j] = front;
               }
               
               
           }
           
         
       }
        
          return false;
    }
    
    
    
    bool dfsCycle(int node, int parent,  unordered_map<int, bool> &vs,vector<int> adj[])
    {
        
        vs[node] = true;
        
        for(auto i: adj[node])
        {
            if(!vs[i])
            {
                bool temp = dfsCycle(i,node, vs, adj);
                if(temp == true)
                return true;
                
            }
            else if(i != parent)
            {
                return true;
            }
        }
        
        return false;
        
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        unordered_map<int, bool> vs(V);
        

      // for components aka disconnected graph
       for(int i=0;i<V; i++)
        {
            if(!vs[i])
               {
                   bool ans = dfsCycle(i,-1, vs, adj);
                   if(ans == true)
                    return true;
               }
    
        }
        
        return false;
        
    }
};

