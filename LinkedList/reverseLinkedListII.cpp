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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head == NULL || head->next == NULL )
            return head; 

        // create dummy node to handle edge cases

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        // create pointers 
        ListNode* prevNode = dummy;
        ListNode* curr = head;

        // reach upto that node
        for(int i=0;i < left-1;i++)
        {
            prevNode = prevNode->next;
            curr =curr->next;
        }


        // keep the head of sublist
         ListNode* subHead = curr;


        // reverse the nodes
        // run loop right-left+1 times

        ListNode* prev = NULL; // used to reverse linked list
       
        
        for(int i=0;i<=right - left ; i++)
        {
            ListNode* forward  = curr->next;
            curr->next = prev;
            prev = curr;
            curr= forward;
        }

        // curr will contain the ( last + 1 )th node

        prevNode->next = prev;
        subHead->next = curr;
        return dummy->next;
    }
};
