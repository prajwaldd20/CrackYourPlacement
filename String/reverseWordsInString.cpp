class Solution {
public:
    string reverseWords(string s) {
        

        int i = s.length()-1;
        string ans = "";
        while(i>=0)
        {
            if( (s[i] <='z' && s[i]>='a') || (s[i]<='Z' && s[i]>='A'))
            {
                int prev = i;
                while(s[i]!= ' ')
                {
                    i--;
                }
                for(int k =i;k<=prev;k++)
                {
                    ans += s[k];
                }
                ans +=' ';
                i--;

            }
            else
            {
                i--;
            }
        }

        ans.pop_back();
        return ans;
    }
};
