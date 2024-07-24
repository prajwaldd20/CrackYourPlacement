class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n =matrix.size();
    
        if(n== 1 )
        return;
       int i=0;
      // transpose and reverse each row
       while(i<n-1)
       {
        int j=i+1;
        while(j<n)
        {
            swap(matrix[i][j], matrix[j][i]);
            j++;
        }
        i++;
       }

       for(int i=0;i<n;i++)
       {
        reverse(matrix[i].begin(), matrix[i].end());
       }

return;

    }
};
