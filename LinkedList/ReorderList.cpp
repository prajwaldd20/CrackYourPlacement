/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverseLL(ListNode* head)
    {
        if(head == NULL || head->next ==  NULL)
        {
            return head;
        }

         ListNode* Node2= reverseLL(head->next);
       head->next->next  = head;
       head->next = NULL;
       return Node2;
    }
public:
    void reorderList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return ;
        

        // find middle node using slow and fast
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow=  slow->next;
            fast = fast->next->next;
        }

        // reverse next half of LL
        ListNode* rev = reverseLL(slow);

        // change links
        ListNode* curr =head;
        while(rev->next != NULL)
        {
            ListNode* tempCurr = curr->next;
            curr->next = rev;

            ListNode* tempRev = rev->next;
            rev->next = tempCurr;

            curr =tempCurr;
            rev = tempRev;
        }




    }
};
