   void  solve(Node* node, int low, int high, bool &flag)
    {
      
        if(node->left ==  NULL && node->right == NULL)
        {
            if((node->data - low) - 1 == 0 )
            {
                if( (high -node->data) -1 == 0 )
                {
                flag =true;
                return ;
                }
            }
            return;
        }
        
        if(node->left) solve(node->left, low, node->data, flag);
        if(node->right) solve(node->right , node->data , high, flag);
        
      
    }
    bool isDeadEnd(Node *root)
    {
        //Your code here
        bool flag;
         solve(root, 0, INT_MAX, flag);
         return flag;
    }
