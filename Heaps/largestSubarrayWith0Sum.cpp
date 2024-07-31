    int maxLen(vector<int>& arr, int n) {
        // Your code here
        
        // store prefSum and index next to it
        unordered_map<int, int> mp;
        int prefSum = 0;
        int ans=0;
        mp[0] = 0;
        for(int i=0;i<n;i++)
        {
            prefSum += arr[i];
            
            // if prefSum is already present        
            if(mp.count(prefSum) != 0)
            {
                int index = i - mp[prefSum]+1;
                ans = max(ans, index);
            }
            else
            {
                mp[prefSum] = i+1;
            }
        }
       
       
       return ans;
        
        
        
    }
