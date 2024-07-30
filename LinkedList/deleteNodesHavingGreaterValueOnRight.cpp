
/*
The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* reverse(Node* head)
    {
        if(head == NULL || head->next ==  NULL)
        {
            return head;
        }

        Node* Node2= reverse(head->next);
       head->next->next  = head;
       head->next = NULL;
       return Node2;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        
        if(head->next == NULL || head== NULL) 
        return head;
        
        
        Node* revHead = reverse(head);
        
        
        int maxi = revHead->data;
        
        Node* prev =revHead;
        Node* curr = revHead->next;
        
        while(curr!= NULL)
        {
            if( curr->data < maxi )
            {
                // means there is greater element 
                // present on right side in actual linked list
                
                // so remove the element
                
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                // update the max value
                // update prev and curr pointers
                
                maxi = max(maxi, curr->data);
                
                prev = curr;
                curr= curr->next;
                
                
            }
        }
        
        
        return  reverse(revHead);
        
        
        
    }
    
};
   


