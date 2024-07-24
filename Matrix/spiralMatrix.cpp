class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n= matrix.size();
        int m=matrix[0].size();

        int top = 0, bottom = n-1;
        int left = 0, right=m-1;


        while(top<= bottom && left<=right )
        {
            // from left to right
            for(int i = left;i<=right;i++)
            {
                ans.push_back(matrix[top][i]);//top is constant
            }
            top++;
            // from top to bottom
            for(int i=top;i<=bottom;i++)
            {
                ans.push_back(matrix[i][right]);// right col remains constant 
            }
            right--;
            //from right to left
            if(top<=bottom)
            {
            for(int i=right;i>= left;i--)
            {
                ans.push_back(matrix[bottom][i]); //bottom col constant
            }
                        bottom--;
            }


            if(left<=right)
            {
            // from bottom to top
            for(int i=bottom;i>=top;i--)
            {
                ans.push_back(matrix[i][left]);
            }
                  left++;
            }
      
        }
        return ans;
    }
};
