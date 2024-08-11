class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        // Yi + Yj + | Xi - Xj | 
        // since Xi < Xj always -> Xi - Xj will be negative
        // Yi+Yj+Xj-Xi
        // ( Yi - Xi ) + (Xj + Yj)


        priority_queue<pair<int, int>> pq;
        // < Yi - Xi , Xi>

        int ans = INT_MIN;
        for( int i=0;i< points.size();i++ )
        {
            while( !pq.empty()  &&  ( points[i][0] - pq.top().second  ) >k )
            {
                pq.pop();
            }

            if( !pq.empty())
            {
                ans =max(ans, pq.top().first + points[i][1] + points[i][0] );
            
            }
 
            pq.push( { points[i][1] - points[i][0] , points[i][0]} ); // yi - xi, xi
        }

        return ans;
    }
};
