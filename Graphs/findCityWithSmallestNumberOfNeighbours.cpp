class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dist[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if( i == j)
                {
                    dist[i][j] = 0;
                }
                else
                {
                    dist[i][j] = 1e9;
                }
            }
        }

         for(auto it:edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        int ans;
        int mini=INT_MAX;
        vector<int>reachble(n);
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=distanceThreshold){
                    count++;
                }
            }
            reachble[i]=count;
            if(count <= mini){
                mini=count;
                ans=i;
            }
        }

        



        return ans;

    }
};
