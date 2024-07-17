class Solution {
    private:
    ListNode* reverse2(ListNode* head)
    {
        if(head == NULL || head->next ==  NULL)
        {
            return head;
        }

         ListNode* Node2= reverse2(head->next);
       head->next->next  = head;
       head->next = NULL;
       return Node2;
    }
    void reverse(ListNode* &head, ListNode* curr, ListNode* prev)
    {
        if(curr == NULL)
        {
            head= prev;
            return;
        }

        ListNode* forward = curr->next;
        reverse(head, forward, curr);
        curr->next = prev;

    }
public:
    ListNode* reverseList(ListNode* head) {
     /*   // if(head == NULL || head->next == NULL)
        // {
        //     return head;
        // }
        ListNode* prev= NULL;
        ListNode* curr = head;
        //   ListNode* forward= NULL;
        // while(curr != NULL)
        // {
        //     forward=curr->next;
        //     curr->next = prev;
        //     prev= curr;
        // curr = forward;
        // }
        // return prev;
        reverse(head, curr, prev);
        return head;
        */
        return (reverse2(head));
    }
};
