class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n=gas.size(), index=0, totalDiff = 0, fuel=0;

        for(int i=0;i<n;i++)
        {
            int diff = gas[i] - cost[i];
            totalDiff += diff;
            fuel +=diff;
            if(fuel < 0)
            {
                fuel = 0;
                index= i+1;
            }
        }



        if(totalDiff < 0) return -1;

        return index;

    }
};
