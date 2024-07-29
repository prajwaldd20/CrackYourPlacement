	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	      vector<int> dist(n, 1e8); //  since given in the question
        dist[0] = 0;
        // N-1 iterations
        for(int i=0;i<n-1;i++)
        {
            for(auto it: edges)
            {
               int  u =it[0];
               int v = it[1];
               int weight = it[2];
               
               // relaxation condition
               if( dist[u] + weight < dist[v])
               {
                   dist[v] = dist[u] + weight;
               }
            }
        }
        
        // Nth iteration for checking negative cycle 
        for(auto it: edges)
        {
               int  u =it[0];
               int v = it[1];
               int weight = it[2];
               
               // relaxation condition
               if(dist[u] != 1e8 && dist[u] + weight < dist[v])
               {
                   return 1;
               }
        }
        
        return 0;
	}
