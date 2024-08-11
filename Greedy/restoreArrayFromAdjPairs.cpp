class Solution {

    void dfs(unordered_map<int, vector<int>> &adj, int i, unordered_set<int> &st, 
    vector<int> &ans
    )
    {
        // if element already present return
        if( st.find(i) != st.end() ) return;
        ans.push_back(i);
        st.insert(i);
        for(auto it: adj[i] )
        {
            dfs(adj, it,st, ans);
        }
    }
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;

        for(auto it: adjacentPairs)
        {
            int u= it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int start;
        for(auto k:adj)
        {
            if(k.second.size() == 1) 
            {
                start = k.first;
            }
        }


        vector<int> ans;
        unordered_set<int> st;

        dfs(adj, start,  st, ans);

        return ans;
    }
};
