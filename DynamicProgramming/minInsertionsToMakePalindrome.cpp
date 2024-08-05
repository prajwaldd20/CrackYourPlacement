class Solution {
    int LCS(string &s1,string &s2, int n , int m)
    {
        vector<vector<int>> t(n+1, vector<int> (m+1, 0));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else
                {
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
                }
            }
        }

        return t[n][m];
    }
public:
    int minInsertions(string s) {
        
        string rev = "";
        int n=s.length();
        for(int i =n-1;i>=0;i-- )
        {
            rev  += s[i];
        }

        int lcs = LCS(s, rev, n, n);
        // cout<<lcs<<" ";
        return n -lcs;
    }
};
