//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
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

// create a trie first 
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
    

};
class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    bool helper(string &A, int index, Trie &obj)
    {
        int n= A.size();
        // check for each substr
        // starting from index upto len
        for(int len = 1; index+len <= n; len++ )
        {
            
            string str = A.substr(index,len);
            
            
            // if length reaches upto end of string 
            // and we found the word in trie
            // return true
            if( index + len == n && obj.search(str) )
            {
                return true;
            }
            
            // else if current string str is found in trie
            // move index to next index
            // next index will be index+len
            
             if(obj.search(str))
            {
                if( helper(A, index+len , obj) )
                    return true;
            }
        }
        
        return false;
        
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        
        //first insert all the words into the trie
        
        // instantiate the trie object
        Trie obj;
        
        int n= B.size();
        for(int i=0;i<n;i++)
        {
            string word = B[i];
            
            obj.insert(word);
            
        }
        
        // function to check whether the 
        // given string is present in trie or not
        
      return   helper(A,0,obj);
        
        
        
    }
};

