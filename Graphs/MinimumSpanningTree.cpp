	pair<int, int>  getMin(vector<int> key, vector<bool> mst)
	{
	    
	    // Function to get minimum from key array
	    int mini = INT_MAX, minIndex = -1;
	    
	    for(int i=0;i<key.size();i++)
	    {
	        if(mst[i] == false && key[i] < mini)
	        {
	            mini = key[i];
	            minIndex = i;
	        }
	    }
	    
	    return {mini, minIndex};
	    
	    
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
       
         
         
         // Code using Prim's Algorithm
         
         
         
         
         
         // 3 arrays 
   
            vector<int> parent(V, -1);
            vector<int> key(V, INT_MAX);
            vector<bool> mst(V, false); // to keep track of nodes included in MST
            
            key[0] = 0; // initialized with 0
            parent[0] = -1;
            
            
            for(int i=0;i<V;i++)
            {
                // get minimum value from key 
                pair<int, int> p  = getMin(key, mst);    
                int minIndex = p.second;
                int minNode= p.first;
                // include that index in mst
                mst[minIndex] = true;
                
                // check for its adjacent nodes
                for(auto it: adj[minIndex])
                {
                    int  node = it[0];
                    int wt = it[1];
                    
                    // if current weight is less than the previous weight
                    // then, update the weight in  key array
                    if( mst[node] == false &&  wt < key[node] )
                    {
                        parent[node] = minNode;
                        key[node] = wt;
                    }
                }
                
                
            }
            
            int ans = 0;
            for(int i=1;i<key.size();i++)
            {
                if(key[i] != INT_MAX) 
                ans+= key[i];
            }
            
            return ans;
            
          
            
            
             
            
    }
