class Solution {
    void solve(int open, int close, string op, vector<string> &ans)
    {
        // base condition

        if( open == 0 && close == 0) 
        {
            ans.push_back(op);
            return;
        }


        if(open!= 0 )
        {
            string temp = op;

            temp.push_back('(');
            solve(open-1, close, temp, ans);
        }
        
        // condition when we get closed bracket
        if(close > open )
        {
            string temp = op;

            temp.push_back(')');
            solve(open, close-1, temp, ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        int open = n;
        int close = n;
        string op = "";
        solve(open, close,op,  ans);

        return ans;
    }
};
