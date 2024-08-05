

// User function template in C++

/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution {
     int findPos(vector<int> in, int start, int end, int val)
    {
     
     for(int i=start;i<=end;i++)
     {
         if(val == in[i]) 
     {
         return i;
     }
     }
     return -1;
    }
    Node* solve(vector<int> in, int pre[], int n, int inStart, int inEnd, int &index )
    {
        if( index>= n || inStart > inEnd )
        {
            return NULL;
        }
        int element = pre[index++];
        int posIndex = findPos( in,inStart, inEnd, element );
        
        if(posIndex == -1) return NULL;
        
        Node* root = newNode(element);
        
        root->left= solve(in, pre, n, inStart, posIndex-1, index);
        root->right = solve(in, pre, n, posIndex+1, inEnd, index);
        
        return root;
    }
  public:
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        // code here
        
         vector<int> in(pre, pre+size);
         
      
         sort(in.begin(), in.end());
         
         int index=0;
         Node* ans = solve(in, pre, size, 0, size-1, index);
         return ans;
    }
};

