//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


// structure of trie node
struct TrieNode{
    //contains links for 26 alphabets
    TrieNode* child[26];

    // flag to mark the word end
    bool flag= false;

    //funtion to check presence of char
    bool contains(char ch)
    {
        if( child[ch-'a'] != NULL )
        {
            // character is present
            return true;
        }
        else
        {
            return false;
        }
    }

    //Function to put new node
    void put(char ch, TrieNode* node)
    {
        child[ch-'a'] = node;
    }

    // funtion to get link of char
    TrieNode* getNext(char ch)
    {
        return child[ch-'a'];
    }
    // set end to true
    void setEnd()
    {
            flag = true;
    }

    //function to check whether the node is end of word or not

    bool isEnd()
    {
        return flag;
    }
};

class Trie {

    TrieNode* root ;
public:
    Trie() {
        // initialize root node
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        int n= word.length();

        //create pointer to root node
        TrieNode* node = root;


        for(int i=0;i<n;i++)
        {
            char ch =word[i];
            if(node->contains(ch) == false) // char not present
            {
                // create new node
                TrieNode* newNode = new TrieNode();

                node->put(ch, newNode);
                
            }

            node = node->getNext(ch);

        }
        // after complete insertion
        // set flag as true
        node->setEnd();

    }
    
    bool search(string word) {
        
        TrieNode* node= root;
        for(int i=0;i<word.length();i++)
        {
            char ch = word[i];
            if( node->contains(ch) == false)
            return false;

            node = node->getNext(ch);
        }

        if(node->isEnd()) return true;
        else return false;



    }
    
    bool startsWith(string prefix) {
        TrieNode* node =root;

        for(int i= 0;i<prefix.length();i++)
        {
            char ch =prefix[i];

            if(node->contains(ch) == false)
            return false;

            node =node->getNext(ch);
        }

        if(node != NULL)
        {
            return true;
        }

        return false;
        
    }
    
    // function to get strings strating with prefix
   void addToAnswer( string &prefix, vector<string> &temp, TrieNode* curr)
   {
       if(curr->isEnd() == true)
       {
           temp.push_back(prefix);
       }
       
       
       for(char ch= 'a'; ch<= 'z';ch++)
       {
          
           if(curr->contains(ch) == true)
           {
               prefix.push_back(ch);
               addToAnswer(prefix , temp , curr->getNext(ch));
               prefix.pop_back();
           }
       }
   }
   
   
   
    vector<vector<string>> getStrings(string s)
    {
        
        // prev pointer to root
        TrieNode* prev = root;
        
        vector<vector<string>> ans;
        
        // initially prefix string is empty
        string prefix = "";
        
        // iterate through the string
        // in each iteration the character is added to the prefix
        for(int i =0;i<s.size(); i++)
        {
            char lastChar =s[i]; 
            prefix += lastChar;
            
            // curr node points to the last char of prefix
            TrieNode* curr = prev->getNext(lastChar);
            
            if(curr == NULL) // char not found 
            {
                break;
            }
            
            // if found
            vector<string>  temp ;
            
            //function to add all strings strting with prefix to the ans
            addToAnswer(prefix, temp, curr);
             
          
                 ans.push_back(temp);
                 temp.clear();
            
            prev =curr;
        }
        
        // if there is break from loop
        // that means the entire part of given string is not present  
        
        
        // so for remaining length of characters 
        // we push "0"
        
        int rem = s.size() - ans.size();
        for(int i=0;i<rem;i++)
        {
            ans.push_back({"0"});
        }
        
        return ans;
    }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie t;
        // insert the words in trie
        for(int i=0;i<n;i++)
        {
            t.insert(contact[i]);
        }
        
        // call the function to check the given string
        
       return  t.getStrings(s);
        
   
        
    }
};

