class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        while(i < s.length())
        {
           
           if(s[i]=='(' || s[i]=='{' || s[i]== '[')
           {
               st.push(s[i]);
               i++;
           }
           else
           {
               if(!st.empty())
               {
               if((st.top()=='(' && s[i]==')') ||
                ( st.top()=='[' && s[i]==']') ||
                 (st.top()=='{' && s[i]=='}'))
                 {
                     st.pop();
                     i++;
                 }
                 else
                 {
                     return false;
                 }
               }
               else
               {
                   return false;
               }
           }
       

        }
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
