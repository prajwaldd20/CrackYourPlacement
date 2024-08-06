class Solution {
    int solve( vector<string> &s, int zeroes, int ones , int index,
    vector<vector<vector<int>>>&t
    )
    {


        // base condition

        if ( index== s.size() || zeroes + ones == 0)
        return 0;

        if(t[zeroes][ones][index] != -1)
        return t[zeroes][ones][index];
        // either include or not
        pair<int, int> p = getCount(s[index]);
         int zeroCount = p.first;
         int oneCount  =p.second;
        int include = 0;
         if( zeroes >= zeroCount  && ones >= oneCount)
         {
            include = 1 + solve(s, zeroes - zeroCount , ones - oneCount, index+1,t);
         }

         int exclude = solve(s, zeroes, ones, index+1,t);

         return t[zeroes][ones][index]= max(exclude, include);
    }

    pair<int, int> getCount( string &s )
    {
         int n =s.length();
         int zeroes = 0;
         for(int i=0;i<n;i++)
         {
            if(s[i] == '0') zeroes++;
         }

         int ones =n - zeroes;

         return {zeroes, ones};
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // m -> no of 0
        // n -> no of 1
          vector<vector<vector<int>>> t(m+1, vector<vector<int>>(n+1, vector<int>(strs.size(), -1)));
        return solve(strs, m, n, 0, t);
    }
};
