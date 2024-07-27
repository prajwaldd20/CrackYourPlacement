 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n);

        stack<int> st;

        for(int i =0;i<n;i++)
        {
            int num = nums1[i];
            int j= m-1;
            while(nums2[j] != num)
            {
                if(nums2[j] > num)
                {
                st.push(nums2[j]);
                }
                j--;
            }

            if(st.empty()) ans[i] = -1;
            else
            {
                ans[i] = st.top();
                st.pop();
                
            }
        while(!st.empty()) st.pop();
        }

        return ans;
    }
