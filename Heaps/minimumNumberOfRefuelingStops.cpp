class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int currFuel = startFuel;
        int i=0;
        int n=stations.size();
        int ans=0;
        // to store the max dist that can be travelled
        priority_queue<int> pq;

        while(currFuel < target)
        {
            // while we have enough fuel
            // just go forward
            // but store the max amount of fuel 
            // in the max heap
            while(i < n && currFuel >= stations[i][0] )
            {
                pq.push(stations[i][1]);
                i++;
            }

            if(pq.empty()) return -1;

            currFuel += pq.top();
            pq.pop();
            ans++;

        }

        return ans;

    }
};
