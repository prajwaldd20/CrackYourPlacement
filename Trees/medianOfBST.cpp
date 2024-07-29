void inorder( struct Node* root, vector<int> &in)
{
    if(root == NULL ) return;
    
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

float findMedian(struct Node *root)
{
      //Code here
      vector<int> in;
      inorder(root, in);
      
      int n =in.size();
      
      if(n % 2 == 1) // odd 
      {
          return in[n/2] * 1.0; // convert to float;
      }
      
       int a = in[n/2];
       int b = in[n/2 -1 ];
       
       return ( (a+b) / 2.0 ) * 1.0; 
}
