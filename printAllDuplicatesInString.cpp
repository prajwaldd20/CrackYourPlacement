class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    string ans="";
	  unordered_set<char> st;
	  for(auto ch: str)
	  {
	      st.insert(ch);
	  }
	  
	  for(auto ch:str)
	  {
	      if(st.find(ch) != st.end())
	      {
	          ans += ch;
	          st.erase(ch);
	      }
	  }
	    
	    return ans;
	}
};
