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
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* smaller= new ListNode(-1);
        ListNode* larger= new ListNode(-1);
        
        
        ListNode* curr1 = smaller;
        ListNode* firstHead = curr1;
        ListNode* curr2 = larger;
        ListNode* secondHead = curr2;
         ListNode* temp = head;

         while(temp != NULL)
         {
            if(temp->val < x)
            {
                curr1->next = new ListNode(temp->val);
                curr1 = curr1->next;
            }
            else
            {
                curr2->next = new ListNode(temp->val);
                curr2 = curr2->next;
            }

            temp = temp->next;

         }

         curr1->next = secondHead->next;

         return firstHead->next;


    }
};
