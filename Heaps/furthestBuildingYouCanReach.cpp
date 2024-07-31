class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // to keep track of the gaps
        priority_queue<int, vector<int> , greater<int>> pq;
        int ans = 0;
        int n= heights.size();
        for(int i=0;i<n-1;i++)
        {
            // if next is less than curr
            // then go to next

            if(heights[i+1]<= heights[i])
            {
                ans++;
            }
            else
            {
                int gap = heights[i+1] - heights[i];
                pq.push(gap); // means we used ladder for 
                    // the current gap

                // if ladders are not avaiable
                if(pq.size() > ladders)
                {
                    // use bricks
                    bricks = bricks - pq.top();
                    pq.pop();


                    if(bricks< 0)
                    {
                        break;
                    }
                }
                ans++;
            }

        }

        return ans;
    }
};
