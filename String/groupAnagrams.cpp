class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() == 0) return {};

        unordered_map<string, vector<string>> mp;

        for(auto s: strs)
        {
            string word = s;

            sort(word.begin(), word.end());

            mp[word].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto [word, vec] : mp)
        {
            ans.push_back(vec);
        }

        return ans;

    }
};
