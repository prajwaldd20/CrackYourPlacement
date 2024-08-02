
// User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        
        if(head == NULL || head->next == NULL )
        return head;
        
        
        // Node* dummy = new Node(-1);
        // dummy->next = head;
        Node* oddTail = NULL;
        Node* evenHead = NULL;
        Node* evenTail = NULL;
        Node* oddHead= NULL;
        
        Node* curr = head;
        
        while(curr != NULL)
        {
            if(curr->data % 2 == 0) // even  node
            {
               if(evenHead == NULL)
               {
                   evenHead = curr;
                   evenTail = curr;
               }
               else
               {
                   evenTail->next = curr;
                   evenTail = curr;
               }
            }
            else
            {
               if(oddHead == NULL)
               {
                oddHead = curr;
                oddTail = curr;
               }
               else
               {
                   oddTail->next = curr;
                   oddTail = curr;
               }
            }
            
            curr = curr->next;
        }
        
        oddTail->next = NULL;
        evenTail->next = oddHead;
        
        
        
        return evenHead;
    }
};

