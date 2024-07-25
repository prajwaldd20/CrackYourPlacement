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
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow= head;
        ListNode* fast = head->next;
        while(fast !=NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeTwo(ListNode* left, ListNode* right)
{
    ListNode* dummy= new ListNode(-1);
    ListNode* temp = dummy;
    while(left!= NULL && right!=NULL)
    {
        if(left->val <= right->val)
        {
            temp->next = left;
            temp=left;
            left = left->next;
            
        }
        else 
        {
            temp->next =right;
            temp =right;
            right= right->next;
        }
  
    }
      if(left)
    {
        temp->next = left;
    }
    else if(right)
    {
        temp->next = right;
    }
    return dummy->next;
}
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next ==NULL)
        {
            return head;
        }
        ListNode* middle =findMiddle(head);
        ListNode* leftHead= head;
        ListNode* rightHead= middle->next;
        middle->next =NULL;
        leftHead= sortList(leftHead);
        rightHead= sortList(rightHead);
        return mergeTwo(leftHead, rightHead);
    }
};
