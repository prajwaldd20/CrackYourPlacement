class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string ans = "";
        int n = columnNumber;
        while( n >= 1  )
        {
            int rem = (n-1)%26;
          
        
            ans += char(65+rem);
    
            n  = (n-1)  / 26;
        }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};
