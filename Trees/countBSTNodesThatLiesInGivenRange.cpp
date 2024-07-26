
//Function to count number of nodes in BST that lie in the given range.
class Solution{
    
    void solve(Node* root, int l, int h, int &count)
    {
        if(root == NULL)
        return;
        
        if( root->data >= l && root->data<= h)
        {
            count++;
        }
        
        solve(root->left, l, h, count);
        solve(root->right, l, h, count);
    }
public:
    int getCount(Node *root, int l, int h)
    {
      // your code goes here  
      int count= 0;
      solve(root, l, h, count);
      return count;
    }
};


