class Solution {
public:
    bool hasCycle(ListNode *head) {
        /*
        map<ListNode* , bool> visited;
        ListNode* temp= head;
        while(temp != NULL)
        {
            if(visited[temp]== true)
            {
                return 1;
            }
            visited[temp]= true;
            temp= temp->next;
        }
        return 0;
        */
       if(head==NULL)
       {
           return 0;
       }
       if(head->next == NULL)
       {
           return 0;
       }
       if(head->next == head)
       {
           return true;
       }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && slow!= NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                fast=fast->next;
            }
            slow= slow->next;
            // If at any position, slow an fast pointers meet, then the cyle exists in the   linked list
            if(slow == fast)
            {
                return 1;
            }
        }
        return 0;
    }
};
