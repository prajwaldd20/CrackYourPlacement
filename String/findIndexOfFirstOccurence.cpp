class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m=needle.length();
        int i =0, j=0;
        while( i<n && j<m)
        {
            if(haystack[i] == needle[j])
            {
                j++;
            }
            else
            {
                i = i-j;
                j=0;
            }
            i++;
        }
        if(j == m)
        {
            return i - m;;
        }
        
   
            return -1;
  
        
    }
};
