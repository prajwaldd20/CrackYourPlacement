//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string> >ans;
        unordered_map< string ,vector<string>> mp;
        
        for(auto s: string_list)
        {
            string str=s;
            sort(str.begin(), str.end());
            mp[str].push_back(s);
        }
        
        
        for(auto it : mp)
        {
            ans.push_back(it.second);
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
