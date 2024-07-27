class Solution {
public:
int n, m;
        void dfs(vector<vector<int>>& image, int i, int j, int color, int d)
        {
        if( i>=n || i<0 || j>=m || j<0 || (image[i][j] != color && image[i][j] !=d))
        {
            return;
        }

        if(image[i][j] == color)
        {
            return;
        }

        if(image[i][j] == d)
        {
            image[i][j] = color;
        }

        dfs(image, i-1, j,color, d);
        dfs(image, i+1, j,color, d);
        dfs(image, i, j-1,color, d);
        dfs(image, i, j+1,color, d);

        return;
        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        n = image.size();
        m = image[0].size();
        int d= image[sr][sc]; // color of given element

        dfs(image, sr, sc,color, d);

        return image;
    }
};
