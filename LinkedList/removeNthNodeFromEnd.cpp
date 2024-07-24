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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL)
        {
            return NULL;
        }
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL)
        {
        len++;
        temp = temp->next;
        }
        int pos = len -n;
        if(pos == 0)
        {
            head= head->next;
            return head;
        }
        ListNode* prev =NULL;
        temp =head;
        while(pos--)
        {
            prev =temp;
            temp = temp->next;
        }
        ListNode* nextNode= temp->next;
        prev->next = nextNode;
        return head;  
    }
};
