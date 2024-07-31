
// pair<distance, pair<x_cor, y_cor>> 
#define P pair<double,pair<int,int>> 
class Solution {
public:


    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        if(k ==0 )return {};
        // min heap to store the points with minimum distance
        priority_queue<P, vector<P> , greater<P> > pq;
        int n=points.size();
       for(int i=0;i<n;i++)
       {
            int x= points[i][0];
            int y =points[i][1];

            double dist = sqrt( x*x + y * y );

            pq.push({dist , {x, y}});
       }

       vector<vector<int>> result;

       while(k--)
       {
        int x =pq.top().second.first;
        int y = pq.top().second.second;
        
        vector<int> temp(2);
        temp[0] =x; temp[1] = y;
        
        result.push_back(temp);

        pq.pop();


       }

       return result;
    }
};
