class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        // max heap to store the max element in current window
        priority_queue<pair<int, int>> pq;
        int n=nums.size();
        int i=0, j=0;

        while(j < n)
        {
            // push the elements in the pq 
            // along with their index
            while( j-i < k  ) pq.push({nums[j], j++});

            while( !pq.empty() && j-pq.top().second > k  ) 
            pq.pop();

            ans.push_back(pq.top().first);
            i++;
        }

        return ans;
    }
};
