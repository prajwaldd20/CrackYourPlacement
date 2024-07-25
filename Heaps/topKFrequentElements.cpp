class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //store value and frequency in map
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        // lambda function in c++
        // & means pass by reference 
        // basically used to create heap according to the frequency 
        // of the element 
        auto comp = [&mp](int a, int b) { return mp[a] > mp[b];};

        // heap using customize function
        priority_queue<int , vector<int>, decltype(comp)> hp(comp);

        for(auto [key, val]: mp)
        {
            hp.push(key);

            if(hp.size() > k) hp.pop();
        }

        vector<int> ans(k);
        for(int i= 0;i<k;i++)
        {
            ans[i] = hp.top();
            hp.pop();
        }

        return ans;
    }
};
