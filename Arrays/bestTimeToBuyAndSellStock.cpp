class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        int maxProfit = 0;
        int cheap =prices[0];
        for(int i=0;i<n; i++)
        {
            if(prices[i] < cheap)
            {
                cheap = prices[i];
            }
            else if(prices[i]-cheap  > maxProfit)
            {
                maxProfit = prices[i]-cheap ;
            }

            
        }
        return maxProfit;
    }
};
