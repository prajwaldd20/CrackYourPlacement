struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    if(n ==0 )return NULL;
    
    stack<Node*> st;
    
    Node* root = new Node(pre[0]);
    
    st.push(root);
    
    for(int i=1;i<n;i++)
    {
         Node* t = st.top();
         st.pop();
         
         Node* newNode= new Node(pre[i]);
         
         if( t->left == NULL ) t->left = newNode;
         else if(t->right == NULL) t->right = newNode;
         
         if( t->left == NULL ||  t->right == NULL )
         st.push(t);
         
         if(preLN[i] == 'N') st.push(newNode);
    }
    
    return root;
    
}
