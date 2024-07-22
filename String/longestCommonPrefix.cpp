class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        sort(strs.begin(), strs.end());
        string startS = strs[0];
        string endS =strs[strs.size()-1];
        for(int i=0;i<min(startS.size(), endS.size()); i++)
        {
            if(startS[i] == endS[i])
            {
                ans += startS[i];
            }
            else
            {
                return ans;
            }
        }
        return ans;
    }
};
