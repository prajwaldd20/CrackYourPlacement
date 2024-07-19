
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        // Your code here
        // -4
       stack<int> st;
       for(int i=0;i<s.length();i++)
       {
           if( s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i]=='/' )
           {
               int a= st.top();
               st.pop();
               int b =st.top();
               st.pop();
               int ans=0;
               switch(s[i]){
                   case '+':ans = b+a;
                            break;
                   case '-':ans = b-a;
                            break;
                   case '*': ans = b*a;
                            break;
                   case '/':ans = b/a;
                             break;
                   
               }
               st.push(ans);
           }
           else
           {
               st.push(s[i] - '0');
           }
       }
       
       return st.top();
    } 
};

