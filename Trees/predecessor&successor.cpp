//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    private:
    
    Node* findPre(Node* root, int key)
    {
        if(root == NULL) return NULL;
       
        Node* ans = NULL;
        // find largest
       while(root)
       {
           if(root->key < key )
           {
               ans = root;
               root =root->right;
           }
           else
           {
               root =root->left;
           }
       }
       
       return ans;
    }
    
     Node* findSuc(Node* root, int key)
    {
        if(root == NULL) return NULL;
      
        Node* ans = NULL;
        //find smallest
        
        while(root)
        {
            if(root->key> key)
           {
               ans = root;
               root =root->left; // find more smaller
           }
           else
           {
               root=root->right;
           }
        }
        return ans;
    }
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        
        pre = NULL; suc = NULL;
        
        if(root == NULL ) return;
        // predecessor - largest in the left subtree
        
        pre  = findPre(root, key);
        suc = findSuc(root, key);
        
        return ;
    }
};

