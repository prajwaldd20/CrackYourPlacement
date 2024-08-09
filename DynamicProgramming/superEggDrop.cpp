class Solution {



    int solve(int e, int f,  vector<vector<int>> &t)
    {
        if( f == 0 || f ==1) return f;

        if(e ==1 ) return f;

        if(t[e][f] != -1) return t[e][f];

        int mini = INT_MAX;
        int start= 1, end= f;
        while( start <= end )
        {
            int k = (start + end) / 2 ;
            int temp, low, high ;

            if( t[e-1][k-1] != -1)
            {
                low = t[e-1][k-1];
            }
            else
            {
                low = solve(e-1, k-1, t);
                t[e-1][k-1]  = low;
            }

            if( t[e][f-k] != -1)
            {
                high = t[e][f-k];
            }
            else
            {
                high = solve(e, f-k, t);
                t[e][f-k] = high;
            }


            temp = 1 + max(low, high);

            if(low < high) start =k+1;
            else end = k-1;

            mini = min(mini, temp);
        }

        return  t[e][f] =  mini;
    }
public:
    int superEggDrop(int k, int n) {
        // k -> no of eggs
        // n -> no of floors

        vector<vector<int>> t(k+1, vector<int>(n+1, -1));

        return solve(k,n, t);
    }
};
