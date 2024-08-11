class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> t(n+1);

        // dp array
        t[0] = 1;

        t[1] = s[0] == '0' ? 0 : 1;

        // the current answer depends upon last 2 elements

        for(int i=2;i<= n; i++)
        {
            int oneDigit = stoi(s.substr(i-1, 1));
            int twoDigit = stoi(s.substr(i-2,2));


            if( oneDigit >=1 )
            {
                t[i] += t[i-1];
            }

            if(twoDigit >=10 && twoDigit <= 26)
            {
                t[i] += t[i-2];
            }
        }

        return t[n];

    }
};
