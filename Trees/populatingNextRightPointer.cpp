/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL ) return NULL;

         queue<Node*> q;
         q.push(root);

         while(!q.empty())
         {
             int s= q.size();

             for(int i=0;i<s;i++)
             {
                Node* front = q.front(); 
                q.pop();
                if( i == s-1) front->next = NULL;
                else
                    front->next = q.front();  

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
             }
         }

         return root;
    }
};
