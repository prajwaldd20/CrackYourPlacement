class Solution {

    int N;
    vector<int> count;
    long root_sum;


    int dfsFirst(unordered_map<int, vector<int>> &adj, 
    int currNode, int prevNode, int currDepth
    )
    {
        int totalCount = 1;

        root_sum+= currDepth;

        for(auto &child: adj[currNode])
        {
            if(child == prevNode)
            {
                    continue;
            }

            totalCount += dfsFirst(adj, child ,currNode, currDepth+1);
        }

        count[currNode] = totalCount;
        return totalCount;
    }


    void dfsSecond(unordered_map<int, vector<int>> &adj,
    int parent, int prev, vector<int> &res
    )
    {
        for(auto &child: adj[parent])
        {
            if(child == prev) continue;

            res[child] = res[parent] - count[child] + N - count[child];

            dfsSecond(adj,child, parent, res);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        N = n;
        
        count.resize(n,0);
        // create adj list

        unordered_map<int, vector<int>> adj;

        for(auto &it: edges)
        {
            int u = it[0];
            int v =it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }


        root_sum = 0;

        // first dfs call to populate count vector 
        // and find result for root
        dfsFirst(adj, 0, -1, 0);

        vector<int> res(n, 0);
        res[0] = root_sum;

        // second dfs call to fill res vector 
        
        dfsSecond(adj, 0, -1,res);

        return res;

    }
};
