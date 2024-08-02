

class Solution {
  public:
    void rearrangeEvenOdd(Node *head) {
        // Your Code here
        if(head == NULL || head->next == NULL) return;
        
        
        int count = 1;
        
        Node* oddHead = NULL;
        Node* oddTail =NULL;
        Node* evenTail = NULL;
        Node* evenHead = NULL;
        
        Node* curr = head;
        
        
        while(curr != NULL)
        {
            if( count %2 == 0 ) // even position
            {
                if(evenHead == NULL )
                {
                    evenHead = curr;
                    evenTail =curr;
                }
                else
                {
                    evenTail->next = curr;
                    evenTail = curr;
                }
            }
            else // odd position node
            {
                if(oddHead == NULL)
                {
                    oddHead = curr;
                    oddTail =curr;
                }
                else
                {
                    oddTail->next = curr;
                    oddTail = curr;
                }
            }
            count++;
            curr = curr->next;
        }
        
        if(oddTail!= NULL)
        oddTail->next = evenHead;
        
        // terminate the even nodes
        if(evenTail != NULL)
        evenTail ->next = NULL;
        
        
        
         oddHead == NULL ? evenHead : oddHead;
    }
};

