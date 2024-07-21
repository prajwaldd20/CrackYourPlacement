class Solution {
public:
    string addBinary(string a, string b) {
        char carry='0';
        int n1=a.length(), n2=b.length();
        int m=max(n1,n2);
        string ans="";
        int i=n1-1, j=n2-1;
        while( i>=0 || j>=0)
        {
            char ch1 = i>=0 ? a[i]:'0';
            char ch2 = j>=0 ? b[j]:'0';
            char temp;
            if(ch1 == '0' && ch2=='0')
            {
                temp = carry;
                carry ='0';
            }
            else if((ch1 == '0' && ch2=='1') || (ch1=='1' && ch2=='0'))
            {
                temp = carry=='1'?'0':'1';
                carry= temp=='0'?'1': '0';
            }
            else // both 1
            {
                temp = carry=='0'? '0':'1';
                carry = '1';
            }
            ans += temp;
            i--;j--;
        }
        if(carry== '1')
        ans += carry;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
