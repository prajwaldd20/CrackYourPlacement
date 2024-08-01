class Solution {
public:

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int count = 0;
        int n =matrix.size();
        int m =matrix[0].size();
        int ans=0;
       for(int i=0;i<n;i++)
       {
        for(int j= 0;j<m;j++)
        {
            if(count < k)
            pq.push(matrix[i][j]);
            
            
            count++;
            if(count > k)
            {
               if(matrix[i][j] < pq.top())
               {
                pq.pop();
                pq.push(matrix[i][j]);
               }
            }
        }
       }

       return pq.top();
    }
};
