class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n= temperatures.size();
        vector<int> ans(n);

        stack<int> st;

        st.push(0);

        for(int i=1;i<n;i++)
        {
           
           
            while ( !st.empty() && temperatures[st.top()] < temperatures[i] )
            {
                 int idx = st.top(); 
                 st.pop();
                 ans[idx] = i - idx;
            }
            st.push(i);
        }
        return ans;
    }
};
