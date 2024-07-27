class Solution {
public:
    int evalRPN(vector<string>& tokens) {


        stack<int> st;

        for(int i=0;i<tokens.size(); i++)
        {
            string ch = tokens[i];
            if( ch == "+" || ch=="-" || ch=="*" || ch=="/" )
            {
                int a= st.top();
                st.pop();
                int b =st.top();
                st.pop();
                int temp;
                if(ch == "+")
                    temp = b+a;
                else if(ch == "-")
                    temp = b-a;
                else if(ch == "*")
                    temp = b*a;
                else temp = b/a;

                st.push(temp);
            }
            else
            {
                st.push(stoi(ch));
            }
        }

        return st.top();
    }
};
