class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans="";
        int n=path.length();
        int i=0;

        while(i < n)
        {
            
            string temp ="";

            while(path[i] == '/')
                i++;

            while(i < n && path[i] != '/')
            {
                temp += path[i];
                i++;
            }

            if(temp.compare("..") == 0)
            {
                if(!st.empty())
                st.pop();
            }
            else if(temp.compare(".") == 0)
            {
                i++;
                continue;
            }
            else if(temp.length() != 0)
            {
                st.push(temp);
    
            }



        
        }
        stack<string> st2;
        while(!st.empty())
        {
             st2.push(st.top());
            st.pop();
        }

        // st2 contains the answer
        ans.append("/");
        while(!st2.empty())
        {
            string temp = st2.top();

            if( st2.size() != 1 ) // not a last directory
            {
                ans.append(temp+"/");
            }
            else
            {
                ans.append(temp);
            }

            st2.pop();
        }

        return ans;
    }
};
